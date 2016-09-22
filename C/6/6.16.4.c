#include<stdio.h>
int main(void)
{
	int i,x,y,z;
	char ch,ch_one,ch_two,ch_thr;
	printf("请输入一个大写字母\n");
	scanf("%c",&ch);
	ch_one = ch - 65; //输入字母与A之间的差值，即所打印行数－1
	for(y = 0;y <= ch_one;y++){ //y初始值为0，保证至少打印一行；随着输入字母ASCII码值的增大，y增加，行数增多
		for(x = y;x < ch_one;x++)
			printf("%c",(char)32); //打印空格，首行A前空格数为总行数－1，其他行递减
		for(i = 0;i <= y;i++){ //i初始值为0，保证至少打印一行,正向每行打印字母始终与行数相等
			ch_two='A' + i; //第一行打印A一个字母，其他行字母数随着i的增加而增加，增加值为行数增加数，即i的增加数
			printf("%c",ch_two);
		} //正向打印，随着行数的增加，字母增加，字母数等于行数
		for(z = 1;z <= y;z++){
			ch_thr = 'A' + y - z; //第一行不打印，第二行打印一个A,其他行数增加字母数为行数－1，为z的增加数
			printf("%c",ch_thr);
		} //反向打印，随着行数的增加，字母数增加数等于行数－1
		printf("\n");
	}
	return 0;
}
