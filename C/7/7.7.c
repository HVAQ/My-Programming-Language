#include<stdio.h>
#include<ctype.h>
#include<stdbool.h>
#define STOP '|'
int main(void)
{
	char c;
	char prev;//前一个读入字符
	long n_chars=0L;//字符数
	int n_lines=0;//行数
	int n_words=0;//单词数
	int p_lines=0;//不完整行数
	bool inword=false;//如果c在一个单词中，则intword等于true

	printf("请输入英文文本，按｜终止:\n");
	prev='\n';
	while((c=getchar())!=STOP){
		n_chars++;
		if(c=='\n')//当输入字符为\n时
			n_lines++;//行数增加
		if(!isspace(c)&&!inword){//当输入的字符不是空白字符，且在一个单词中
			inword=true;
			n_words++;
		}
		if(isspace(c)&&inword)//当输入的字符是一个空白字符，不在一个单词中
			inword=false;//到达单词的尾部
		prev=c;
	}

	if(prev!='\n')
		p_lines=1;
	printf("字符数%ld,行数%d,单词数%d,不完整行数%d\n",n_chars,n_lines,n_words,p_lines);
	return 0;
}
