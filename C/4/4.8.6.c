#include<stdio.h>
#include<float.h>
int main(void)
{
	float a=1.0/3.0;
	double b=1.0/3.0;

	printf("float最少有效数字位数\n%d\n",FLT_DIG);
	printf("double最少有效数字位数\n%d\n",DBL_DIG);

	printf("%.4f %.12f %.16f\n",a,a,a);
	printf("%.4lf %.12lf %.16lf\n",b,b,b);
	printf("FIT_DIG下%.6f\n",a);
	printf("DBL_DIG下%.15lf\n",b);
	return 0;
}
