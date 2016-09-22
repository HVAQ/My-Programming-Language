#include <stdlib.h>
#include <stdio.h>

//如果定义了mode，执行
#ifdef Mode
void print_h(void)
{
	printf("world\n");
}
#else //如果没有定义mode，执行
void print_h(void)
{
	printf("hello world\n");
}
#endif

int main(void)
{
	print_h();
	return 0;
}
