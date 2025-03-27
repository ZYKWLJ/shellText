#include "../include/main.h"
int main()
{
    for (int i = 0; words[i]; i++)
    {
        for (int j = 0; words[i][j]; j++)
        {
            puts(words[i][j]);
        }
    }
    return 0;
}


/*
清理cmake缓存的方法:
rm -rf CMakeCache.txt CMakeFiles

# 重新运行CMake生成构建文件
cmake ..

# 执行构建命令，这里以make为例
make
*/
