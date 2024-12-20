# 汽车租赁系统 (Car Rental System)

## 项目简介
这是一个基于 Qt 和 SQL Server 的汽车租赁管理系统。该系统旨在帮助汽车租赁公司管理客户、车辆和租赁记录。用户可以通过图形界面进行车辆租赁、归还操作，并查看当前的租赁状态。系统支持与 SQL Server 数据库的交互，确保数据的安全性和一致性。

## 目录结构
- CarRentalSystem/
  1. src/  
     - main.cpp  
     - manager_widget.cpp  
     - manager_widget.h  
     - sql_manager.cpp  
     - sql_manager.h  
  2. ui/  
     - manager_widget.ui  
     - mainwindow.ui  
  3. resources/  
     - icons/  
  4. db/  
     - create_db.sql  
  5. .gitignore  
  6. CMakeLists.txt  
  7. README.md  


## 功能概述
- 车辆管理：管理员可以添加、编辑和删除车辆信息。
- 客户管理：管理员可以添加、编辑和删除客户信息。
- 租赁管理：用户可以租赁车辆，选择租赁日期和预计归还日期。管理员可以记录实际归还日期并更新租赁状态。
- 查询功能：用户可以查询当前的租赁记录、未归还的租赁记录以及历史租赁记录。
- 日历选择：用户可以通过日历组件选择租赁和归还日期。
- 数据持久化：所有数据存储在 SQL Server 数据库中，确保数据的安全性和一致性。

## 技术栈
- 前端：Qt 6.x（C++ GUI 库）
- 后端：SQL Server 2019 或更高版本
- 数据库连接：ODBC 驱动程序
- 构建工具：CMake 3.16 或更高版本

## 开发环境推荐
为了更好地开发和维护此项目，建议使用以下开发环境：

- **CLion**：CLion 是一个强大的 C/C++ IDE，特别适合 CMake 项目。它提供了良好的代码补全、调试工具和项目管理功能，能够显著提高开发效率。

### 安装 CLion
1. 下载并安装 CLion。
2. 安装 Qt 插件以支持 Qt 项目的开发。

### 配置 Qt 支持
在 CLion 中配置 Qt 工具链，确保可以正确编译和运行 Qt 项目
