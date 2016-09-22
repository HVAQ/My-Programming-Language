#include<stdio.h>
int main(void)
{
	int i,x;
	char ch[6];
	for(i=0;i<=5;i++){
		for(x=0;x<=i;x++){
			ch[x]='F'-x;
			printf("%c",ch[x]);
		}
		printf("\n");
	}
	return 0;
}
