cmake_minimum_required (VERSION 3.8)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
project(Sql_manager)

set(CMAKE_CXX_STANDARD 17)

# 将源代码添加到此项目的可执行文件。
add_executable(Sql_manager
        main.cpp
)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
# 设置目标架构为 x64
#set(CMAKE_GENERATOR_PLATFORM x64)

# 如果支持，请为 MSVC 编译器启用热重载。
if (POLICY CMP0141)
    cmake_policy(SET CMP0141 NEW)
    set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()
# 将项目设置为 Windows 应用，避免控制台窗口
set(CMAKE_WIN32_EXECUTABLE ON)

# TODO: 如有需要，请添加测试并安装目标。

# 提供位置定位 Qt6 的 .cmake 文件
set(Qt6_DIR "E:/studyspace/QT/6.8.0/mingw_64/lib/cmake/Qt6")

# 寻找 Qt6，这里不需要再寻找 Qt5
find_package(Qt6 REQUIRED COMPONENTS Core Widgets Sql)

target_link_libraries(Sql_manager PRIVATE Qt6::Core Qt6::Widgets Qt6::Sql)

# 如果需要使用 Qt 版本变量，可以这样设置
if(Qt6_FOUND)
    set(QT_VERSION_MAJOR 6)
endif()

# 如果您的代码需要根据 Qt 版本动态处理，可以使用以下代码
if(${QT_VERSION_MAJOR} EQUAL 6)
    # 对于 Qt6，执行一些操作
endif()

# TODO: 如有需要，请添加测试并安装目标。