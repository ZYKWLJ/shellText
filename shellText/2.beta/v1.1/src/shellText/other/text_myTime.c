# include "../../../include/shellText/text_myTime.h"
// 清屏函数
void clear_screen_myTime() {
    printf("\033[2J");
    printf("\033[H");
}

// 定义数字的 ASCII 艺术字
const char *digits[10][5] = {
    {
        "  _  ",
        " | | ",
        " |_| ",
        "     ",
        "     "
    },
    {
        "     ",
        "   | ",
        "   | ",
        "     ",
        "     "
    },
    {
        "  _  ",
        "  _| ",
        " |_  ",
        "     ",
        "     "
    },
    {
        "  _  ",
        "  _| ",
        "  _| ",
        "     ",
        "     "
    },
    {
        "     ",
        " |_| ",
        "   | ",
        "     ",
        "     "
    },
    {
        "  _  ",
        " |_  ",
        "  _| ",
        "     ",
        "     "
    },
    {
        "  _  ",
        " |_  ",
        " |_| ",
        "     ",
        "     "
    },
    {
        "  _  ",
        "   | ",
        "   | ",
        "     ",
        "     "
    },
    {
        "  _  ",
        " |_| ",
        " |_| ",
        "     ",
        "     "
    },
    {
        "  _  ",
        " |_| ",
        "  _| ",
        "     ",
        "     "
    }
};

// 冒号的 ASCII 艺术字
const char *colon[5] = {
    "     ",
    "  ·  ",
    "     ",
    "  ·  ",
    "     "
};

// 打印 ASCII 数字
void print_digit(int digit, int line) {
    printf("%s", digits[digit][line]);
}

// 打印冒号
void print_colon(int line) {
    printf("%s", colon[line]);
}

// 打印日期数字
void print_date_digits(int num, int line) {
    if (num < 10) {
        print_digit(0, line);
        print_digit(num, line);
    } else {
        print_digit(num / 10, line);
        print_digit(num % 10, line);
    }
}

void timeStart(){
    while (1) {
        clear_screen_myTime();

        // 获取当前时间
        time_t now = time(NULL);
        struct tm *local_time = localtime(&now);
        int year = local_time->tm_year + 1900;
        int month = local_time->tm_mon + 1;
        int day = local_time->tm_mday;
        int hour = local_time->tm_hour;
        int minute = local_time->tm_min;
        int second = local_time->tm_sec;

        // 打印日期
        for (int line = 0; line < 5; line++) {
            // 打印年份
            print_date_digits(year / 100, line);
            print_date_digits(year % 100, line);
            printf("  ");

            // 打印月份
            print_date_digits(month, line);
            printf("  ");

            // 打印日期
            print_date_digits(day, line);
            printf("\n");
        }

        // 打印分隔线
        for (int i = 0; i < 35; i++) {
            printf("-");
        }
        printf("\n");

        // 打印 ASCII 时钟
        for (int line = 0; line < 5; line++) {
            print_digit(hour / 10, line);
            print_digit(hour % 10, line);
            print_colon(line);
            print_digit(minute / 10, line);
            print_digit(minute % 10, line);
            print_colon(line);
            print_digit(second / 10, line);
            print_digit(second % 10, line);
            printf("\n");
        }

        // 控制帧率
        usleep(1000000); // 每秒更新一次
    }
}
// 主函数
// int main() {
//     printf(BOLD"");
//     printf(GREEN"");
//     timeStart();
//     printf(RESET"");

//     return 0;
// }    