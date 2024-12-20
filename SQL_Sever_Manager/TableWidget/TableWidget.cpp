// tablewidget.cpp
#include "tablewidget.h"
#include <QVBoxLayout>
#include <QTableView>
#include <QSqlQueryModel>

TableWidget::TableWidget(QSqlQueryModel *model, QWidget *parent)
    : QWidget(parent), tableView(new QTableView(this)) {

    // 设置布局
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(tableView);
    setLayout(layout);

    // 将模型绑定到 QTableView
    tableView->setModel(model);

    // 调整表格列宽以适应内容
    tableView->resizeColumnsToContents();

    // 设置窗口标题
    setWindowTitle("查询结果");
}