#include<stdio.h>
int main(void)
{
	char ch;
	int a_ct,e_ct,i_ct,o_ct,u_ct;

	a_ct = e_ct = i_ct = o_ct = u_ct = 0;

	printf("请输入,以开始计数。按＃退出\n");
	while((ch=getchar())!='#')
	{
		switch(ch)
		{
			case 'a':
			case 'A':
				a_ct++;
				break;
			case 'e':
			case 'E':
				e_ct++;
				break;
			case 'i':
			case 'I':
				i_ct++;
				break;
			case 'o':
			case 'O':
				o_ct++;
				break;
			case 'u':
			case 'U':
				u_ct++;
				break;
			default:
				break;
		}
	}
	printf("名称: a e i o u\n");
	printf("    %4d %4d %4d %4d %4d\n",a_ct,e_ct,i_ct,o_ct,u_ct);
	return 0;
}
