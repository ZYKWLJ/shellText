cmake_minimum_required(VERSION 3.5)
project (main) # 定义项目的名称。

set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin) # PROJECT_SOURCE_DIR是包含CMakeLists.txt的目录，这里是设置可执行文件的输出路径。

# 使用 file(GLOB_RECURSE) 递归获取所有源文件
file(GLOB_RECURSE SRC_LIST "src/*.c" "src/*/*.c" "src/*/*/*.c")

include_directories (include)# 指定头文件的搜索路径。即.h文件

# 查找 readline 库
find_library(READLINE_LIBRARY readline)
find_path(READLINE_INCLUDE_DIR readline/readline.h)

if(READLINE_LIBRARY AND READLINE_INCLUDE_DIR)
    include_directories(${READLINE_INCLUDE_DIR})
    add_executable (main ${SRC_LIST})# 创建一个可执行文件。名字为main
    # 链接 readline 库
    target_link_libraries(main ${READLINE_LIBRARY})
else()
    message(FATAL_ERROR "readline library not found!")
endif()