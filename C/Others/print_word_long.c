#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define IN 1
#define OUT 0
#define MAX_TIME 99     /* 单词长度最大频率数 */

int main()
{
    char word;
    int lenword[MAX_TIME][2];   /* 定义单词长度存储数组，MAX_TIME[0]用于存储长度，MAX_TIME[1]存储次数*/
    int word_len, str_time, in_or_out == OUT;

    /* 单词长度，该长度下出现的次数，数组计数*/
    word_len = str_time = 0;

    for (int index = 0; index < MAX_TIME; index++)
        for (int count = 0; count < 2; count++)
        /* 初始化数组 */
        lenword[index][count] = 0;

    while ((word = getchar()) != EOF)
    {
        if (isspace(word) && str_time < MAX_TIME && in_or_out == IN)
        {
            in_or_out = OUT;
            lenword[str_time][0] = word_len;
            lenword[str_time][1] += 1;
            str_time++;
        }
        else if (str_time == MAX_TIME)
        {
            fprintf(stderr, "错误: 文本单词次数频度过高!");
            exit(1)
        }
        else
        {
            /* 非空白字符时，在当前所在单词长度上增加1 */
            word_len++;
            in_or_out = IN;
        }
    }
    
    if (in_or_out == IN)
        lenword[str_time][1] += 1;

    for (int index = 0; index < MAX_TIME; index++)
    {
        /* 打印水平直方图 */
        if (lenword[index] != 0)
        {
            printf("Word long is %2d: ", index);
            for (int count = 0; count < lenword[index]; count++)
                printf("#");
            printf("\n");
        }
    }

    return 0;
}
