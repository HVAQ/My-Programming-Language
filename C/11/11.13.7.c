#include <stdio.h>
#include <string.h>
#define SIZE 81
char * string_in(char *, char *);  //方案1，等同于方案2的strstr()函数
char * string_ino(char *, char *); //方案2
int main(void)
{
	char str1[SIZE];
	char str2[SIZE];
	char *ptr;

	puts("请输入一个字符串");
	while(*gets(str1)){
		puts("请再输入一个字符串");
		while(!*gets(str2))
			continue;
		ptr = string_ino(str1, str2);
		if(ptr == NULL)
			printf ("%s 中不存在 %s\n", str1, str2);
		else
			printf ("%s 在 %s 中的存储地址是 %p\n", str2, str1, ptr);
		puts("请继续输入一个字符串");
	}

	return 0;
}
char * string_in(char *s1, char *s2)
{
	int m = strlen(s1);
	int n = strlen(s2);
	int x, y;

	if(m < n)
		return NULL;
	else if(m == n || strcmp(s1, s2) == 0)
		return s1;
	else{
		for (x = 0, y = 0; y < n; x++){
			if(s1[x] == s2[y])
				y++;
			else
				y = 0;
		}
		if (y == n)
			return (s1 + x - n);
		else
			return NULL;
	}
}
char * string_ino(char *s1, char *s2)
{
	return (strstr (s1, s2));
}
