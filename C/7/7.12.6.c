#include<stdio.h>
int main(void)
{
	char ch1,ch2;
	int m=0;
	while((ch1=getchar())!='#')
	{
		while(ch1=='e')
		{
			while((ch2=getchar())=='e')
				continue;
			if(ch2=='#')
				goto late1;
			if(ch2=='i'){
				m++;
				ch1=ch2;
			}
			else
				ch1=ch2; 
		}
	}
late1:printf("序列ei出现%d次\n",m);
	return 0;
}
