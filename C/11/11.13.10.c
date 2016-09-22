#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define LINE 10
#define SIZE 81

void show_mean(void);  //菜单显示选项
void get_mean(char *str[], char *str2[], int);  //获取用户选项
void mean_a(char *str2[], int);  // a 选项
void mean_b(char *str[], int);   // b 选项
void mean_c(char *str[], int);   // c 选项
void mean_d(char *str[], int);   // d 选项
int len(char *);  // 计算每个字符串第一个单词的长度

int main(void)
{
	char ch[LINE][SIZE];
	char *str[LINE];
	char *str2[LINE];
	int n = 0;

	printf("请输入 %d 个字符串\n", LINE);

	while (n < LINE && *gets(ch[n]) != EOF){  //当读取输入遇到文件结尾或者达到10行字符串时，停止读取
		str[n] = str2[n] = ch[n];  //二维数组读取字符串，可理解为“ 字符串中的字符串 ”
		n++;
	}
	show_mean();  // 当程序停止读取输入时，显示菜单
	get_mean(str, str2, n); // 获取用户对菜单的选项，因为要对读取的字符串进行处理，所以同时传递读取的字符串数组
	puts("Done!");

	return 0;
}
void show_mean(void)
{
	puts("########################################################################");
	puts("a) 输出初始字符串列表\t        b) 按ASCII顺序输出字符串");
	puts("c) 按长度递增顺序输出字符串\td) 按字符串中第一个单词的长度输出字符串");
	puts("e) 退出");
	puts("########################################################################");
	puts("\n请选择:");
}
void get_mean(char *str[], char *str2[], int i)
{
	char ch;

	while ((ch = getchar()) != 'e' && ch != 'E')  //当用户选择 e || E 时，执行退出
	{
		ch = tolower (ch); // 将用户输入全部转换为小写字母
		if (ch == '\n')  //当用户输入回车时，重新读取输入，同时，为一次循环后，puts()函数输出的 '\n' 做缓冲
			puts("请重新选择");
		else if (ch < 97 || ch > 100)  // 在ascii中，a ＝ 97，d ＝ 100，当用户输入不属于 a－d 时，要起重现选择
			puts("请输入菜单中的选项");
		else
		{
			switch(ch)
			{
				case 'a':
					mean_a(str2, i);  // 因其他选项会改变字符串数组顺序，因此为a选项传递一个不受影响的str2
					break;
				case 'b':
					mean_b(str, i);
					break;
				case 'c':
					mean_c(str, i);
					break;
				case 'd':
					mean_d(str, i);
					break;
				default:
					printf("出错了\n");  // 预留程序错误报错
			}
		}
	}
}
void mean_a(char *str2[], int i)  // 可作为排序类程序及函数的输出实例，同时为 b、c、d 选项输出提供支持
{
	int x;

	puts("结果:");
	for (x = 0; x < i; x++)
		puts(str2[x]);
}
void mean_b(char *str[], int i)
{
	int m, n;
	char *ch;  // 供数据交换的指针，指向一个字符串
	
	for (m = 0; m < i - 1; m++)      // m 代表的是在字符串数组中的 前 一个元素
		for (n = m + 1; n < i; n++)  // n 代表的是在字符串数组中的 后 一个元素
			if (strcmp (str[m], str[n]) > 0)  // 将前、后两个字符串进行比较，按照 ascii 顺序排列
			{
				ch = str[m];  // 地址上的操作
				str[m] = str[n];
				str[n] = ch;
			}
	mean_a(str, i);  // 由选项 a 的函数提供的输出支持
}
void mean_c(char *str[], int i)
{
	int m, n;
	char *ch;

	for (m = 0; m < i - 1; m++)
		for (n = m + 1; n < i; n++)
			if(strlen(str[m]) > strlen(str[n]))  //将前、后两个字符串的长度进行比较，
			{
				ch = str[m];
				str[m] = str[n];
				str[n] = ch;
			}
	mean_a(str, i);
}
void mean_d(char *str[], int i)
{
	char *ch;
	int m, n;

	for (m = 0; m < i - 1; m++)
		for (n = m + 1; n < i; n++)
			if (len(str[m]) > len(str[n])){  // 将前、后两个字串的首个单词长度进行比较
				ch = str[m];
				str[m] = str[n];
				str[n] = ch;
			}
	mean_a(str, i);
}
int len(char *str)  // 类似 b、c选项的由 string.h 提供支持的 strcmp()函数、strlen()函数
{
	int i;

	for (i = 0; i < strlen(str); i++)
		if (isspace(str[i]))  // 分析字符串参数中的每个字符（故使用 ＊str 来表示）是否为空白字符
			break;  // 当遇到空白字符时，跳出循环

	return i;  //此时的i，代表的就是字符串第一个单词的实际长度
}
