#include <stdio.h>
#include <string.h>
#define SIZE 81
#define SP ' '
void get_input(char s1[]);
int main(void)
{
	char str[SIZE];
	
	puts("请输入一个字符串");
	while (*gets(str)){
		get_input(str);
		puts("请输入一个字符串");
	}
	puts("Done!");

	return 0;
}
void get_input(char s1[])
{
	int x;
	int y = 0;
	char s2[strlen(s1)];

	for (x = 0; x < strlen(s1); x++)
		if (s1[x] != SP){
			s2[y] = s1[x];
			y++;
		}
	s2[y] = '\0';
	puts(s2);
}
