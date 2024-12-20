//
// Created by 缝缘 on 2024/12/17.
//
// You may need to build the project (run Qt uic code generator) to get "ui_Manager_widget.h" resolved
#include "manager_widget.h"
#include <QLineEdit>
#include <QMessageBox>
#include "ui_Manager_widget.h"
#include <qpushbutton.h>
#include <QSqlError>
#include "TableWidget/TableWidget.h"
#include "Dialogs/Customer_Information_Dialogs/customerinfodialog.h"


Manager_widget::Manager_widget(QWidget *parent) : QMainWindow(parent), ui(new Ui::Manager_widget),
                                                  sql_manager_for_test(this)
{
    ui->setupUi(this);

    sql_manager_for_test.Connect_Sql();
    ui->textEdit_for_debug->setText(sql_manager_for_test.Test_output);
    //用户信息 信号与槽区


    connect(ui->Do_Sql_Query, &QPushButton::clicked, this, &Manager_widget::when_pushButtonDoSqlQuery_clicked);
    connect(ui->New_User_Registration, &QPushButton::clicked, this, &Manager_widget::when_New_User_Registration_clicked);
    connect(ui->Retrieving_user_Information,&QPushButton::clicked, this, &Manager_widget::when_Retrieving_User_Information_clicked);
    connect(ui->All_Car_Information, &QPushButton::clicked, this, &Manager_widget::when_All_Car_Information_clicked);
    connect(ui->Available_Car_Information, &QPushButton::clicked, this, &Manager_widget::when_Available_Car_Information_clicked);
    connect(ui->Rent_the_car, &QPushButton::clicked, this, &Manager_widget::when_Rent_the_car_clicked);
    connect(ui->Return_the_car, &QPushButton::clicked, this, &Manager_widget::when_Return_the_car_clicked);
    when_All_Car_Information_clicked();
    when_Available_Car_Information_clicked();
}

Manager_widget::~Manager_widget() {
    delete ui;
}

///////sql 查询 通用函数 //////
void Manager_widget::Do_Sql_Query(const QString &sql_query_qstr) {
    QSqlQuery query(sql_manager_for_test.db);

    // 执行查询
    if (!query.exec(sql_query_qstr)) {
        // 查询失败，输出错误信息
        qDebug() << "Query failed:" << query.lastError().text();
        return;
    }

    // 如果是 SELECT 查询，创建模型并显示结果
    if (sql_query_qstr.startsWith("SELECT", Qt::CaseInsensitive)) {
        QSqlQueryModel *model = new QSqlQueryModel(this);
        model->setQuery(query);

        // 创建并显示 TableWidget
        TableWidget *widget = new TableWidget(model, nullptr);
        widget->show();
    } else {
        // 对于非 SELECT 查询（如 INSERT、UPDATE、DELETE），不需要显示表格
        qDebug() << "Query executed successfully.";
    }

}

//////执行sql查询//////// 测试//
void Manager_widget::when_pushButtonDoSqlQuery_clicked() {
    // 创建 QSqlQueryModel 实例
    QSqlQueryModel *model = new QSqlQueryModel(this);

    // 执行查询并将结果加载到模型中
    if(ui->textEdit_for_debug->toPlainText()=="") {
        ui->textEdit_for_debug->setText("SELECT * FROM dbo.Vehicle");
    }
    QString queryText = ui->textEdit_for_debug->toPlainText();
    model->setQuery(queryText, sql_manager_for_test.db);

    // 检查查询是否成功
    if (model->lastError().isValid()) {
        qDebug() << "Query failed:" << model->lastError().text();
        return;
    }
    // 将模型绑定到 QTableView
  //  ui->tableView->setModel(model);
    // 调整表格列宽以适应内容（可选）
  //  ui->tableView->resizeColumnsToContents();
    Do_Sql_Query(queryText);
}



