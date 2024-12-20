#pragma once

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
class sql_manager : public QObject
{
    Q_OBJECT

public:
    explicit sql_manager(QObject* parent ); // 使用 explicit 明确构造函数
    ~sql_manager() override;

    void Connect_Sql(); // 添加 Connect_Sql 函数声明
    QSqlQuery query;
    QString Test_output;
    QSqlDatabase db; // 如果需要在类中持有数据库连接，可以在这里声明
private:

    QString connectionName; // 用于存储连接名称
};