#include<stdio.h>
int main(void)
{
	char ch='$';
	int i,x;
	for(i=1;i<=5;i++){
		for(x=1;x<=i;x++)
			printf("%c",ch);
		printf("\n");
	}
	return 0;
}


