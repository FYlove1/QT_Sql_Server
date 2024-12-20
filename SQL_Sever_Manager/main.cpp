#include <QApplication>
#include "manager_widget.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Manager_widget m;
    m.show();

    return a.exec();
}



/*
新客户注册
支持新客户注册，记录客户信息。
查询客户信息

//////
租赁管理
提供租车服务选择。
客户可以选择不同的车辆进行租赁。
设置租赁时间（起始时间和归还时间）。
归还设置
支持客户归还车辆。
记录归还时间并更新车辆状态。
会员登录
支持会员登录，验证用户身份。
会员可以查看个人租车记录和账户信息。
价格管理
根据会员等级设置不同的租车价格。
系统自动根据会员等级计算租金。
会员等级管理
支持不同会员等级的创建和管理。
不同等级享有不同的优惠和服务。
 *
 *
 *
 *
 */