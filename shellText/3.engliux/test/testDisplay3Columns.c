#include <stdio.h>

// 列宽定义
#define COL1_WIDTH 20
#define COL2_WIDTH 25
#define COL3_WIDTH 35

/**
 * @brief 显示指定列的内容
 * @param words 单词表二维数组
 * @param line 行号
 * @param first_show 第一列显示控制
 * @param second_show 第二列显示控制
 * @param third_show 第三列显示控制
 */
void show_columns(const char *words[][3], int line,
                 int first_show, int second_show, int third_show)
{
    // 参数检查
    if (words == NULL || line < 0) {
        printf("参数错误！\n");
        return;
    }
    
    // 检查行结束标记
    if (words[line][0] == NULL) {
        printf("行号超出范围！\n");
        return;
    }

    // 显示第一列
    if (first_show >= 1 && first_show <= 3) {
        printf("%-*s", COL1_WIDTH, words[line][first_show - 1]);
    } else if (first_show == 0) {
        printf("%-*s", COL1_WIDTH, "");
    }

    // 显示第二列
    if (second_show >= 1 && second_show <= 3) {
        printf("%-*s", COL2_WIDTH, words[line][second_show - 1]);
    } else if (second_show == 0) {
        printf("%-*s", COL2_WIDTH, "");
    }

    // 显示第三列
    if (third_show >= 1 && third_show <= 3) {
        printf("%-*s", COL3_WIDTH, words[line][third_show - 1]);
    } else if (third_show == 0) {
        printf("%-*s", COL3_WIDTH, "");
    }

    printf("\n");
}

int main() 
{
    // 单词表数据
    const char *word_set[][3] = {
        {"apple", "/ˈæpl/", "n. 苹果；苹果树；苹果公司"},
        {"banana", "/bəˈnɑːnə/", "n. 香蕉；芭蕉属植物"},
        {"cherry", "/ˈtʃeri/", "n. 樱桃；樱桃树；樱桃色"},
        {NULL, NULL, NULL}  // 结束标记
    };

    printf("=== 完美对齐测试 ===\n\n");

    // printf("1. 显示所有列\n");
    show_columns(word_set, 0, 1, 2, 3);

    // printf("\n2. 只显示单词\n");
    show_columns(word_set, 0, 1, 0, 0);

    // printf("\n3. 单词+释义\n");
    show_columns(word_set, 0, 1, 0, 3);

    // printf("\n4. 音标+释义\n");
    show_columns(word_set, 0, 0, 2, 3);

    // printf("\n5. 非常规顺序\n");
    show_columns(word_set, 1, 2, 1, 3);

    // printf("\n6. 越界测试\n");
    show_columns(word_set, 3, 1, 2, 3);  // 应显示"行号超出范围"

    return 0;
}