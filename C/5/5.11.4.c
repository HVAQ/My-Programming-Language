#include<stdio.h>
#define ZH 30.48 //1ft=30.48cm
int main(void)
{
	float feet,cm,inches;
	printf("Enter a height in centimeters: ");
	scanf("%f",&cm);
	while(cm>0){
		feet=cm/ZH;
		inches=cm-ZH*(int)feet;
		printf("%.1f cm = %d feet, %.1f inches\n",cm,(int)feet,inches);
		printf("Enter a height in centimeters (<=0 to quite): ");
		scanf("%f",&cm);
	}
	printf("bye\n");
	return 0;
}
