#include<stdio.h>
void chiline(char,int,int);

int main(void)
{
	char ch;
	int x,y,z;

	printf("请输入一个字符\n");
	ch=getchar();
	while(getchar()!='\n')
		continue;
	printf("请输入两个整数\n");
	while(scanf("%d %d",&x,&y)!=2){
		while(getchar()!='\n')
			continue;
		printf("请输入两个整数\n");
	}
	z=x>y?x:y;
	x=x<y?x:y;
	chiline(ch,x,z);
	return 0;
}

void chiline(char ch,int x,int y)
{
	int i;

	for(i=1;i<x;++i)
		putchar(' ');
	for(;i<=y;++i)
		putchar(ch);
	putchar('\n');
}