////////////////////////////用户 信息 相关 槽函数////////////////////
//查询用户信息
void Manager_widget::when_Retrieving_User_Information_clicked() {

     // 创建并显示客户信息对话框，用于输入姓名和电话号码
    CustomerInfoDialog queryDialog(this);

    // 设置对话框为只读模式（可选），仅允许输入姓名和电话号码
    queryDialog.firstNameLineEdit->setReadOnly(false);
    queryDialog.lastNameLineEdit->setReadOnly(false);
    queryDialog.phoneNumberLineEdit->setReadOnly(false);

    // 禁用其他输入控件，特别是 CustomerID
    queryDialog.customerIDLineEdit->setReadOnly(true);
    queryDialog.emailLineEdit->setReadOnly(true);
    queryDialog.addressLineEdit->setReadOnly(true);
    queryDialog.driverLicenseLineEdit->setReadOnly(true);
    queryDialog.membershipLevelComboBox->setEnabled(false);

    // 如果用户点击了“确定”，则获取输入的信息
    if (queryDialog.exec() == QDialog::Accepted) {
        // 获取用户输入的姓名和电话号码
        QString firstName = queryDialog.firstNameLineEdit->text();
        QString lastName = queryDialog.lastNameLineEdit->text();
        QString phoneNumber = queryDialog.phoneNumberLineEdit->text();

        // 构建查询语句，只使用 FirstName, LastName 和 PhoneNumber
        QString customerQueryText = "SELECT * FROM Customer WHERE FirstName = :firstName AND LastName = :lastName AND PhoneNumber = :phoneNumber";

        // 创建 QSqlQueryModel 实例用于客户信息
        QSqlQueryModel *customerModel = new QSqlQueryModel(this);

        // 使用绑定参数的方式构建查询
        QSqlQuery customerQuery(sql_manager_for_test.db);
        customerQuery.prepare(customerQueryText);
        customerQuery.bindValue(":firstName", firstName);
        customerQuery.bindValue(":lastName", lastName);
        customerQuery.bindValue(":phoneNumber", phoneNumber);

        // 执行查询并将结果加载到模型中
        if (!customerQuery.exec()) {
            qDebug() << "Customer query failed:" << customerQuery.lastError().text();
            QMessageBox::warning(this, "失败", "查询客户信息失败，请检查输入信息！");
            delete customerModel;  // 清理资源
            return;
        }

        // 将查询结果加载到模型中
        customerModel->setQuery(customerQuery);

        // 检查查询结果是否为空
        if (customerModel->rowCount() == 0) {
            // 如果没有找到匹配的客户，提示用户
            QMessageBox::information(this, "未找到", "未找到与输入信息匹配的客户。");
            delete customerModel;  // 清理资源
            return;
        }

        // 设置客户信息表头名称（可选）
        customerModel->setHeaderData(0, Qt::Horizontal, tr("客户ID"));
        customerModel->setHeaderData(1, Qt::Horizontal, tr("姓"));
        customerModel->setHeaderData(2, Qt::Horizontal, tr("名"));
        customerModel->setHeaderData(3, Qt::Horizontal, tr("电子邮件"));
        customerModel->setHeaderData(4, Qt::Horizontal, tr("电话号码"));
        customerModel->setHeaderData(5, Qt::Horizontal, tr("地址"));
        customerModel->setHeaderData(6, Qt::Horizontal, tr("驾驶证号"));
        customerModel->setHeaderData(7, Qt::Horizontal, tr("会员等级"));

        // 将客户信息模型设置为 QTableView 的模型
        ui->Current_User_Information->setModel(customerModel);
        ui->Current_User_Information->resizeColumnsToContents();  // 自动调整列宽

        // 显示成功消息
        QMessageBox::information(this, "成功", "已找到匹配的客户信息。");

        // 提取客户 ID
        int customerID = customerModel->data(customerModel->index(0, 0)).toInt();  // 假设客户ID是第一列

        // 查询 Rental 表中 ActualReturnDate 为 NULL 的记录
        QSqlQueryModel *rentalModel = new QSqlQueryModel(this);
        QString rentalQueryText = "SELECT * FROM dbo.RentalRecord WHERE CustomerID = :customerID AND ActualReturnDate IS NULL";

        // 使用绑定参数的方式构建查询
        QSqlQuery rentalQuery(sql_manager_for_test.db);
        rentalQuery.prepare(rentalQueryText);
        rentalQuery.bindValue(":customerID", customerID);

        // 执行查询并将结果加载到模型中
        if (!rentalQuery.exec()) {
            qDebug() << "Rental query failed:" << rentalQuery.lastError().text();
            QMessageBox::warning(this, "失败", "查询租赁记录失败，请检查数据库连接！");
            delete rentalModel;  // 清理资源
            return;
        }

        // 将查询结果加载到模型中
        rentalModel->setQuery(rentalQuery);

        // 检查查询结果是否为空
        if (rentalModel->rowCount() == 0) {
            // 如果没有找到未归还的租赁记录，提示用户
            QMessageBox::information(this, "未找到", "该客户没有未归还的租赁记录。");
            delete rentalModel;  // 清理资源
            return;
        }

        // 设置租赁记录表头名称（可选）
        rentalModel->setHeaderData(0, Qt::Horizontal, tr("租赁ID"));
        rentalModel->setHeaderData(1, Qt::Horizontal, tr("客户ID"));
        rentalModel->setHeaderData(2, Qt::Horizontal, tr("车辆ID"));
        rentalModel->setHeaderData(3, Qt::Horizontal, tr("租赁日期"));
        rentalModel->setHeaderData(4, Qt::Horizontal, tr("预计归还日期"));
        rentalModel->setHeaderData(5, Qt::Horizontal, tr("实际归还日期"));
        rentalModel->setHeaderData(6, Qt::Horizontal, tr("总费用"));

        // 将租赁记录模型设置为另一个 QTableView 的模型
        ui->Current_User_State->setModel(rentalModel);
        ui->Current_User_State->resizeColumnsToContents();  // 自动调整列宽

        // 显示成功消息
        QMessageBox::information(this, "成功", "已找到该客户的未归还租赁记录。");
    }


}
// 新建用户
void Manager_widget::when_New_User_Registration_clicked() {

      // 开始事务
    if (!sql_manager_for_test.db.transaction()) {
        qDebug() << "Failed to start transaction:" << sql_manager_for_test.db.lastError().text();
        QMessageBox::warning(this, "失败", "无法开始事务，请检查数据库配置！");
        return;
    }

    // 创建一个 QSqlQuery 对象来查询最后一个 CustomerID
    QSqlQuery lastIdQuery(sql_manager_for_test.db);
    if (!lastIdQuery.exec("SELECT ISNULL(MAX(CustomerID), 0) AS LastCustomerID FROM Customer;")) {
        qDebug() << "Failed to retrieve the last CustomerID:" << lastIdQuery.lastError().text();
        QMessageBox::warning(this, "失败", "无法获取最后一个客户ID，请检查数据库配置！");
        sql_manager_for_test.db.rollback();  // 回滚事务
        return;
    }

    // 检查查询结果
    if (!lastIdQuery.next()) {
        qDebug() << "No result returned from the last CustomerID query.";
        QMessageBox::warning(this, "失败", "无法获取最后一个客户ID，请检查数据库配置！");
        sql_manager_for_test.db.rollback();  // 回滚事务
        return;
    }

    // 获取最后一个 CustomerID 并加 1
    int lastCustomerID = lastIdQuery.value(0).toInt();
    int nextCustomerID = lastCustomerID + 1;

    // 格式化 CustomerID 为 "X (自动获取)"
    QString displayCustomerID = QString("%1 (自动获取)").arg(nextCustomerID);

    // 创建并显示客户信息对话框，传递格式化的 CustomerID
    CustomerInfoDialog dialog(this);
    dialog.customerIDLineEdit->setText(displayCustomerID);  // 确保这里调用的是正确的函数

    // 如果用户点击了“确定”，则获取输入的信息
    if (dialog.exec() == QDialog::Accepted) {
        // 获取用户输入的客户信息（不包括 CustomerID）
        CustomerInfo customerInfo = dialog.getCustomerInfo();

        // 构建插入语句（不包含 CustomerID，因为它是自增列）
        QSqlQuery insertQuery(sql_manager_for_test.db);
        insertQuery.prepare("INSERT INTO Customer (FirstName, LastName, Email, PhoneNumber, Address, DriverLicenseNumber, MembershipLevel) "
                            "VALUES (:firstName, :lastName, :email, :phoneNumber, :address, :driverLicenseNumber, :membershipLevel)");
        insertQuery.bindValue(":firstName", customerInfo.firstName);
        insertQuery.bindValue(":lastName", customerInfo.lastName);
        insertQuery.bindValue(":email", customerInfo.email);
        insertQuery.bindValue(":phoneNumber", customerInfo.phoneNumber);
        insertQuery.bindValue(":address", customerInfo.address);
        insertQuery.bindValue(":driverLicenseNumber", customerInfo.driverLicenseNumber);
        insertQuery.bindValue(":membershipLevel", customerInfo.membershipLevel);

        // 执行插入操作
        if (!insertQuery.exec()) {
            // 插入失败，提示用户
            qDebug() << "Insert Query failed:" << insertQuery.lastError().text();
            QMessageBox::warning(this, "失败", "无法插入新客户，请检查输入信息！");
            sql_manager_for_test.db.rollback();  // 回滚事务
            return;
        }

        // 提交事务
        if (!sql_manager_for_test.db.commit()) {
            qDebug() << "Failed to commit transaction:" << sql_manager_for_test.db.lastError().text();
            QMessageBox::warning(this, "失败", "无法提交事务，请检查数据库配置！");
            return;
        }

        // 获取最后插入的行ID（适用于 SQL Server）
        QSqlQuery lastInsertIdQuery(sql_manager_for_test.db);
        if (!lastInsertIdQuery.exec("SELECT @@IDENTITY AS LastInsertedID;")) {
            qDebug() << "Failed to retrieve the last inserted ID:" << lastInsertIdQuery.lastError().text();
            QMessageBox::warning(this, "失败", "无法获取新客户的ID，请检查数据库配置！");
            return;
        }

        if (lastInsertIdQuery.next()) {
            int lastInsertedID = lastInsertIdQuery.value(0).toInt();
            QMessageBox::information(this, "成功", QString("新客户已成功添加，客户ID为: %1").arg(lastInsertedID));
        } else {
            QMessageBox::warning(this, "失败", "无法获取新客户的ID，请检查数据库配置！");
        }
    } else {
        // 用户取消了对话框，回滚事务
        sql_manager_for_test.db.rollback();
    }
}
// 归还汽车
void Manager_widget::when_Return_the_car_clicked() {
    // 获取当前选中的租赁记录
    QModelIndexList selectedIndexes = ui->Current_User_State->selectionModel()->selectedRows();
    if (selectedIndexes.isEmpty()) {
        QMessageBox::warning(this, "警告", "请先选择一条租赁记录！");
        return;
    }

    // 获取选中的行索引
    QModelIndex selectedIndex = selectedIndexes.first();

    // 获取当前的模型
    QSqlQueryModel *currentModel = static_cast<QSqlQueryModel*>(ui->Current_User_State->model());

    // 从选中的行中提取 RentalID（假设租赁ID是第一列）
    int rentalID = currentModel->data(currentModel->index(selectedIndex.row(), 0)).toInt();

    // 从选中的行中提取 CustomerID（假设客户ID是第二列）
    int customerID = currentModel->data(currentModel->index(selectedIndex.row(), 1)).toInt();

    // 从日历组件中获取用户选择的日期
    QDate selectedDate = ui->calendarWidget->selectedDate();

    // 将 QDate 转换为 yyyy-MM-dd 格式的字符串
    QString dateString = selectedDate.toString("yyyy-MM-dd");

    // 构建更新语句，使用 ? 作为占位符
    QString updateQueryText = "UPDATE dbo.RentalRecord SET ActualReturnDate = ? WHERE RentalID = ?";

    // 使用绑定参数的方式构建查询
    QSqlQuery updateQuery(sql_manager_for_test.db);
    if (!updateQuery.prepare(updateQueryText)) {
        qDebug() << "Prepare failed:" << updateQuery.lastError().text();
        QMessageBox::warning(this, "失败", "准备更新语句失败，请检查数据库连接！");
        return;
    }

    // 按顺序绑定参数，使用字符串形式的日期
    updateQuery.addBindValue(dateString);  // 绑定日期字符串
    updateQuery.addBindValue(rentalID);

    // 执行更新操作
    if (!updateQuery.exec()) {
        qDebug() << "Update failed:" << updateQuery.lastError().text();
        qDebug() << "Driver error:" << updateQuery.driver()->lastError().text();
        QMessageBox::warning(this, "失败", "更新租赁记录失败，请检查数据库连接！");
        return;
    }

    // 提示用户更新成功
    QMessageBox::information(this, "成功", "租赁记录已成功更新！");

    // 重新查询未归还的租赁记录
    QString rentalQueryText = "SELECT * FROM dbo.RentalRecord WHERE CustomerID = :customerID AND ActualReturnDate IS NULL";
    QSqlQuery rentalQuery(sql_manager_for_test.db);
    rentalQuery.prepare(rentalQueryText);
    rentalQuery.bindValue(":customerID", customerID);

    // 执行查询并将结果加载到模型中
    if (!rentalQuery.exec()) {
        qDebug() << "Rental query failed:" << rentalQuery.lastError().text();
        QMessageBox::warning(this, "失败", "查询租赁记录失败，请检查数据库连接！");
        return;
    }

    // 将查询结果加载到模型中
    currentModel->setQuery(rentalQuery);

    // 设置租赁记录表头名称（可选）
    currentModel->setHeaderData(0, Qt::Horizontal, tr("租赁ID"));
    currentModel->setHeaderData(1, Qt::Horizontal, tr("客户ID"));
    currentModel->setHeaderData(2, Qt::Horizontal, tr("车辆ID"));
    currentModel->setHeaderData(3, Qt::Horizontal, tr("租赁日期"));
    currentModel->setHeaderData(4, Qt::Horizontal, tr("预计归还日期"));
    currentModel->setHeaderData(5, Qt::Horizontal, tr("实际归还日期"));
    currentModel->setHeaderData(6, Qt::Horizontal, tr("总费用"));

    // 将租赁记录模型设置为 QTableView 的模型
    ui->Current_User_State->setModel(currentModel);
    ui->Current_User_State->resizeColumnsToContents();  // 自动调整列宽

    // 如果所有租赁记录都已归还，提示用户
    if (currentModel->rowCount() == 0) {
        QMessageBox::information(this, "全部归还", "该客户的租赁记录已全部归还。");
    }
}


