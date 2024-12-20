汽车租赁系统 (Car Rental System)
项目简介
这是一个基于 Qt 和 SQL Server 的汽车租赁管理系统。该系统旨在帮助汽车租赁公司管理客户、车辆和租赁记录。用户可以通过图形界面进行车辆租赁、归还操作，并查看当前的租赁状态。系统支持与 SQL Server 数据库的交互，确保数据的安全性和一致性。

目录结构
深色版本
CarRentalSystem/
│
├── src/                    # 源代码目录
│   ├── main.cpp            # 主程序入口
│   ├── manager_widget.cpp  # 管理员界面实现
│   ├── manager_widget.h    # 管理员界面头文件
│   └── sql_manager.cpp     # 数据库管理类实现
│   └── sql_manager.h       # 数据库管理类头文件
│
├── ui/                     # 用户界面文件
│   ├── manager_widget.ui   # 管理员界面设计文件
│   └── mainwindow.ui       # 主窗口界面设计文件
│
├── resources/              # 资源文件（图标、图片等）
│   └── icons/              # 图标文件
│
├── db/                     # 数据库脚本和备份
│   └── create_db.sql       # 创建数据库的 SQL 脚本
│
├── .gitignore              # Git 忽略文件配置
├── CMakeLists.txt          # CMake 构建文件
└── README.md               # 项目说明文档
功能概述
车辆管理：管理员可以添加、编辑和删除车辆信息。
客户管理：管理员可以添加、编辑和删除客户信息。
租赁管理：用户可以租赁车辆，选择租赁日期和预计归还日期。管理员可以记录实际归还日期并更新租赁状态。
查询功能：用户可以查询当前的租赁记录、未归还的租赁记录以及历史租赁记录。
日历选择：用户可以通过日历组件选择租赁和归还日期。
数据持久化：所有数据存储在 SQL Server 数据库中，确保数据的安全性和一致性。
技术栈
前端：Qt 6.x（C++ GUI 库）
后端：SQL Server 2019 或更高版本
数据库连接：ODBC 驱动程序
构建工具：CMake 3.16 或更高版本


建议使用 Clion 对于 cmake 工程的 qt,, 如果是用 qtcreate  可能出现 未知问题
