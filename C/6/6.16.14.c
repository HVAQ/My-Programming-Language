#include<stdio.h>
#include<string.h>
#define SIZE 255
#define STWO 20
int main(void)
{
	char ch[SIZE];
	int i,x;
	printf("请输入字符\n");
	for(i=0;i<STWO;i++)
		scanf("%c",&ch[i]);
	for(x=STWO-1;x>=0;x--)
		printf("%c",ch[x]);
	printf("\n");
	return 0;
}
