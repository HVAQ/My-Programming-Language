#include<stdio.h>
int main(void)
{
	int ch;
	int i=0;

	while((ch=getchar())!=EOF)
		++i;
	printf("\n从输入到文件结尾为止,字符数有%d\n",i);
	return 0;
}
