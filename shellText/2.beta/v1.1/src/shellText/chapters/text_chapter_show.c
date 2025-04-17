// #include "../../../include/shellText/chapter_show.h"
#include "../../../include/shellText/text_chapter_show.h"
void display_chapters(int chapter_num)
{
    switch (chapter_num)
    {
    case 0:
        display_chapter1();
        display_chapter2();
        display_chapter3();
        display_chapter4();
        display_chapter5();
        display_chapter6();
        display_chapter7();
        display_chapter8();
        display_chapter9();
        break;
    case 1:
        display_chapter1();
        break;
    case 2:
        display_chapter2();
        break;
    case 3:
        display_chapter3();
        break;
    case 4:
        display_chapter4();
        break;
    case 5:
        display_chapter5();
        break;
    case 6:
        display_chapter6();
        break;
    case 7:
        display_chapter7();
        break;
    case 8:
        display_chapter8();
        break;
    case 9:
        display_chapter9();
        break;
    default:
        break;
    }
}
