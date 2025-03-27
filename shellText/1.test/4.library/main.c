#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_BOOKS 100
#define FILENAME "library.dat"

// 图书结构体
typedef struct {
    int id;             // 图书编号
    char title[100];    // 书名
    char author[50];    // 作者
    char publisher[50]; // 出版社
    int year;           // 出版年份
    int stock;          // 库存数量
} Book;

Book library[MAX_BOOKS]; // 图书数组
int bookCount = 0;       // 当前图书数量

// 函数声明
void loadBooks();
void saveBooks();
void addBook();
void deleteBook();
void modifyBook();
void searchBook();
void displayAllBooks();
void displayMenu();
void clearInputBuffer();

int main() {
    loadBooks(); // 启动时加载数据

    int choice;
    do {
        displayMenu();
        printf("请输入您的选择: ");
        scanf("%d", &choice);
        clearInputBuffer(); // 清除输入缓冲区

        switch(choice) {
            case 1: addBook(); break;
            case 2: deleteBook(); break;
            case 3: modifyBook(); break;
            case 4: searchBook(); break;
            case 5: displayAllBooks(); break;
            case 0: 
                saveBooks(); // 退出前保存数据
                printf("感谢使用图书管理系统，再见！\n");
                break;
            default: 
                printf("无效的选择，请重新输入！\n");
        }
    } while(choice != 0);

    return 0;
}

// 加载图书数据
void loadBooks() {
    FILE *file = fopen(FILENAME, "rb");
    if (file == NULL) {
        printf("未找到数据文件，将创建新文件。\n");
        return;
    }

    bookCount = fread(library, sizeof(Book), MAX_BOOKS, file);
    fclose(file);
    printf("成功加载 %d 本图书数据。\n", bookCount);
}

// 保存图书数据
void saveBooks() {
    FILE *file = fopen(FILENAME, "wb");
    if (file == NULL) {
        printf("无法创建数据文件！\n");
        return;
    }

    int saved = fwrite(library, sizeof(Book), bookCount, file);
    fclose(file);
    printf("成功保存 %d 本图书数据。\n", saved);
}

// 添加图书
void addBook() {
    if (bookCount >= MAX_BOOKS) {
        printf("图书库已满，无法添加更多图书！\n");
        return;
    }

    Book newBook;
    printf("\n--- 添加新图书 ---\n");

    printf("请输入图书编号: ");
    scanf("%d", &newBook.id);
    clearInputBuffer();

    // 检查编号是否已存在
    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == newBook.id) {
            printf("错误：该图书编号已存在！\n");
            return;
        }
    }

    printf("请输入书名: ");
    fgets(newBook.title, sizeof(newBook.title), stdin);
    newBook.title[strcspn(newBook.title, "\n")] = '\0'; // 去除换行符

    printf("请输入作者: ");
    fgets(newBook.author, sizeof(newBook.author), stdin);
    newBook.author[strcspn(newBook.author, "\n")] = '\0';

    printf("请输入出版社: ");
    fgets(newBook.publisher, sizeof(newBook.publisher), stdin);
    newBook.publisher[strcspn(newBook.publisher, "\n")] = '\0';

    printf("请输入出版年份: ");
    scanf("%d", &newBook.year);
    clearInputBuffer();

    printf("请输入库存数量: ");
    scanf("%d", &newBook.stock);
    clearInputBuffer();

    library[bookCount++] = newBook;
    printf("图书添加成功！\n");
}

// 删除图书
void deleteBook() {
    if (bookCount == 0) {
        printf("图书库为空，没有可删除的图书！\n");
        return;
    }

    int id;
    printf("\n--- 删除图书 ---\n");
    printf("请输入要删除的图书编号: ");
    scanf("%d", &id);
    clearInputBuffer();

    int found = 0;
    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == id) {
            found = 1;
            // 将后面的书向前移动
            for (int j = i; j < bookCount - 1; j++) {
                library[j] = library[j + 1];
            }
            bookCount--;
            printf("图书删除成功！\n");
            break;
        }
    }

    if (!found) {
        printf("未找到编号为 %d 的图书！\n", id);
    }
}

