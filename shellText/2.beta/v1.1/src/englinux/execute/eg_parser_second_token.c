#include "../../../include/englinux/execute/eg_parser_second_token.h"
// 提取字符串中的中文字符
int handlerChinese(const char *input, char *output)
{
    int len = strlen(input);
    int index = 0;
    int hasChinese = 0;

    for (int i = 0; i < len; i++)
    {
        // 检查是否为中文字符（UTF-8 编码下，中文字符以 0xE 开头）
        if ((input[i] & 0xF0) == 0xE0)
        {
            output[index++] = input[i];
            output[index++] = input[++i];
            output[index++] = input[++i];
            hasChinese = 1;
        }
    }
    output[index] = '\0';

    return hasChinese;
}


// 封装函数，生成所有可能的子查询并存储到数组中
// 封装函数，生成所有可能的子查询并存储到数组中// 封装函数，生成所有可能的子查询并存储到数组中// 获取UTF-8字符的字节长度
int utf8_char_len(unsigned char c) {
    if (c < 0x80) return 1;        // ASCII字符(1字节)
    if ((c & 0xE0) == 0xC0) return 2; // 2字节字符
    if ((c & 0xF0) == 0xE0) return 3; // 中文等(3字节)
    if ((c & 0xF8) == 0xF0) return 4; // 4字节字符
    return 1;                      // 默认情况
}

int generateSubqueries(const char *input, char *subquerys[1024]) {
    int len = strlen(input);
    int count = 0;
    
    // 首先记录每个完整字符的起始位置
    int char_offsets[1024];
    int char_count = 0;
    
    for (int i = 0; i < len;) {
        int char_len = utf8_char_len(input[i]);
        if (i + char_len > len) break; // 跳过不完整的尾部字符
        
        char_offsets[char_count++] = i;
        i += char_len;
    }

    // 生成所有可能的子串
    for (int sub_char_len = char_count; sub_char_len > 0; sub_char_len--) {
        for (int start = 0; start <= char_count - sub_char_len; start++) {
            int end = start + sub_char_len;
            int byte_start = char_offsets[start];
            int byte_end = (end < char_count) ? char_offsets[end] : len;
            int sub_len = byte_end - byte_start;
            
            subquerys[count] = (char *)malloc(sub_len + 1);
            if (!subquerys[count]) {
                // 内存分配失败，清理已分配的内存
                for (int i = 0; i < count; i++) free(subquerys[i]);
                return -1;
            }
            
            strncpy(subquerys[count], input + byte_start, sub_len);
            subquerys[count][sub_len] = '\0';
            count++;
            
            if (count >= 1024) return count; // 防止溢出
        }
    }
    
    return count;
}


int parser_second_token(char *token, char *origin_str, int *find_mod, char *word,char *subquerys[1024])
{
    // 1.先判断是不是合法单词！
    // 首先去除可能的%
    int l = 0, r = strlen(token) - 1;
    if (token[0] == '%')
    {
        l++;
    }
    if (token[r] == '%')
    {
        r--;
    }
    // 直接处理原始 word 指针，不要创建新的 str
    // 将处理后的字符串复制到 word 中
    int len = r - l + 1;
    strncpy(word, token + l, len);
    word[len] = '\0';

    char chinese[100];
    // 处理中文字符
    if (handlerChinese(word, chinese)) {
        // printf("查询中文！\n");
        // 这里假设 ERROR_CMDS 等是宏定义，暂时忽略
        // 生成所有可能的子查询
        int subquery_count = generateSubqueries(chinese, subquerys);
        // if (subquery_count > 0) {
        //     for (int i = 0; i < subquery_count; i++) {
        //         printf("子查询: %s\n", subquerys[i]);
        //     }
        // }
        return 2;
    }
    else
    {//不是中文再处理英文
        // 2.再判断中心的字符串是不是全字母！
        if (!is_all_alpha(word))
        {
            printf(ERROR_CMDS, BOLD, RED, origin_str, RESET, BOLD, YELLOW, RESET);
            return 0;
        }

        // 开始解析查找模式！
        if (l == 0 && r == strlen(token) - 1)
        {
            *find_mod = 0;
        }
        else if (l == 0)
        {
            *find_mod = 1;
        }
        else if (r == strlen(token) - 1)
        {
            *find_mod = 2;
        }
        else
        {
            *find_mod = 3;
        }
    }
    return 1;
}