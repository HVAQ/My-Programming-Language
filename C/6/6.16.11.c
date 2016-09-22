#include<stdio.h>
int main(void)
{
	int n,s;
	float q,p,i,y,x,m,z;
	printf("请输入序列停止循环的次数:");
	s=scanf("%d",&n);
	while(s==1&&n>0){
		for(x=0,i=1.0;i<=n;i++){
			x=x+1.0/i;
		}
		printf("循环%d次\n++ = %f\n",n,x);
		y=n%2; //获取n的奇偶
		while(y==0){ //此时n为偶数
			for(m=0,i=1.0;i<=n;i=i+2.0){
				q=i+1.0;
				m=(1.0/i-1.0/q)+m;
			}
			printf("+- = %f\n",m);
			y=y+2;
		}
		while(y==1){ //此时n为!=1的奇数
			for(m=0,i=2.0;i<=n;i=i+2.0){
				p=i+1.0;
				m=(1.0/p-1.0/i)+m;
			}
			z=m+1.0;
			printf("+- = %f\n",z);
			y=y+2;
		}
		while(y==1/2){ //此时n为1
			printf("+- = 1\n");
		}
		y=y+2;
		printf("请输入序列停止循环的次数:");
		s=scanf("%d",&n);
	}
	return 0;
}
