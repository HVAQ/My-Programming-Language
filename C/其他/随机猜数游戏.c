//一个利用随机种子的猜数程序
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main (void)
{
	int num, i;
	int count = 1;

	srand ((unsigned int) time(0));
	i = rand() % 100;
	printf ("请输入一个小于100的数字.\n");
	while (scanf ("%d", &num) == 1) {
		if (num > i){
			printf ("猜大了,");
			++count;
		}
		else if (num < i){
			printf ("猜小了,");
			++count;
		}
		else{
			puts ("恭喜您,猜对了!");
			printf ("本次您共猜了 %d 次\n", count);
			i = rand() % 100;
			count = 1;
		}
		printf ("再来一次吧!\n");
	}
	puts("再见!\n");

	return 0;
}
