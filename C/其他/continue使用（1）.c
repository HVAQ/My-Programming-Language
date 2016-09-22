#include<stdio.h>
//continue的使用
int main(void)
{
	int i;
	for(i=0;i<10;i++){
		if(i==3)
			continue;
		printf("%d\n",i);
	}
	return 0;
}
