#include<stdio.h>
void mean(void)
{
	printf("Enter the operation of your chioce:\n");
	printf("a.add\ts.subtract\nm.multiply\td.divide\nq.quit\n");
}
float get_n(float n,char other)
{

	return n;
}
int main(void)
{
	char ch,other;
	float m,n;

	mean();
	while((ch=getchar())!='q')
	{
		if(ch=='\n')
			continue;
		if(ch!='a'&&ch!='s'&&ch!='m'&&ch!='d'){
			printf("请输入菜单中的选项\n");
			continue;
		}
		else{
			printf("Enter first number:");
			while(scanf("%f",&m)!=1){
				while((other=getchar())!='\n')
					putchar(other);
				printf(" is not an number\n");
				printf("Please enter a number,such as 2.5,-1.78E8,or 3:");
			}
			printf("Enter second number:");
			while(scanf("%f",&n)!=1){
				while((other=getchar())!='\n')
					putchar(other);
				printf(" is not an number\n");
				printf("Please enter a number,such as 2.5,-1.78E8,or 3:");
			}
			if(ch=='d'&&n==0){
				printf("Enter a number other than 0:");
				while(scanf("%f",&n)!=1){
					while((other=getchar())!='\n')
						putchar(other);
					printf(" is not an number\n");
					printf("Please enter a number,such as 2.5,-1.78E8,or 3:");
				}
			}
			switch(ch)
			{
				case 'a':printf("%g+%g=%g\n",m,n,m+n);break;
				case 's':printf("%g-%g=%g\n",m,n,m-n);break;
				case 'm':printf("%g*%g=%g\n",m,n,m*n);break;
				default:printf("%g/%g=%g\n",m,n,m/n);
			}
		}
		mean();
	}
	printf("Bye\n");
	return 0;
}
