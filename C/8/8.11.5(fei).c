#include<stdio.h>
#include<ctype.h>
char get_in(void);
void yn(int num);
int bs(int num);
int num_b(int num);
int num_s(int num);

int main(void)
{
	int num_o=0;
	int num_t=100;
	int num=50;
	char ch_h;
	int m;

	num_o=num_t;
	printf("想象一个1到100之内的整数,我去猜！按#退出\n");
	printf("输入y表示猜对了,输入n表示猜错了\n");
	printf("输入s表示猜小了,输入b表示猜大了\n");
	printf("你的数字是%d吗?\n",num);
	while((ch_h=get_in())!='#')
	{
		if(ch_h!='y')
		{
			if(ch_h=='n'){
				bs(num);
				if((m=bs(num))==0)
					break;
			}
			else
				printf("我只能识别y、n哦\n");
		}
		else
			printf("我知道我可以的\n");
	}
	printf("Bye!\n");
	return 0;
}
char get_in(void)
{
	char ch;

	ch=getchar();
	while((getchar())!='\n')
		continue;
	ch=tolower(ch);
	return ch;
}
void yn(int num)
{
	char ch_o;

	printf("是%d吗?\n",num);
	while((ch_o=get_in())!='#')
	{
		if(ch_o!='y'){
			if(ch_o=='n')
				bs(num);
			else
				printf("我只能识别y、n哦\n");
		}
	}
}
int bs(int num)
{
	char ch_t;
	int i=0;

	printf("我猜大了还是猜小了?\n");
	while((ch_t=get_in())!='#'){
		if(ch_t=='b'||ch_t=='s')
		{
			switch(ch_t)
			{
				case 'b':{
							 num=num_b(num);
							 yn(num);
							 break;
						 }
				default:{
							num=num_s(num);
							yn(num);
						}
			}
		}
		else
			printf("我现在只能识别b、s哦\n");
	}
	if(ch_t=='#')
		i=1;
	return i;
}
int num_b(int num)
{
	if(num>50)
		num=(num+num)/2;
	else
		num=(num+num_o)/2;
	return num;
}
int num_s(int num)
{
	num=(num+num_t)/2;
	return num;
}
