#include<stdio.h>
#include<string.h>
int main(void)
{
	int x,z;
	char word[40];
	printf("请输入一个单词\n");
	scanf("%s",word);
	x=strlen(word)-1;
	for(z=x;z>=0;z--)
		printf("%c",word[z]);
	printf("\n");
	return 0;
}
