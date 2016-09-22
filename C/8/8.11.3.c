#include<stdio.h>
#include<ctype.h>
int main(void)
{
	char ch;
	int sm,bg;

	sm=bg=0;
	while((ch=getchar())!=EOF){
		if(islower(ch))
			++sm;
		else if(isupper(ch))
			++bg;
		else
			continue;
	}
	printf("有大写字母%d个,小写字母%d个\n",bg,sm);
	return 0;
}
