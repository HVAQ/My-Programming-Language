#include<stdio.h>
void larger_of(double *a,double *b);

int main(void)
{
	double x,y;

	printf("请输入两个不同的数\n");
	while(scanf("%lf %lf",&x,&y)!=2||x==y){
		while(getchar()!='\n')
			continue;
		printf("请输入两个不同的数\n");
	}
	larger_of(&x,&y);
	printf("现在x,y是%f和%f\n",x,y);
	return 0;
}

void larger_of(double *a,double * b)
{
	double temp;

	if(*a>*b){
		temp=*b;
		*b=*a;
	}
	else{
		temp=*a;
		*a=*b;
	}
}