/////////////////汽车  查询//////////////////////////

void Manager_widget::when_All_Car_Information_clicked() {
    // 创建 QSqlQueryModel 实例
    QSqlQueryModel *model = new QSqlQueryModel(this);

    // 构建 SQL 查询语句
    QString queryText = "SELECT VehicleID, Brand, Model, Year, LicensePlate, Color, Seats, Type, Status, RentalPricePerDay "
                        "FROM Vehicle "
                        ;

    // 执行查询并将结果加载到模型中
    model->setQuery(queryText, sql_manager_for_test.db);

    // 检查查询是否成功
    if (model->lastError().isValid()) {
        qDebug() << "Query failed:" << model->lastError().text();
        QMessageBox::critical(this, "查询失败", "无法执行查询：" + model->lastError().text());
        return;
    }

    // 将模型绑定到 QTableView

    ui->All_Car_Information_Table->setModel(model);

    // 调整表格列宽以适应内容（可选）
    ui->All_Car_Information_Table->resizeColumnsToContents();

    // 设置表头名称（如果需要）
    model->setHeaderData(0, Qt::Horizontal, tr("车辆ID"));
    model->setHeaderData(1, Qt::Horizontal, tr("品牌"));
    model->setHeaderData(2, Qt::Horizontal, tr("型号"));
    model->setHeaderData(3, Qt::Horizontal, tr("年份"));
    model->setHeaderData(4, Qt::Horizontal, tr("车牌号"));
    model->setHeaderData(5, Qt::Horizontal, tr("颜色"));
    model->setHeaderData(6, Qt::Horizontal, tr("座位数"));
    model->setHeaderData(7, Qt::Horizontal, tr("类型"));
    model->setHeaderData(8, Qt::Horizontal, tr("状态"));
    model->setHeaderData(9, Qt::Horizontal, tr("日租金"));

    // 可选：记录查询成功的日志
    qDebug() << "查询成功，显示已租用车辆列表。";
}

