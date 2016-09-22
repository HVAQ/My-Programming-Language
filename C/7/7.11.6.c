#include<stdio.h>
//回忆i++与++i的优先级顺序
int main(void)
{
	int i = 0;
	while(i < 3){
		switch(++i){
			case 0:printf("fat ");
			case 1:printf("hat ");
			case 2:printf("cat ");
			default:printf("Oh no! ");
		}
		putchar('\n');
	}
	return 0;
}
