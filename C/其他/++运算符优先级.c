//++运算符优先级
#include<stdio.h>
int main(void)
{
	int x,y,i1,i2;
	x = 2;
	y = 3;
	i1 = (x + 5) * y++;
	i2 = (x + 5) * ++y;

	printf("x = 2\ny = 3\ni1 = (x + 5) * y++\ni2 = (x + 5) * ++y\n");
	printf("i1为后缀增量运算符，i2为前缀\n");
	printf("i1 = %d\n",i1);
	printf("i2 = %d\n",i2);
	return 0;
}
