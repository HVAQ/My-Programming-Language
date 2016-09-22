#include<stdio.h>
void fo(void);
void wh(void);
int main(void)
{
	fo();
	fo();
	fo();
	wh();

	return 0;
}

void fo(void)
{
	printf("For he's a jolly good fellow!\n");
}

void wh(void)
{
	printf("Which nobody can deny!\n");
}
