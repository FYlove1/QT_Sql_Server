/********************************************************************************
** Form generated from reading UI file 'manager_widget.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANAGER_WIDGET_H
#define UI_MANAGER_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Manager_widget
{
public:
    QWidget *centralwidget;
    QTextEdit *textEdit_for_debug;
    QTabWidget *User_Leasing_Status;
    QWidget *tab_4;
    QTableWidget *All_User_Information_2;
    QWidget *tab;
    QTableView *All_Car_Information_Table;
    QWidget *tab_2;
    QTableView *Available_Car_Table;
    QPushButton *Rent_the_car;
    QLineEdit *Month_lineEdit;
    QLineEdit *Day_lineEdit;
    QLabel *label_2;
    QLabel *label_3;
    QWidget *tab_3;
    QPushButton *Return_the_car;
    QTableView *Current_User_State;
    QPushButton *Do_Sql_Query;
    QToolBox *toolBox;
    QWidget *page;
    QPushButton *New_User_Registration;
    QPushButton *Retrieving_user_Information;
    QPushButton *All_User_Information;
    QWidget *car;
    QPushButton *All_Car_Information;
    QPushButton *Available_Car_Information;
    QCalendarWidget *calendarWidget;
    QLabel *label_4;
    QLabel *label;
    QTableView *Current_User_Information;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Manager_widget)
    {
        if (Manager_widget->objectName().isEmpty())
            Manager_widget->setObjectName("Manager_widget");
        Manager_widget->resize(852, 501);
        Manager_widget->setMinimumSize(QSize(0, 0));
        Manager_widget->setContextMenuPolicy(Qt::ContextMenuPolicy::NoContextMenu);
        centralwidget = new QWidget(Manager_widget);
        centralwidget->setObjectName("centralwidget");
        textEdit_for_debug = new QTextEdit(centralwidget);
        textEdit_for_debug->setObjectName("textEdit_for_debug");
        textEdit_for_debug->setGeometry(QRect(750, 460, 101, 20));
        User_Leasing_Status = new QTabWidget(centralwidget);
        User_Leasing_Status->setObjectName("User_Leasing_Status");
        User_Leasing_Status->setGeometry(QRect(330, 10, 511, 331));
        tab_4 = new QWidget();
        tab_4->setObjectName("tab_4");
        All_User_Information_2 = new QTableWidget(tab_4);
        All_User_Information_2->setObjectName("All_User_Information_2");
        All_User_Information_2->setGeometry(QRect(20, 20, 361, 261));
        User_Leasing_Status->addTab(tab_4, QString());
        tab = new QWidget();
        tab->setObjectName("tab");
        All_Car_Information_Table = new QTableView(tab);
        All_Car_Information_Table->setObjectName("All_Car_Information_Table");
        All_Car_Information_Table->setGeometry(QRect(10, 20, 431, 271));
        User_Leasing_Status->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        Available_Car_Table = new QTableView(tab_2);
        Available_Car_Table->setObjectName("Available_Car_Table");
        Available_Car_Table->setGeometry(QRect(20, 20, 361, 261));
        Rent_the_car = new QPushButton(tab_2);
        Rent_the_car->setObjectName("Rent_the_car");
        Rent_the_car->setGeometry(QRect(410, 240, 81, 41));
        Month_lineEdit = new QLineEdit(tab_2);
        Month_lineEdit->setObjectName("Month_lineEdit");
        Month_lineEdit->setGeometry(QRect(430, 150, 41, 20));
        Day_lineEdit = new QLineEdit(tab_2);
        Day_lineEdit->setObjectName("Day_lineEdit");
        Day_lineEdit->setGeometry(QRect(430, 200, 41, 20));
        label_2 = new QLabel(tab_2);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(390, 160, 21, 16));
        label_3 = new QLabel(tab_2);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(390, 200, 31, 16));
        User_Leasing_Status->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        Return_the_car = new QPushButton(tab_3);
        Return_the_car->setObjectName("Return_the_car");
        Return_the_car->setGeometry(QRect(400, 230, 91, 51));
        Current_User_State = new QTableView(tab_3);
        Current_User_State->setObjectName("Current_User_State");
        Current_User_State->setGeometry(QRect(40, 30, 321, 251));
        User_Leasing_Status->addTab(tab_3, QString());
        Do_Sql_Query = new QPushButton(centralwidget);
        Do_Sql_Query->setObjectName("Do_Sql_Query");
        Do_Sql_Query->setGeometry(QRect(750, 440, 91, 20));
        toolBox = new QToolBox(centralwidget);
        toolBox->setObjectName("toolBox");
        toolBox->setGeometry(QRect(10, 10, 291, 471));
        page = new QWidget();
        page->setObjectName("page");
        page->setGeometry(QRect(0, 0, 291, 413));
        New_User_Registration = new QPushButton(page);
        New_User_Registration->setObjectName("New_User_Registration");
        New_User_Registration->setGeometry(QRect(40, 10, 141, 51));
        Retrieving_user_Information = new QPushButton(page);
        Retrieving_user_Information->setObjectName("Retrieving_user_Information");
        Retrieving_user_Information->setGeometry(QRect(40, 80, 141, 51));
        All_User_Information = new QPushButton(page);
        All_User_Information->setObjectName("All_User_Information");
        All_User_Information->setGeometry(QRect(40, 150, 141, 51));
        toolBox->addItem(page, QString::fromUtf8("\347\224\250\346\210\267"));
        car = new QWidget();
        car->setObjectName("car");
        car->setGeometry(QRect(0, 0, 291, 413));
        All_Car_Information = new QPushButton(car);
        All_Car_Information->setObjectName("All_Car_Information");
        All_Car_Information->setGeometry(QRect(30, 0, 171, 71));
        Available_Car_Information = new QPushButton(car);
        Available_Car_Information->setObjectName("Available_Car_Information");
        Available_Car_Information->setGeometry(QRect(30, 70, 171, 71));
        calendarWidget = new QCalendarWidget(car);
        calendarWidget->setObjectName("calendarWidget");
        calendarWidget->setGeometry(QRect(10, 210, 251, 161));
        label_4 = new QLabel(car);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(20, 180, 101, 16));
        toolBox->addItem(car, QString::fromUtf8("\350\275\246\350\276\206"));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(340, 360, 111, 20));
        Current_User_Information = new QTableView(centralwidget);
        Current_User_Information->setObjectName("Current_User_Information");
        Current_User_Information->setGeometry(QRect(330, 390, 381, 81));
        Manager_widget->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(Manager_widget);
        statusbar->setObjectName("statusbar");
        Manager_widget->setStatusBar(statusbar);

        retranslateUi(Manager_widget);

        User_Leasing_Status->setCurrentIndex(3);
        toolBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Manager_widget);
    } // setupUi

    void retranslateUi(QMainWindow *Manager_widget)
    {
        Manager_widget->setWindowTitle(QCoreApplication::translate("Manager_widget", "Manager_widget", nullptr));
#if QT_CONFIG(accessibility)
        Manager_widget->setAccessibleName(QString());
#endif // QT_CONFIG(accessibility)
        User_Leasing_Status->setTabText(User_Leasing_Status->indexOf(tab_4), QCoreApplication::translate("Manager_widget", "\347\224\250\346\210\267", nullptr));
        User_Leasing_Status->setTabText(User_Leasing_Status->indexOf(tab), QCoreApplication::translate("Manager_widget", "\346\211\200\346\234\211\346\261\275\350\275\246", nullptr));
        Rent_the_car->setText(QCoreApplication::translate("Manager_widget", "\351\200\211\346\213\251\347\247\237\347\224\250", nullptr));
        label_2->setText(QCoreApplication::translate("Manager_widget", "\346\234\210", nullptr));
        label_3->setText(QCoreApplication::translate("Manager_widget", "\346\227\245", nullptr));
        User_Leasing_Status->setTabText(User_Leasing_Status->indexOf(tab_2), QCoreApplication::translate("Manager_widget", "\345\217\257\344\276\233\347\247\237\347\224\250\346\261\275\350\275\246", nullptr));
        Return_the_car->setText(QCoreApplication::translate("Manager_widget", "\345\275\222\350\277\230\346\261\275\350\275\246", nullptr));
        User_Leasing_Status->setTabText(User_Leasing_Status->indexOf(tab_3), QCoreApplication::translate("Manager_widget", "\345\275\223\345\211\215\347\224\250\346\210\267\347\247\237\350\265\201\347\212\266\345\206\265", nullptr));
        Do_Sql_Query->setText(QCoreApplication::translate("Manager_widget", "Do_Sql_Query", nullptr));
        New_User_Registration->setText(QCoreApplication::translate("Manager_widget", "\346\226\260\345\273\272\347\224\250\346\210\267", nullptr));
        Retrieving_user_Information->setText(QCoreApplication::translate("Manager_widget", "\351\200\211\346\213\251\347\224\250\346\210\267", nullptr));
        All_User_Information->setText(QCoreApplication::translate("Manager_widget", "\346\211\200\346\234\211\347\224\250\346\210\267\346\237\245\350\257\242", nullptr));
        toolBox->setItemText(toolBox->indexOf(page), QCoreApplication::translate("Manager_widget", "\347\224\250\346\210\267", nullptr));
        All_Car_Information->setText(QCoreApplication::translate("Manager_widget", "\346\230\276\347\244\272\346\211\200\346\234\211\350\275\246\350\276\206", nullptr));
        Available_Car_Information->setText(QCoreApplication::translate("Manager_widget", "\346\230\276\347\244\272\345\217\257\347\247\237\347\224\250\350\275\246\350\276\206", nullptr));
        label_4->setText(QCoreApplication::translate("Manager_widget", "\351\200\211\346\213\251\345\274\200\345\247\213\347\247\237\350\265\201\346\227\266\351\227\264", nullptr));
        toolBox->setItemText(toolBox->indexOf(car), QCoreApplication::translate("Manager_widget", "\350\275\246\350\276\206", nullptr));
        label->setText(QCoreApplication::translate("Manager_widget", "\345\275\223\345\211\215\347\224\250\346\210\267\344\277\241\346\201\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Manager_widget: public Ui_Manager_widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGER_WIDGET_H