//查询可租用车辆
void Manager_widget::when_Available_Car_Information_clicked() {
    // 创建 QSqlQueryModel 实例
    QSqlQueryModel *model = new QSqlQueryModel(this);

    // 构建 SQL 查询语句，选择状态为 "Available" 的车辆
    QString queryText = "SELECT VehicleID, Brand, Model, Year, LicensePlate, Color, Seats, Type, Status, RentalPricePerDay "
                        "FROM Vehicle "
                        "WHERE Status = 'Available';";

    // 执行查询并将结果加载到模型中
    model->setQuery(queryText, sql_manager_for_test.db);

    // 检查查询是否成功
    if (model->lastError().isValid()) {
        qDebug() << "Query failed:" << model->lastError().text();
        QMessageBox::critical(this, "查询失败", "无法执行查询：" + model->lastError().text());
        return;
    }

    // 将模型绑定到 QTableView
    ui->Available_Car_Table->setModel(model);

    // 调整表格列宽以适应内容（可选）
    ui->Available_Car_Table->resizeColumnsToContents();

    // 设置表头名称（如果需要）
    model->setHeaderData(0, Qt::Horizontal, tr("车辆ID"));
    model->setHeaderData(1, Qt::Horizontal, tr("品牌"));
    model->setHeaderData(2, Qt::Horizontal, tr("型号"));
    model->setHeaderData(3, Qt::Horizontal, tr("年份"));
    model->setHeaderData(4, Qt::Horizontal, tr("车牌号"));
    model->setHeaderData(5, Qt::Horizontal, tr("颜色"));
    model->setHeaderData(6, Qt::Horizontal, tr("座位数"));
    model->setHeaderData(7, Qt::Horizontal, tr("类型"));
    model->setHeaderData(8, Qt::Horizontal, tr("状态"));
    model->setHeaderData(9, Qt::Horizontal, tr("日租金"));

    // 可选：记录查询成功的日志
    qDebug() << "查询成功，显示可用车辆列表。";
}

