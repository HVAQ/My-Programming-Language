#include<stdio.h>
#define SIZE 26
int main(void)
{
	int i;
	char ch[SIZE];
	for(i=0;i<=SIZE;i++)
		ch[i]='a'+i;
	for(i=0;i<SIZE;i++)
		printf("%2c",ch[i]);
	printf("\n");
	return 0;
}
