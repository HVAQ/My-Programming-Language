#include <stdio.h>
//  测试外部链接
int i = 10;
int main (void)
{
	extern int i;

	printf("i = %d\n", i);

	return 0;
}
