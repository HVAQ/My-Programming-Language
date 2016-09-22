#include<stdio.h>
int main(void)
{
	char ch;
	int n_ch,s_ch,o_ch;
	
	n_ch=s_ch=o_ch=0;
	printf("请输入\n");
	while((ch=getchar())!='#')
	{
		switch(ch)
		{
			case '\n':
				n_ch++;
				break;
			case ' ':
				s_ch++;
				break;
			default:
				o_ch++;
		}
	}
	printf("输入的字符中\n空格%d个\n换行符%d个\n其他符号%d个\n",s_ch,n_ch,o_ch);
	return 0;
}
