#include<stdio.h>
#include<ctype.h>

int main(void)
{
	int ch;
	int num=0;
	int i=1;
	float pj;

	while((ch=getchar())!=EOF)
	{
		if(isspace(ch)||ispunct(ch)){
			if(num>0){
				++i; //当字符数不为0，遇到第一个空白字符或标点符号，单词数＋1
				while((ch=getchar())!=EOF){ //继续读数，知道下一个字符不为空白字符或标点时，字符数＋1
					if(isspace(ch)||ispunct(ch))
						continue;
					else{
						++num;
						break;
					}
				}
			}
		}
		else
			++num;
	}
	pj=(float)num/(float)(i-1);
	printf("每个单词的平均字母数为%g\n",pj);
	return 0;
}
