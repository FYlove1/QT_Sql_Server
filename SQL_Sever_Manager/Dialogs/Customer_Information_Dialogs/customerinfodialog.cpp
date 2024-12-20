#include "customerinfodialog.h"
#include <QVBoxLayout>
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QDialogButtonBox>
#include <QMessageBox>

CustomerInfoDialog::CustomerInfoDialog(QWidget *parent)
    : QDialog(parent), currentCustomerInfo({0, "", "", "", "", "", "", ""}) {
    // 设置对话框标题
    setWindowTitle("客户信息");

    // 创建表单布局
    QFormLayout *formLayout = new QFormLayout(this);

    // 添加 CustomerID 输入框
    customerIDLineEdit = new QLineEdit(this);
    formLayout->addRow(new QLabel("客户ID:"), customerIDLineEdit);

    // 添加 FirstName 输入框
    firstNameLineEdit = new QLineEdit(this);
    formLayout->addRow(new QLabel("名字:"), firstNameLineEdit);

    // 添加 LastName 输入框
    lastNameLineEdit = new QLineEdit(this);
    formLayout->addRow(new QLabel("姓氏:"), lastNameLineEdit);

    // 添加 Email 输入框
    emailLineEdit = new QLineEdit(this);
    formLayout->addRow(new QLabel("邮箱:"), emailLineEdit);

    // 添加 PhoneNumber 输入框
    phoneNumberLineEdit = new QLineEdit(this);
    formLayout->addRow(new QLabel("手机号:"), phoneNumberLineEdit);

    // 添加 Address 输入框
    addressLineEdit = new QLineEdit(this);
    formLayout->addRow(new QLabel("地址:"), addressLineEdit);

    // 添加 DriverLicenseNumber 输入框
    driverLicenseLineEdit = new QLineEdit(this);
    formLayout->addRow(new QLabel("驾驶证号码:"), driverLicenseLineEdit);

    // 添加 MembershipLevel 下拉框
    membershipLevelComboBox = new QComboBox(this);
    membershipLevelComboBox->addItem("None");
    membershipLevelComboBox->addItem("Silver");
    membershipLevelComboBox->addItem("Gold");
    membershipLevelComboBox->addItem("Platinum");
    formLayout->addRow(new QLabel("会员等级:"), membershipLevelComboBox);

    // 添加按钮
    QDialogButtonBox *buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this);
    connect(buttonBox, &QDialogButtonBox::accepted, this, &CustomerInfoDialog::onAccepted);
    connect(buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);
    formLayout->addWidget(buttonBox);

    // 设置对话框的默认大小
    resize(400, 300);
}

CustomerInfoDialog::~CustomerInfoDialog() {
    // 析构函数
}

CustomerInfo CustomerInfoDialog::getCustomerInfo() const {
    return currentCustomerInfo;
}

void CustomerInfoDialog::onAccepted() {
    // 获取用户输入的信息
    bool ok;
    int customerID = customerIDLineEdit->text().toInt(&ok);
    /*if (!ok || customerID <= 0) {
        QMessageBox::warning(this, "输入错误", "客户ID必须是有效的正整数！");
        return;
    }*/

    currentCustomerInfo.customerID = customerID;
    currentCustomerInfo.firstName = firstNameLineEdit->text().trimmed();
    currentCustomerInfo.lastName = lastNameLineEdit->text().trimmed();
    currentCustomerInfo.email = emailLineEdit->text().trimmed();
    currentCustomerInfo.phoneNumber = phoneNumberLineEdit->text().trimmed();
    currentCustomerInfo.address = addressLineEdit->text().trimmed();
    currentCustomerInfo.driverLicenseNumber = driverLicenseLineEdit->text().trimmed();
    currentCustomerInfo.membershipLevel = membershipLevelComboBox->currentText();
    if(customerIDLineEdit->text().isEmpty()) {

        if (currentCustomerInfo.firstName.isEmpty() || currentCustomerInfo.lastName.isEmpty() ||
         currentCustomerInfo.phoneNumber.isEmpty() ) {
            QMessageBox::warning(this, "输入错误", "请填写电话,姓和名字！");
            return;
        }
    }
    else {
        // 检查必填项是否为空
        if (currentCustomerInfo.firstName.isEmpty() || currentCustomerInfo.lastName.isEmpty() ||
            currentCustomerInfo.email.isEmpty() || currentCustomerInfo.phoneNumber.isEmpty() ||
            currentCustomerInfo.address.isEmpty() || currentCustomerInfo.driverLicenseNumber.isEmpty()) {
            QMessageBox::warning(this, "输入错误", "请填写所有必填项！");
            return;
            }
    }


    // 接受对话框
    accept();
}