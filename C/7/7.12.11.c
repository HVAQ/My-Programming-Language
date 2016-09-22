#include<stdio.h>
#include<ctype.h>
#define CX 1.25
#define LB 0.89
#define TC 0.65
#define B_O 5
#define B_T 20
#define BJ_O 3.5
#define BJ_T 10
#define BJ_H 8
#define BJ_F 0.1
#define ZK_Z 100
#define ZK_L 0.05
void xh(void);
float dg(void);

int main(void)
{
	char ch;
	float azl,bzl,czl,zj,zz,zk,yf,zj_z,zl;

	azl=bzl=czl=zj=zz=zk=yf=zl=0;
	xh();
	printf("         请进行选购\n  名  称\t单价(美元/磅)\na)朝鲜蓟\t1.25\nb)甜  菜\t0.65\nc)胡萝卜\t0.89\nq)退  出\n");
	xh();
	printf("请选购\n");
	while((ch=getchar())!='q'&&ch!='Q'){
		ch=tolower(ch);
		if(ch>='a'&&ch<='c'){
				switch(ch){
					case 'a':{
								 zl=dg();
							     azl+=zl;
						     }
							 break;
				    case 'b':{
							     zl=dg();
							     bzl+=zl;
						     }
						     break;
				    default:{
							    zl=dg();
							    czl+=zl;
						    }
				}
			}
			else if('\n'==ch){
				printf("请继续选购\n");
				continue;
			}
			else
				printf("请在a-c中任选一项,或按q退出\n");
		}
	zj=azl*CX+bzl*TC+czl*LB;
	zz=azl+bzl+czl;

	if(zj>=ZK_Z)
		zk=zj*ZK_L;

	if(zz>0){
		if(zz<=B_O)
			yf=BJ_O;
		else if(zz<=B_T)
			yf=BJ_T;
		else
			yf=BJ_H+(zz-B_T)*BJ_F;
	}

	zj_z=zj+yf-zk;
	printf("您订购了:\n\t朝鲜蓟 %g 磅(%g美元/磅)\n\t甜  菜 %g 磅(%g美元/磅)\n\t胡萝卜 %g 磅(%g美元/磅)\n应    付:\n\t朝鲜蓟  %g 美元\n\t甜  菜  %g 美元\n\t胡萝卜  %g 美元\n总    共:\t%g 美元\n折    扣:\t%g 美元\n运    费:\t%g 美元\n实际应付:\t%g 美元\n",azl,CX,bzl,TC,czl,LB,azl*CX,bzl*TC,czl*LB,zj,zk,yf,zj_z);
	return 0;
}
void xh(void)
{
	int i;
	for(i=0;i<29;i++)
		printf("*");
	printf("\n");
}
float dg(void)
{
	float yzl;
	printf("请输入您要购买的重量\n");
	scanf("%f",&yzl);	
	return yzl;
}
