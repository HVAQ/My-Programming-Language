#include <stdio.h>

char * rotate (unsigned int, int, char *);

int main (void)
{
	unsigned int val;
	int places;
	char num[8 * sizeof(int)];

	// get number
	puts ("请输入一个无符号整数.");
	while (scanf ("%u", &val) != 1)
	{
		while (getchar() != '\n')
			continue;
		puts ("请输入一个无符号整数.");
	}
	// get 左旋数
	puts ("请输入要左旋的位数.");
	while (scanf ("%d", &places) != 1)
	{
		while (getchar() != '\n')
			continue;
		puts ("请输入一个整数值.");
	}
	rotate (val, places, num);
	printf ("%u左旋%d位后, 二进制表示为%s.\n", val, places, num);

	return 0;
}

char * rotate (unsigned int m, int n, char * num)
{
	unsigned int overflow, nuo;
	int i, size = 8 * sizeof(int);

	// 使左移位数保持为一个有效的值
	n %= size;
	// 将坐移位会丢掉的位保存下来
	// 左移位m, 并对其与保存的位做与或运算
	overflow = m >> (size - n);
	nuo = (m << n) | overflow;
	// 读取二进制位
	for (i = size - 1; i >= 0; i--, nuo >>= 1)
		num[i] = (01 & nuo) + '0';
	num[size] = '\0';

	return num;
}
