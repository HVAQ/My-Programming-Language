#include<stdio.h>
#define DS 17850
#define HZ 23900
#define GY 29750
#define LY 14875
#define SL_O 0.15
#define SL_T 0.28
void xh(void);
float sr(void);
float sj(char ch,float csr);

int main(void)
{
	char ch;
	float csr,csj;
	
	while(1){
		xh();
		printf("请您选择税金种类\n");
		printf("1)单身\t2)户主\n3)共有\t4)离异\n5)退出\n");
		xh();
		printf("\n");
		while((ch=getchar())!='5')
		{
			if(ch>'0'&&ch<'5'){
				switch(ch){
					case '1':{
								 csr=sr();
								 csj=sj(ch,csr);
							 }
							 break;
					case '2':{
								 csr=sr();
								 csj=sj(ch,csr);
							 }
							 break;
					case '3':{
								 csr=sr();
								 csj=sj(ch,csr);
							 }
							 break;
					default:{
								csr=sr();
								csj=sj(ch,csr);
							}
				}
				printf("您应征税收入为%g,应缴税为%g\n\n",csr,csj);
			}
			else if('\n'==ch)
				break;
			else
				printf("请选择1-5内的选项\n\n");
		}
		if(ch=='5')
			break;
	}
	printf("Bye!\n");
	return 0;
}
void xh(void)
{
	int i;
	for(i=0;i<16;i++)
		printf("*");
	printf("\n");
}
float sr(void)
{
	float yzsr;
	printf("请输入应征税收入\n");
	scanf("%f",&yzsr);
	return yzsr;
}
float sj(char ch,float sr)
{
	float yjs;

	if(ch=='1'&&sr>DS)
		yjs=DS*SL_O+(sr-DS)*SL_T;
	else if(ch=='2'&&sr>HZ)
		yjs=HZ*SL_O+(sr-HZ)*SL_T;
	else if(ch=='3'&&sr>GY)
		yjs=GY*SL_O+(sr-GY)*SL_T;
	else if(ch=='4'&&sr>LY)
		yjs=LY*SL_O+(sr-LY)*SL_T;
	else
		yjs=sr*SL_O;
	return yjs;
}
