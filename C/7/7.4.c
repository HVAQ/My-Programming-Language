#include<stdio.h>
#define fj_one 360
#define fj_two 680
#define jg_one 0.12589
#define jg_two 0.17901
#define jg_thr 0.20971
#define zj_one (fj_one*jg_one)
#define zj_two (fj_two*jg_two)
int main(void)
{
	double a,b;
	printf("请输入您的用电度数\n");
	scanf("%lf",&a);
	if(a<=fj_one)
		b=a*jg_one;
	else if(a<=fj_two)
		b=zj_one+(a-fj_one)*jg_two;
	else
		b=zj_two+(a-fj_two)*jg_thr;
	printf("您当月用电%g度，应交电费为%g\n",a,b);
	return 0;
}
