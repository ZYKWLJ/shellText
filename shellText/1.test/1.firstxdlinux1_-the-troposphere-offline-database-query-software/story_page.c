#include "story_page.h"
#include "main.h"


//软件背后的故事打印
void story_page(int sleep_time1, int sleep_time2, int interval_num_to_sleep)
{
    printf("\n\n");
   
    
    printBanner_yellow(DOTTED_LINE_STORY_END_MIDDLE);

    cursor_move_Ncolumn_print(57);
    Dynamic_input_red("《善者因之》\n\n", SLEEP_TIME1,1);
    fast_Dynamic_input("一次对流层课堂上我在后面编程序,弓老师走过来问我:\"同学你是在编程序？\"我略显尴尬地微微地回答:\"我在看计算机的书籍（至今记忆尤深,当时再看《深入理解计算机系统》的第八章）\"。没想到弓老师及其激动,认可地说:\"好,编程序好,谁说对流层的课程只能干对流层的事,这不是耍流氓吗？（这句话我记忆尤深）\",此话一出,我已经被弓老师的宏大的胸襟所触动。", SLEEP_TIME2, INTERVAL_NUM_TO_SLEEP);
    fast_Dynamic_input("\"你喜欢编程序,那你编写一个能够实现对流层的XXX数据查询的程序。\"弓老师半笑着打趣到,不过当时只是内心很触动,并非有此意向。或者说,只是种下了一颗我都不知道什么时候种下的种子。", SLEEP_TIME2, INTERVAL_NUM_TO_SLEEP);
    fast_Dynamic_input("别的老师课上只要你不好好听讲,干其他的,老师虽然不说,但或多或少会有些意见,强者金刚怒目,佛者直接不管,温者好言相劝,而只智者,善者因之。（太史公:故善者因之,其次利道 之,其次教诲之,其次整齐之,最下者与之争。这句千古名言,真正明了又几何呢？）（非常抱歉和羞惭,我如此大胆评价教师,然而就当我是大逆不道地阐述可能存在的客观事实吧）。说实话上了大学能有这么有趣和开明的老师真是学生的（至少是我的）幸福,其实环顾当下教育,好像任何教学阶段都是如此）。\n\n\n", SLEEP_TIME2, INTERVAL_NUM_TO_SLEEP);

    cursor_move_Ncolumn_print(57);
    Dynamic_input_red("《刷视频也是好的》\n\n", SLEEP_TIME1,1);
    fast_Dynamic_input("第二次契机是,我依然在最后面敲电脑,弓老师先用上课铃声引出思考——他认为这个上课铃声太为之低靡,消沉（其实在西电待一会就能够立马知道）。即可让大家发表观点如果让你来设计，你会何为？莫看事小，小也是大，小处见微，细节定败。既有包藏宇宙之怀，又有细钻微渺之心。", SLEEP_TIME2, INTERVAL_NUM_TO_SLEEP);
    fast_Dynamic_input("老师还说了很多立志励志之言,大意就是要真正找到自己所热爱的东西,把这件事情做头,那么万事也就做透了。这个观点与我深深契合。老师说,不一定要来教室上课,只要你说你在宿舍学高数学的十分认真专注,效率很好,那么你不来上课完全没问题,我支持你,要打开自己的胸结。", SLEEP_TIME2, INTERVAL_NUM_TO_SLEEP);
    fast_Dynamic_input("之后,弓老师走到一位同学面前问道,\"同学你的爱好是什么？\",可能是看到这位同学一直在刷视频,弓老师便打趣到\"你的爱好是刷视频\",听到这话,我稍微地笑了笑,没想到弓老师来了个急转弯,大声而坚定地说\"刷视频好,谁说刷视频不好,你在刷视频的同时,把制作视频的经验总结下来,这就是你的能力,这当然好啊。所以说不要限制自己,要多思维,多角度看待事情。", SLEEP_TIME2, INTERVAL_NUM_TO_SLEEP);
    fast_Dynamic_input("问君此言,顿时羞愧难当（之前我一直认为刷视频是浪费生命,看来自己的胸结还不够打开,而弓老师定为助开此胸结之贵人）,再次被弓老师的博达之胸怀,广阔之视野,深远之洞见,通融之气骨所震撼,折服（至少上大学来,或者说自从上学以来,就只有弓老师这么说过,其之伟岸通达,遇者真乃之幸运,此乃可遇不可求）（反思自身,或许真是太偏执孤傲视短眼近,要打开胸结！）。 \n\n\n", SLEEP_TIME2, INTERVAL_NUM_TO_SLEEP);

    cursor_move_Ncolumn_print(57);
    Dynamic_input_red("《国际视野家国情怀》\n\n", SLEEP_TIME1,1);

    fast_Dynamic_input("第三次契机便与本次软件开发深深相关了。还是这节课,我猫在最后看linux。老师走过来就问我,同学你在编程？我说我在学linux,老师就和我说了很多关于操作系统之国内国际事之大小,国内操作系统各方面之受垄断之窘况,风格还是持肯定态度,而当时我正在使用的指令是tree遍历,这和这个软件的本质是相同的——数据遍历,这直接引起了我有兴趣用tree命令的风格做一些有用的开发的心思。\n\n\n", SLEEP_TIME2, INTERVAL_NUM_TO_SLEEP);

    cursor_move_Ncolumn_print(57);
    Dynamic_input_red("《宏博之视野,全维之思辩》\n\n", SLEEP_TIME1,1);
    fast_Dynamic_input("第四次契机是\"萨拉热窝\"级的（第一次世界大战引火线）,也是我毛遂自荐之举之引。", SLEEP_TIME2, INTERVAL_NUM_TO_SLEEP);
    fast_Dynamic_input("老师在群里发了一些\"无关教学内容\"的视频——其中内容大概是视频制作之思维,机械构造之精巧,前人智慧之凝练诸类……", SLEEP_TIME2, INTERVAL_NUM_TO_SLEEP);
    fast_Dynamic_input("很难想象,老师和学生们发的内容基本全是与\"教学无关\"的,而是一些任何能够激发学生们的思维,提升学生们的能力的东西（而这事实上,貌似似之国内外教学大环境之比）。（事实上一些老师,课上了后,你就找不到TA了）随后我当即问之是否需要制作此程序,得知肯定后,立即展开工作,两个小时左右理清了大致框架与实现,并成功进行了数据测试。于是,我当晚私聊了弓老师——表明构筑心志之坚与构建蓝图之伟。", SLEEP_TIME2, INTERVAL_NUM_TO_SLEEP);
    fast_Dynamic_input("虽然弓老师未教我半点技术之事,但是他确是这款软件的直接引导者,也开阔了我的视野与格局。谢谢。\n", SLEEP_TIME2, INTERVAL_NUM_TO_SLEEP);
    Dynamic_input_red("\n\n谨将此软件献给人生路上无数个像弓老师一样的引路人。谢谢。\n\n\n", SLEEP_TIME1,1);

    cursor_move_Ncolumn_print(101);
    Dynamic_input_green(NAME, SLEEP_TIME1,1);
    printf("\n");
    cursor_move_Ncolumn_print(101);
    cursor_move_Ncolumn_print(101);
    Dynamic_input_green(DATE1, SLEEP_TIME1,1);
    printf("\n");
    cursor_move_Ncolumn_print(101);
    Dynamic_input_green(ADDRESS, SLEEP_TIME1,1);
    printf("\n");

    //    cursor_move_Ncolumn_print(21);
    //    printf("%s%s%s%s%s", DOTTED_LINE_FORNT, YELLOW_TEXT, DOTTED_LINE_STORY_END_MIDDLE, RESET_COLOR, DOTTED_LINE_BACK);
    printBanner_yellow(DOTTED_LINE_STORY_END_MIDDLE);
}
