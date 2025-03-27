#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

int main() {
    char *input;
    while (1) {
        input = readline("请输入命令: ");
        if (input == NULL) {
            break;
        }
        if (*input != '\0') {
            add_history(input);
            printf("你输入的命令是: %s\n", input);
        }
        free(input);
    }
    return 0;
}
/**
 * 命令行记忆化需要使用这个库：sudo apt-get install libreadline-dev
 * 然后链接的时候命令为：gcc main.c -o main -L/path/to/readline/lib -lreadline
 * 否则就会链接错误！
 * 
 */