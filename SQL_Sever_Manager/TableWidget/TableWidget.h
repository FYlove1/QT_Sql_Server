// tablewidget.h
#pragma once

#include <QWidget>
#include <QTableView>
#include <QSqlQueryModel>
#include <QVBoxLayout>

class TableWidget : public QWidget {
    Q_OBJECT

public:
    // 构造函数
    explicit TableWidget(QSqlQueryModel *model, QWidget *parent = nullptr);

private:
    QTableView *tableView;
};