// 修改图书信息
void modifyBook() {
    if (bookCount == 0) {
        printf("图书库为空，没有可修改的图书！\n");
        return;
    }

    int id;
    printf("\n--- 修改图书信息 ---\n");
    printf("请输入要修改的图书编号: ");
    scanf("%d", &id);
    clearInputBuffer();

    int found = 0;
    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == id) {
            found = 1;
            Book *book = &library[i];

            printf("当前书名: %s\n新书名(直接回车保持原值): ", book->title);
            char input[100];
            fgets(input, sizeof(input), stdin);
            if (strlen(input) > 1) { // 用户输入了新值
                input[strcspn(input, "\n")] = '\0';
                strcpy(book->title, input);
            }

            printf("当前作者: %s\n新作者(直接回车保持原值): ", book->author);
            fgets(input, sizeof(input), stdin);
            if (strlen(input) > 1) {
                input[strcspn(input, "\n")] = '\0';
                strcpy(book->author, input);
            }

            printf("当前出版社: %s\n新出版社(直接回车保持原值): ", book->publisher);
            fgets(input, sizeof(input), stdin);
            if (strlen(input) > 1) {
                input[strcspn(input, "\n")] = '\0';
                strcpy(book->publisher, input);
            }

            printf("当前出版年份: %d\n新出版年份(输入0保持原值): ", book->year);
            int year;
            scanf("%d", &year);
            clearInputBuffer();
            if (year != 0) {
                book->year = year;
            }

            printf("当前库存数量: %d\n新库存数量(输入0保持原值): ", book->stock);
            int stock;
            scanf("%d", &stock);
            clearInputBuffer();
            if (stock != 0) {
                book->stock = stock;
            }

            printf("图书信息修改成功！\n");
            break;
        }
    }

    if (!found) {
        printf("未找到编号为 %d 的图书！\n", id);
    }
}

// 搜索图书
void searchBook() {
    if (bookCount == 0) {
        printf("图书库为空，没有可搜索的图书！\n");
        return;
    }

    int choice;
    printf("\n--- 搜索图书 ---\n");
    printf("1. 按编号搜索\n");
    printf("2. 按书名搜索\n");
    printf("3. 按作者搜索\n");
    printf("请选择搜索方式: ");
    scanf("%d", &choice);
    clearInputBuffer();

    char keyword[100];
    int id;
    int found = 0;

    switch(choice) {
        case 1:
            printf("请输入图书编号: ");
            scanf("%d", &id);
            clearInputBuffer();

            for (int i = 0; i < bookCount; i++) {
                if (library[i].id == id) {
                    printf("\n找到图书:\n");
                    printf("编号: %d\n", library[i].id);
                    printf("书名: %s\n", library[i].title);
                    printf("作者: %s\n", library[i].author);
                    printf("出版社: %s\n", library[i].publisher);
                    printf("出版年份: %d\n", library[i].year);
                    printf("库存数量: %d\n", library[i].stock);
                    found = 1;
                    break;
                }
            }
            break;

        case 2:
            printf("请输入书名关键字: ");
            fgets(keyword, sizeof(keyword), stdin);
            keyword[strcspn(keyword, "\n")] = '\0';

            printf("\n搜索结果:\n");
            for (int i = 0; i < bookCount; i++) {
                if (strstr(library[i].title, keyword) != NULL) {
                    printf("%d. %s (作者: %s)\n", library[i].id, library[i].title, library[i].author);
                    found = 1;
                }
            }
            break;

        case 3:
            printf("请输入作者关键字: ");
            fgets(keyword, sizeof(keyword), stdin);
            keyword[strcspn(keyword, "\n")] = '\0';

            printf("\n搜索结果:\n");
            for (int i = 0; i < bookCount; i++) {
                if (strstr(library[i].author, keyword) != NULL) {
                    printf("%d. %s (作者: %s)\n", library[i].id, library[i].title, library[i].author);
                    found = 1;
                }
            }
            break;

        default:
            printf("无效的选择！\n");
            return;
    }

    if (!found) {
        printf("未找到匹配的图书！\n");
    }
}

// 显示所有图书
void displayAllBooks() {
    if (bookCount == 0) {
        printf("图书库为空！\n");
        return;
    }

    printf("\n--- 所有图书列表 ---\n");
    printf("%-6s %-30s %-20s %-20s %-6s %-6s\n", 
           "编号", "书名", "作者", "出版社", "年份", "库存");
    printf("----------------------------------------------------------------\n");

    for (int i = 0; i < bookCount; i++) {
        printf("%-6d %-30s %-20s %-20s %-6d %-6d\n", 
               library[i].id, 
               library[i].title, 
               library[i].author, 
               library[i].publisher, 
               library[i].year, 
               library[i].stock);
    }
    printf("共 %d 本图书\n", bookCount);
}

// 显示菜单
void displayMenu() {
    printf("\n=== 图书管理系统 ===\n");
    printf("1. 添加图书\n");
    printf("2. 删除图书\n");
    printf("3. 修改图书\n");
    printf("4. 搜索图书\n");
    printf("5. 显示所有图书\n");
    printf("0. 退出系统\n");
}

// 清除输入缓冲区
void clearInputBuffer() {
    while (getchar() != '\n');
}