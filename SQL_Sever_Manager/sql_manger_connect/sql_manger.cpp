#include "sql_manger.h"
#include <QSqlError>
#include <QDebug>

// 构造函数
sql_manager::sql_manager(QObject* parent)
    : QObject(parent)
{
    // 初始化数据库连接
    // 设置自定义连接名称
    connectionName = "fylove_for_test";
    db = QSqlDatabase::addDatabase("QODBC", connectionName);
}


// 析构函数
sql_manager::~sql_manager()
{
    if (db.isOpen()) {
        db.close();
    }
    QSqlDatabase::removeDatabase(db.connectionName());
}

// 连接数据库的方法
// 连接数据库的方法
void sql_manager::Connect_Sql()
{
    //数据库配置
    db.setHostName("LAPTOP-FKO9AJUJ");         // 服务器名称
    db.setDatabaseName("fylove");       // 数据源名称
    db.setUserName("fylove");               // 用户名
    db.setPassword("123456");
   // db.setDatabaseName("DATA_BASE_CLASS_Homework");
    if (db.open()) {
        Test_output = "数据库连接成功";
        qDebug()<<Test_output;
    }
    else {
        Test_output = "数据库连接失败: " + db.lastError().text();
        qDebug()<<Test_output;
    }

}