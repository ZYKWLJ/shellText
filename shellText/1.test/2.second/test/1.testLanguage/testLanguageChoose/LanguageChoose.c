#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LanguageInterface.h"
// 定义接口，返回语言类型
typedef LanguageInterface (*LanguageHandler)();

// 定义语言结构体，包含语言名称和对应的处理函数
typedef struct
{
    char *name;
    LanguageHandler handler; // 语言的具体接口
} Language;

// 全局变量，用于存储已注册的语言
Language *registeredLanguages = NULL; // 相当于一个数组
int languageCount = 0;                // 数组计数

// 注册语言的函数先
void registerLanguage(const char *name, LanguageHandler handler)
{
    registeredLanguages = realloc(registeredLanguages, (languageCount + 1) * sizeof(Language)); // 从头开始分配与覆盖！
    registeredLanguages[languageCount].name = strdup(name);
    registeredLanguages[languageCount].handler = handler;
    languageCount++;
}

// 根据语言名称获取对应的处理函数
LanguageInterface languageInterface(const char *languageName)
{
    for (int i = 0; i < languageCount; i++)
    {
        if (strcmp(registeredLanguages[i].name, languageName) == 0)
        {
            return registeredLanguages[i].handler();
        }
    }
    printf("无效的语言选择。\n");
}
// 处理中文的函数
LanguageInterface handleChinese()
{
    printf("您选择了中文，正在进行中文相关的后续操作。\n");
    return CHINESE;
}

// 处理英文的函数
LanguageInterface handleEnglish()
{
    printf("You have selected English, performing relevant subsequent operations.\n");
    return ENGLISH;
}

int main()
{
    // 注册中文和英文
    registerLanguage("中文", handleChinese);
    registerLanguage("English", handleEnglish);

    while (1)
    {
        char input[20];
        printf("请输入您的语言选择（输入“中文”或“English”）：");
        if (scanf("%19s", input) != 1)
        {
            // 处理输入错误
            printf("输入错误，请重新输入。\n");
            while (getchar() != '\n')
                ; // 清空输入缓冲区
            continue;
        }

        languageInterface(input);
    }

    // 在程序结束时释放动态分配的内存
    for (int i = 0; i < languageCount; i++)
    {
        free(registeredLanguages[i].name);
    }
    free(registeredLanguages);

    return 0;
}