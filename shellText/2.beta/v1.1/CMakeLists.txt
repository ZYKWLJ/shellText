cmake_minimum_required(VERSION 3.5)
project(main)

# 设置可执行文件输出路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# 递归查找所有源文件
file(GLOB_RECURSE SRC_LIST
    "src/*.c"
    "src/*/*.c"
    "src/*/*/*.c"
)

# 添加可执行文件
add_executable(main ${SRC_LIST})

# 递归查找所有头文件目录并添加到包含路径
file(GLOB_RECURSE INC_DIRS
    "include/*.h"
    "include/*/*.h"
    "include/*/*/*.h"
)
foreach(INC_DIR ${INC_DIRS})
    get_filename_component(DIR ${INC_DIR} DIRECTORY)
    target_include_directories(main PUBLIC ${DIR})
endforeach()

# 查找 readline 库
find_library(READLINE_LIBRARY readline)
find_path(READLINE_INCLUDE_DIR readline/readline.h)

if(READLINE_LIBRARY AND READLINE_INCLUDE_DIR)
    # 添加 readline 库的头文件搜索路径
    target_include_directories(main PUBLIC ${READLINE_INCLUDE_DIR})
    # 链接 readline 库
    target_link_libraries(main PRIVATE ${READLINE_LIBRARY})
    # 链接 -lrt 库
    target_link_libraries(main PRIVATE -lrt)
else()
    message(FATAL_ERROR "readline library not found!")
endif()