/// 选择车租赁
void Manager_widget::when_Rent_the_car_clicked() {
    // 确保客户信息已经被加载到 QTableView 中
    QSqlQueryModel *customerModel = static_cast<QSqlQueryModel*>(ui->Current_User_Information->model());
    if (!customerModel || customerModel->rowCount() == 0) {
        QMessageBox::information(this, "提示", "请先查询并选择客户信息！");
        return;
    }

    // 获取选中的客户行（假设用户只能选择一行）
    QItemSelectionModel *customerSelectionModel = ui->Current_User_Information->selectionModel();
    if (!customerSelectionModel->hasSelection()) {
        QMessageBox::information(this, "提示", "请选择一位客户！");
        return;
    }

    QModelIndexList selectedCustomerIndexes = customerSelectionModel->selectedRows();
    if (selectedCustomerIndexes.isEmpty()) {
        qDebug() << "SelectedCustomerIndexes is empty, returning...";
        return;
    }

    const QModelIndex &selectedCustomerRow = selectedCustomerIndexes.first();
    int customerID = customerModel->data(customerModel->index(selectedCustomerRow.row(), 0)).toInt();  // 假设 CustomerID 是第一列

    // 获取 QItemSelectionModel
    QItemSelectionModel *carSelectionModel = ui->Available_Car_Table->selectionModel();

    // 检查是否有行被选中
    if (!carSelectionModel->hasSelection()) {
        qDebug() << "No rows selected, showing message box...";
        QMessageBox::information(this, "提示", "请先选择一行数据！");
        return;
    }

    // 获取所有选中的行（假设用户只能选择一行）
    QModelIndexList selectedIndexes = carSelectionModel->selectedRows();

    // 如果有多个行被选中，只处理第一个选中的行
    if (selectedIndexes.isEmpty()) {
        qDebug() << "SelectedIndexes is empty, returning...";
        return;
    }

    const QModelIndex &selectedRow = selectedIndexes.first();
    int row = selectedRow.row();

    // 提取该行的数据
    QSqlQueryModel *carModel = static_cast<QSqlQueryModel*>(ui->Available_Car_Table->model());
    QStringList rowData;
    for (int col = 0; col < carModel->columnCount(); ++col) {
        rowData << carModel->data(carModel->index(row, col)).toString();
    }

    // 获取用户输入的租赁时长（月和日）
    QString monthText = ui->Month_lineEdit->text().trimmed();
    QString dayText = ui->Day_lineEdit->text().trimmed();

    // 检查输入是否为空
    if (monthText.isEmpty() || dayText.isEmpty()) {
        qDebug() << "Month or Day input is empty, showing message box...";
        QMessageBox::information(this, "提示", "请输入租赁时长！如果不需要月份或天数，请输入 0。");
        return;
    }

    // 检查输入是否为有效的整数
    bool isMonthValid = false;
    bool isDayValid = false;
    int months = monthText.toInt(&isMonthValid);
    int days = dayText.toInt(&isDayValid);

    if (!isMonthValid || !isDayValid) {
        qDebug() << "Invalid integer input, showing message box...";
        QMessageBox::information(this, "提示", "请输入有效的整数作为租赁时长！");
        return;
    }

    // 获取用户选择的开始日期
    QDate rentalDate = ui->calendarWidget->selectedDate();

    // 计算预计归还日期
    // 假设每个月按 30 天计算
    int totalDays = months * 30 + days;
    QDate returnDate = rentalDate.addDays(totalDays);

    // 打印调试信息
    qDebug() << "Selected Row Data:" << rowData;
    qDebug() << "Selected Duration: " << months << " months and " << days;

    // 构建确认消息
    QString message = QString("您选择了以下车辆：\n\n"
                              "车辆ID: %1\n"
                              "品牌: %2\n"
                              "型号: %3\n"
                              "年份: %4\n"
                              "车牌号: %5\n"
                              "颜色: %6\n"
                              "座位数: %7\n"
                              "类型: %8\n"
                              "状态: %9\n"
                              "日租金: %10\n\n"
                              "租赁时长为 %11 个月 %12 天。\n\n"
                              "是否确认？")
            .arg(rowData[0])  // 车辆ID
            .arg(rowData[1])  // 品牌
            .arg(rowData[2])  // 型号
            .arg(rowData[3])  // 年份
            .arg(rowData[4])  // 车牌号
            .arg(rowData[5])  // 颜色
            .arg(rowData[6])  // 座位数
            .arg(rowData[7])  // 类型
            .arg(rowData[8])  // 状态
            .arg(rowData[9])  // 日租金
            .arg(months)
            .arg(days);

    // 显示确认对话框
    QPointer<QMessageBox> msgBox = new QMessageBox(this);
    msgBox->setWindowTitle("确认租赁");
    msgBox->setText(message);
    msgBox->setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox->setDefaultButton(QMessageBox::Yes);

    // 显示对话框并等待用户选择
    int result = msgBox->exec();
    msgBox->raise();
    msgBox->activateWindow();

    // 检查用户的选择
    if (result == QMessageBox::Yes) {
        qDebug() << "租赁信息已确认，执行后续操作...";

        // 用户确认
        // 插入数据库
        // 使用从 Current_User_Information 中获取的 customerID
        double dailyRate = rowData[9].toDouble();
        double totalCost = dailyRate * totalDays;

        // 构建 SQL 插入语句
        QSqlQuery query(sql_manager_for_test.db);
        query.prepare("INSERT INTO RentalRecord (CustomerID, VehicleID, RentalDate, ReturnDate, ActualReturnDate, TotalCost) "
                      "VALUES (:customerID, :vehicleID, :rentalDate, :returnDate, NULL, :totalCost)");
        query.bindValue(":customerID", customerID);  // 使用从 Current_User_Information 中获取的 customerID
        query.bindValue(":vehicleID", rowData[0]);   // 车辆ID
        query.bindValue(":rentalDate", rentalDate.toString("yyyy-MM-dd"));
        query.bindValue(":returnDate", returnDate.toString("yyyy-MM-dd"));
        query.bindValue(":totalCost", totalCost);

        // 执行插入操作
        if (query.exec()) {
            qDebug() << "租赁信息已成功插入数据库，执行后续操作...";
            QMessageBox::information(this, "成功", "租赁信息已成功保存！");
        } else {
            qDebug() << "插入数据库失败：" << query.lastError().text();
            QMessageBox::critical(this, "失败", "无法插入租赁信息：" + query.lastError().text());
        }

    } else {
        qDebug() << "用户取消了租赁确认，返回...";
        // 用户点击“否”，返回，等待下一次点击按钮
        return;
    }

    // 释放资源
    delete msgBox;
}


