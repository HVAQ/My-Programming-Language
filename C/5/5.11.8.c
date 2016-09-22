#include<stdio.h>
void Te(double Fa);
int main(void)
{
	double h;
	printf("请输入一个华氏温度\n");
	while(scanf("%le",&h)==1){
		//scanf的返回值代表成功输入的数量的数目，非数字不会被成功输入
		Te(h);
		printf("请重新输入一个华氏温度\n");
	}
	printf("bye\n");
	return 0;
}

void Te(double h)
{
	const double Fa = h;
	const double Ce = 1.8 * Fa + 32.0;
	const double Ke = Ce + 273.16;
	printf("%.2le Fahrenheit = %.2le Celsius = %.2le Kelvin\n",Fa,Ce,Ke);
}
