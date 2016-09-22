#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	int i;
	i=system("./a");
	printf("i=%d\n",i/0x100);
	return 0;
}
