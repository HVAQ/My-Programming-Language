#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>  // 包含 atoi() 函数
#define MAXDAY 31
#define MAXMON 12

struct info {
	int days;
	char months[10];  // 嵌套联合
	int years;
};  // 用户输入的结构模版

struct month {
	char name[10];
	int days;
	int yname;
};

struct month months[MAXMON] = {
	{"January", 31, 1},
	{"February", 28, 2},
	{"March", 31, 3},
	{"April", 30, 4},
	{"May", 31, 5},
	{"June", 30, 6},
	{"July", 31, 7},
	{"August", 31, 8},
	{"September", 30, 9},
	{"October", 30, 10},
	{"November", 31, 11},
	{"December", 30, 12},
};

int set_mon (struct info *);  // 测试输入
void show_info (const struct info *, int);  // 显示结果
void eatline (void);

int main (void)
{
	struct info get;
	int mon;
	
	puts ("请输入日期.");
	while (scanf ("%d", &get.days) != 1 || get.days > MAXDAY)
	{
		eatline();
		puts ("日期输入有误, 请重新输入.");
	}
	eatline();
	puts ("请输入月份.");
	while (gets (get.months) == NULL || get.months[0] == '\0')
		puts ("月份输入有误, 请重新输入.");
	puts ("请按数字格式输入年份.");
	while (scanf ("%d", &get.years) != 1)
	{
		eatline();
		puts ("年份输入有误, 请重新输入.");
	}
	if ((mon = set_mon (&get)) == 0)
		puts ("没有找到您的输入的日期.");
	else
		show_info (&get, mon);
	
	return 0;
}

void eatline (void)
{
	while (getchar() != '\n')
		continue;
}

int  set_mon (struct info * get)
{
	int i, mon, m;
	int n = 0;
	// 测试用户输入的是数字还是字符串
	for (i = 0; get -> months[i] != '\0'; i++)
		if (isalnum (get -> months[i]) && !isalpha (get -> months[i]))
			n = 1;  // 用户如果输入月份全部为阿拉伯数字, n = 1
		else
		{
			n = 0;
			break;
		}  // 否则, n = 0
	// 检查输入月份是否能与结构中月份匹配
	if (n == 1)  // 如果是数字
	{
		mon = atoi (get -> months);  // 将字符转换为数字
		if (mon < 1 || mon > MAXMON)
			return 0;  // 如果输入月份不在1 - 12的范围内, 返回0
	}
	else
	{  // 如果输入的不是数字
		get -> months[0] = toupper (get -> months[0]);  // 将输入的字符串首字母转换为大写
		for (i = 1; i < m; i++)
			get -> months[i] = tolower (get -> months[i]);  // 将剩余的字符串转换为小写
		m = strlen (get -> months);  // 计算输入的字符串的长度
		for (i = 0; i < MAXMON; i++)
			if (strncmp (get -> months, months[i].name, m) == 0)  // 测试输入的字符串与结构中月份名是否相同.
			{
				mon = i + 1;  // 如果相同, 计算实际月份
				break;
			}
		if (i == MAXMON)  // 如果到达最大循环次数
			return 0;  // 返回0
	}
	// 下部分测试输入日期数是否与月份最大天数匹配
	if (mon == 4 || mon == 6 || mon == 9 || mon == 11)
	{
		if (get -> days >= MAXDAY)
			return 0;  // 如果月份号是4、6、9、11, 则天数不能超过30天
	}
	else if (mon == 2)
	{
		if (get -> years % 4 == 0)
		{
			if (get -> days > 29)	// 如果是闰年, 二月份天数不能超过29天
				return 0;
		}
		else
			if (get -> days > 28)   // 如果是平年, 二月份天数不能超过28天
				return 0;
	}
	else
		if (get -> days > MAXDAY)  // 否则天数不能超过31天
			return 0;
	
	return mon;  // 返回输入的月份
}

void show_info (const struct info * get, int mon)
{
	int total = 0;

	if (mon == 1)  // 如果为1月份
		total += get -> days;  // 总天数为用户输入的日期
	else
	{
		for (int i = 0; i < mon - 1; i++)
			total += months[i].days;  // 部分总天数为用户输入月份前的所有天数之和
		total += get -> days;  // 加用户输入日期
		if (mon >2 && get -> years % 4 == 0)  // 如果输入月份大于2, 且为闰年
			total += 1; // 总天数加1 (2月份多1天)
	}
	printf ("%d年%d月%d日是一年中的%d天.\n", get -> years, mon, get -> days, total);
}
