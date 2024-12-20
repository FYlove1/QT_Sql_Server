//
// Created by 缝缘 on 2024/12/17.
//

#ifndef MANAGER_WIDGET_H
#define MANAGER_WIDGET_H
#include <QMainWindow>
#include <QtSql>
#include "sql_manger_connect/sql_manger.h"
#include "Dialogs/Customer_Information_Dialogs/customerinfodialog.h"
#include "Dialogs/Rent_time_dialog/rented_confirm_and_time_set_dialog.h"
class TableWidget;
QT_BEGIN_NAMESPACE
namespace Ui { class Manager_widget; }
QT_END_NAMESPACE



class Manager_widget : public QMainWindow {
Q_OBJECT

public:
    explicit Manager_widget(QWidget *parent = nullptr);
    ~Manager_widget() override;
    void Do_Sql_Query(const QString &sql_query_qstr);

private:
    Ui::Manager_widget *ui;
    sql_manager sql_manager_for_test;

    TableWidget *table_widget;


private slots:
    void when_pushButtonDoSqlQuery_clicked();
    void when_Retrieving_User_Information_clicked();
    void when_New_User_Registration_clicked();
    void when_All_Car_Information_clicked();
    void when_Available_Car_Information_clicked();
    void when_Rent_the_car_clicked();
    void when_Return_the_car_clicked();
};


#endif //MANAGER_WIDGET_H
class Rented_Confirm_And_Time_Set_Dialog;