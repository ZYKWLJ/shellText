#include "main.h"

char header[100] = HEAD_OF_ALL;
char QueryKeywords[100] = { 0 };

//输入指令并解析的核心函数,无论新老用户都要做这一步，也是最核心的
int core_keywords_matching() {
    fflush(stdin);
    printf("%s[对流层传播@all~]>%s", GREEN_TEXT, RESET_COLOR);

    while (1)
    {

        fflush(stdin); // 清空输入缓冲区，确保从一个干净的状态开始
        //显现光标
        printf("\033[?25h");
        fgets(QueryKeywords, sizeof(QueryKeywords), stdin);

        //隐藏光标
        printf("\033[?25l");

        if (strcmp(QueryKeywords, "\n") == 0) {
            // 处理空输入
            printf("%s%s%s", GREEN_TEXT, header, RESET_COLOR);
            continue;

        }
        //去掉末尾的/n,因为可能会影响指令执行
        QueryKeywords[strcspn(QueryKeywords, "\n")] = '\0';




        //数据查询指令//最直接的单个表的查询

        if ( strcmp(QueryKeywords, "2.1") == 0 || strcmp(QueryKeywords, "2.3") == 0|| strcmp(QueryKeywords, "2.4") == 0 || strcmp(QueryKeywords, "2.5") == 0 ||
            strcmp(QueryKeywords, "2.6") == 0 || strcmp(QueryKeywords, "2.7") == 0 || strcmp(QueryKeywords, "2.8") == 0 || strcmp(QueryKeywords, "2.9.1") == 0 || 
            strcmp(QueryKeywords, "2.9.1") == 0 || strcmp(QueryKeywords, "2.9.2") == 0 || strcmp(QueryKeywords, "2.10") == 0 || strcmp(QueryKeywords, "2.11") == 0 || 
            strcmp(QueryKeywords, "3.10") == 0 || strcmp(QueryKeywords, "3.12") == 0 || strcmp(QueryKeywords, "3.13") == 0 || strcmp(QueryKeywords, "3.16") == 0 || 
            strcmp(QueryKeywords, "3.17") == 0 || strcmp(QueryKeywords, "3.18") == 0 || strcmp(QueryKeywords, "3.20") == 0 || strcmp(QueryKeywords, "3.21") == 0 || 
            strcmp(QueryKeywords, "3.25") == 0 || strcmp(QueryKeywords, "3.26") == 0 || strcmp(QueryKeywords, "3.29") == 0 || strcmp(QueryKeywords, "3.32") == 0 || 
            strcmp(QueryKeywords, "3.33") == 0 || strcmp(QueryKeywords, "3.34") == 0 || strcmp(QueryKeywords, "3.35.1") == 0 || strcmp(QueryKeywords, "3.36") == 0 || 
            strcmp(QueryKeywords, "3.35.2") == 0 || strcmp(QueryKeywords, "3.38") == 0 || strcmp(QueryKeywords, "3.6") == 0 || strcmp(QueryKeywords, "3.7") == 0 || 
            strcmp(QueryKeywords, "3.8") == 0 || strcmp(QueryKeywords, "3.9") == 0)
            //else if(is_target_in_table_names(QueryKeywords, table_names))
        {
            if (strcmp(QueryKeywords, "2.1") == 0)
            {
                strcpy(QueryKeywords, "表2.1 对流层大气的主要成分");
                //这里实现表名打印 
                printf("\n%s%s%s\n",
                    GREEN_TEXT, QueryKeywords, RESET_COLOR);

            }
            else if (strcmp(QueryKeywords, "2.3") == 0)
            {
                strcpy(QueryKeywords, "表2.3 Hi和Li的取值");

                //这里实现表名打印    
                printf("\n%s%s%s\n",
                    GREEN_TEXT, QueryKeywords, RESET_COLOR);
            }
            else if (strcmp(QueryKeywords, "2.4") == 0)
            {
                strcpy(QueryKeywords, "表2.4 氧气的48条谱线及a1~a6的取值");

                //这里实现表名打印    
                printf("\n%s%s%s\n",
                    GREEN_TEXT, QueryKeywords, RESET_COLOR);
            }
            else if (strcmp(QueryKeywords, "2.5") == 0)
            {
                strcpy(QueryKeywords, "表2.5 氧气的48条谱线及的b1~b6的取值");

                //这里实现表名打印    
                printf("\n%s%s%s\n",
                    GREEN_TEXT, QueryKeywords, RESET_COLOR);
            }
            else if (strcmp(QueryKeywords, "2.6") == 0)
            {
                strcpy(QueryKeywords, "表2.6 我国主要气候地区ns的年均最大、最小值及年均值");

                //这里实现表名打印    
                printf("\n%s%s%s\n",
                    GREEN_TEXT, QueryKeywords, RESET_COLOR);
            }
            else if (strcmp(QueryKeywords, "2.7") == 0)
            {
                strcpy(QueryKeywords, "表2.7 不同国家的值");

                //这里实现表名打印    
                printf("\n%s%s%s\n",
                    GREEN_TEXT, QueryKeywords, RESET_COLOR);
            }
            else if (strcmp(QueryKeywords, "2.8") == 0)
            {
                strcpy(QueryKeywords, "表2.8 不同国家a、b的值");

                //这里实现表名打印    
                printf("\n%s%s%s\n",
                    GREEN_TEXT, QueryKeywords, RESET_COLOR);
            }
            else if (strcmp(QueryKeywords, "2.9.1") == 0)
            {
                strcpy(QueryKeywords, "表2.9.1 我国部分地区极限频率统计结果");

                //这里实现表名打印    
                printf("\n%s%s%s\n",
                    GREEN_TEXT, QueryKeywords, RESET_COLOR);
            }
            else if (strcmp(QueryKeywords, "2.9.2") == 0)
            {
                strcpy(QueryKeywords, "表2.9.2 我国部分地区临界仰角统计结果");

                //这里实现表名打印    
                printf("\n%s%s%s\n",
                    GREEN_TEXT, QueryKeywords, RESET_COLOR);
            }
            else if (strcmp(QueryKeywords, "2.10") == 0)
            {
                strcpy(QueryKeywords, "表2.10 我国部分地区波导强度百分概率统计结果");

                //这里实现表名打印    
                printf("\n%s%s%s\n",
                    GREEN_TEXT, QueryKeywords, RESET_COLOR);
            }
            else if (strcmp(QueryKeywords, "2.11") == 0)
            {
                strcpy(QueryKeywords, "表2.11 经纬度划分表格");

                //这里实现表名打印    
                printf("\n%s%s%s\n",
                    GREEN_TEXT, QueryKeywords, RESET_COLOR);
            }
            else if (strcmp(QueryKeywords, "3.6") == 0)
            {
                strcpy(QueryKeywords, "表3.6 雨滴粒子半径与雨滴粒子末速度");

                //这里实现表名打印    
                printf("\n%s%s%s\n",
                    GREEN_TEXT, QueryKeywords, RESET_COLOR);
            }
            else if (strcmp(QueryKeywords, "3.7") == 0)
            {
                strcpy(QueryKeywords, "表3.7 我国11个气象站等温层高度的与变化值");

                //这里实现表名打印    
                printf("\n%s%s%s\n",
                    GREEN_TEXT, QueryKeywords, RESET_COLOR);
            }
            else if (strcmp(QueryKeywords, "3.8") == 0)
            {
                strcpy(QueryKeywords, "表3.8 itu-r提供的各雨区雨强度表");

                //这里实现表名打印    
                printf("\n%s%s%s\n",
                    GREEN_TEXT, QueryKeywords, RESET_COLOR);
                    }
            else if (strcmp(QueryKeywords, "3.9") == 0)
            {
                strcpy(QueryKeywords, "表3.9 我国新乡、青岛、广州地区降雨率年时间概率统计结果");

                //这里实现表名打印    
                printf("\n%s%s%s\n",
                    GREEN_TEXT, QueryKeywords, RESET_COLOR);
                    }
            else if (strcmp(QueryKeywords, "3.10") == 0)
            {
                strcpy(QueryKeywords, "表3.10 参数u的值");

                //这里实现表名打印    
                printf("\n%s%s%s\n",
                    GREEN_TEXT, QueryKeywords, RESET_COLOR);
                    }
            else if (strcmp(QueryKeywords, "3.12") == 0)
            {
                strcpy(QueryKeywords, "表3.12 回归参数和中我国不同地区和的取值");

                //这里实现表名打印    
                printf("\n%s%s%s\n",
                    GREEN_TEXT, QueryKeywords, RESET_COLOR);
                    }
            else if (strcmp(QueryKeywords, "3.13") == 0)
            {
                strcpy(QueryKeywords, "表3.13 我国部分大城市十分钟积分时间的降雨率长期累积分布");

                //这里实现表名打印    
                printf("\n%s%s%s\n",
                    GREEN_TEXT, QueryKeywords, RESET_COLOR);
                    }
            else if (strcmp(QueryKeywords, "3.16") == 0)
            {
                strcpy(QueryKeywords, "表3.16 雾的能见度等级表");

                //这里实现表名打印    
                printf("\n%s%s%s\n",
                    GREEN_TEXT, QueryKeywords, RESET_COLOR);
                    }
            else if (strcmp(QueryKeywords, "3.17") == 0)
            {
                strcpy(QueryKeywords, "表3.17 云的国际分类");

                //这里实现表名打印    
                printf("\n%s%s%s\n",
                    GREEN_TEXT, QueryKeywords, RESET_COLOR);
                    }
            else if (strcmp(QueryKeywords, "3.18") == 0)
            {
                strcpy(QueryKeywords, "表3.18 雾滴粒子的尺寸分布");

                //这里实现表名打印    
                printf("\n%s%s%s\n",
                    GREEN_TEXT, QueryKeywords, RESET_COLOR);
                    }
            else if (strcmp(QueryKeywords, "3.20") == 0)
            {
                strcpy(QueryKeywords, "表3.20 雾中含水量（g/m^3）随高度的分布");

                //这里实现表名打印    
                printf("\n%s%s%s\n",
                    GREEN_TEXT, QueryKeywords, RESET_COLOR);
                    }
            else if (strcmp(QueryKeywords, "3.21") == 0)
            {
                strcpy(QueryKeywords, "表3.21 层状云的含水量");

                //这里实现表名打印    
                printf("\n%s%s%s\n",
                    GREEN_TEXT, QueryKeywords, RESET_COLOR);
                    }
            else if (strcmp(QueryKeywords, "3.22") == 0)
            {
                strcpy(QueryKeywords, "表3.22 不同性质的雾的平均高度");

                //这里实现表名打印    
                printf("\n%s%s%s\n",
                    GREEN_TEXT, QueryKeywords, RESET_COLOR);
                    }
            else if (strcmp(QueryKeywords, "3.25") == 0)
            {
                strcpy(QueryKeywords, "表3.25 西安地区云及云底高度");

                //这里实现表名打印    
                printf("\n%s%s%s\n",
                    GREEN_TEXT, QueryKeywords, RESET_COLOR);
                    }
            else if (strcmp(QueryKeywords, "3.26") == 0)
            {
                strcpy(QueryKeywords, "表3.26 几种云雾滴谱广义gamma分布参数");

                //这里实现表名打印    
                printf("\n%s%s%s\n",
                    GREEN_TEXT, QueryKeywords, RESET_COLOR);
                    }
            else if (strcmp(QueryKeywords, "3.29") == 0)
            {
                strcpy(QueryKeywords, "表3.29 各纬度海洋和陆地的年平均云量");

                //这里实现表名打印    
                printf("\n%s%s%s\n",
                    GREEN_TEXT, QueryKeywords, RESET_COLOR);
                    }
            else if (strcmp(QueryKeywords, "3.32") == 0)
            {
                strcpy(QueryKeywords, "表3.32 沙尘暴天气强度划分标准");

                //这里实现表名打印    
                printf("\n%s%s%s\n",
                    GREEN_TEXT, QueryKeywords, RESET_COLOR);
                    }
            else if (strcmp(QueryKeywords, "3.33") == 0)
            {
                strcpy(QueryKeywords, "表3.33 我国部分地区的<inr>和入");

                //这里实现表名打印    
                printf("\n%s%s%s\n",
                    GREEN_TEXT, QueryKeywords, RESET_COLOR);
                    }
            else if (strcmp(QueryKeywords, "3.34") == 0)
            {
                strcpy(QueryKeywords, "表3.34 气溶胶颗粒尺寸范围（只留下半部分参考除尘理论中的内容）");

                //这里实现表名打印    
                printf("\n%s%s%s\n",
                    GREEN_TEXT, QueryKeywords, RESET_COLOR);
                    }
            else if (strcmp(QueryKeywords, "3.35.1") == 0)
            {
                strcpy(QueryKeywords, "表3.35.1 常见气溶胶颗粒密度_固体");

                //这里实现表名打印    
                printf("\n%s%s%s\n",
                    GREEN_TEXT, QueryKeywords, RESET_COLOR);
                    }
            else if (strcmp(QueryKeywords, "3.35.2") == 0)
            {
                strcpy(QueryKeywords, "表3.35.2 常见气溶胶颗粒密度_液体");

                //这里实现表名打印    
                printf("\n%s%s%s\n",
                    GREEN_TEXT, QueryKeywords, RESET_COLOR);
                    }
            else if (strcmp(QueryKeywords, "3.36") == 0)
            {
                strcpy(QueryKeywords, "表3.36 不同能见距离条件下的取值");

                //这里实现表名打印    
                printf("\n%s%s%s\n",
                    GREEN_TEXT, QueryKeywords, RESET_COLOR);
                    }
            else if (strcmp(QueryKeywords, "3.38") == 0)
            {
                strcpy(QueryKeywords, "表3.38 文献[57]给出的水的介电常数测量结果");

                //这里实现表名打印    
                printf("\n%s%s%s\n",
                    GREEN_TEXT, QueryKeywords, RESET_COLOR);
                    }


            //到数据库中查询
            Query(QueryKeywords);

            printf("\n%s%s%s",
                GREEN_TEXT,
                header,
                RESET_COLOR);

        }

        //展示所在目录全部表名查询——制作一个就行
        else if (strcmp(QueryKeywords, "DB") == 0)
        {
            printf("这里是将来的该章节的所有表名\n");

            //这里实现表名打印    
            printf("\n%s%s%s",
                GREEN_TEXT, header, RESET_COLOR);
                    }


        //章节指令
        else if (strcmp(QueryKeywords, "1") == 0 || strcmp(QueryKeywords, "2") == 0 || strcmp(QueryKeywords, "3") == 0 || strcmp(QueryKeywords, "4") == 0 || strcmp(QueryKeywords, "5") == 0 || strcmp(QueryKeywords, "6") == 0 || strcmp(QueryKeywords, "7") == 0 || strcmp(QueryKeywords, "8") == 0 || strcmp(QueryKeywords, "9") == 0)
        {
            //标头语句软编码
            snprintf(header, sizeof(header), "[对流层传播@第%s章~]>>", QueryKeywords);
            printf("%s%s%s", GREEN_TEXT, header, RESET_COLOR);

        }
        else if (strcmp(QueryKeywords, "0") == 0 || strcmp(QueryKeywords, "all") == 0 || strcmp(QueryKeywords, "All") == 0 || strcmp(QueryKeywords, "ALL") == 0)
        {

            //标头语句软编码
            snprintf(header, sizeof(header), "[对流层传播@all~]>>");
            printf("%s%s%s", GREEN_TEXT, header, RESET_COLOR);

        }
        else if (strcmp(QueryKeywords, "help") == 0 || strcmp(QueryKeywords, "h") == 0)
        {
          help_static();
            printf("%s%s%s", GREEN_TEXT, header, RESET_COLOR);
        }
        else if (strcmp(QueryKeywords, "help0") == 0 || strcmp(QueryKeywords, "h0") == 0)
        {
            again_newUser_guide1();
            printf("%s%s%s", GREEN_TEXT, header, RESET_COLOR);
        }
        else if (strcmp(QueryKeywords, "story") == 0 || strcmp(QueryKeywords, "st") == 0)
        {
           story_page(STORY_SLEEP_TIME1, STORY_SLEEP_TIME2, STORY_INTERVAL_NUM_TO_SLEEP);
            printf("%s%s%s", GREEN_TEXT, header, RESET_COLOR);
        }
        else if (strcmp(QueryKeywords, "q") == 0 || strcmp(QueryKeywords, "~") == 0)
        {
            printf("%s您已退出查询%s", GREEN_TEXT, RESET_COLOR);
            exit(1);
        }
        else
        {
            printf("%s%sERROR:\'%s\'属于无效指令，请正确输入(输入h[elp]以获取用户手册)%s\n\n%s%s%s",
                ANSI_COLOR_RED_BACKGROUND,
                ANSI_COLOR_WHITE_FONT,
                QueryKeywords,
                ANSI_COLOR_RESET,

                GREEN_TEXT,
                ARROW,
                RESET_COLOR
                
            );
        }


    } mysql_close(conn);
}
