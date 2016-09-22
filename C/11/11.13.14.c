#include <stdio.h>
#include <string.h>
#include <ctype.h>
int atoi (char *);
int pf (int, int);

int main (int argc, char *argv[])
{
	int n;

	if (argc < 2)
		puts("缺少参数");
	else
		for (n = 1; n < argc; n++)
			printf("输入数字是 %d: %d\n", n, atoi(argv[n]));  // 所需转换参数在 argv[n] 中, n >= 1

	return 0;
}
int atoi (char *argv)
{
	int  i, x, y;
	int m = strlen(argv);

	x = y = 0;
	while (y < m)  // 测试参数中是否有除阿拉伯数字外的字符
		if (!isdigit(argv[y]))
			break;
		else
			y++;
	if(y == m)  // 当参数中均为阿拉伯字符时，进行计算
		for (i = 0; i < m; i++)
			x += ((argv[i] - 48) * pf(i, m));  // '0' 的 ascii 码值为48
	
	return x; // 返回 0 或输入参数的数字形式
}
int pf (int i, int m)  //获取位数，并转换为10进制数
{
	int y = 1;
	int n;

	for(n = 1; n < m - i; n++)  // 根据参数位数及字符存在位置计算
		y *= 10;

	return y;
}
