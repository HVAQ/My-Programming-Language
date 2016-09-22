#include<stdio.h>
//continue的使用3
int main(void)
{
	int i;
	for(i=0;i<10;i++){
		if(i==3)
			continue;
		printf("%d\n",i);
	}
	printf("%d\n",i);
	return 0;
}
