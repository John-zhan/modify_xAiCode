# CMake 最低版本要求
cmake_minimum_required(VERSION 3.10)

# 项目名称和语言
project(modify_xAiCode CXX)

# 设置 C++ 标准 (例如 C++11, C++14, C++17, C++20)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
# 建议关闭编译器特定的扩展，以提高可移植性
# set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(.)

# 添加可执行文件目标
# 源文件是相对于这个 CMakeLists.txt 文件的路径
# 假设这个 CMakeLists.txt 文件位于 'common' 目录中
add_executable(modify_xAiCode
    common/args.cpp    
    node/interfaces.cpp
    init.cpp
    btd.cpp
)