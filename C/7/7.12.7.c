#include<stdio.h>
#define JB 10
#define JIB 1.5
#define TM_O 40
#define GZ_O 300
#define GZ_T 450
#define SL_O 0.15
#define SL_W 0.2
#define SL_H 0.25
int main(void)
{
	int time,zgz,sl;
	printf("请输入一周工作的时间\n");
	while((scanf("%d",&time))==1){
		if(time<=TM_O){
			zgz=time*JB;
			if(zgz<=GZ_O)
				sl=zgz*SL_O;
			else
				sl=GZ_O*SL_O+(zgz-GZ_O)*SL_W;
		}
		else{
			zgz=TM_O*JB+(time-TM_O)*JB*JIB;
			if(zgz<=GZ_T)
				sl=GZ_O*SL_O+(zgz-GZ_O)*SL_W;
			else
				sl=GZ_O*SL_O+(GZ_T-GZ_O)*SL_W+(zgz-GZ_T)*SL_H;
		}
		printf("总工资%d，税率%d，净工资%d\n",zgz,sl,zgz-sl);
		printf("请继续输入\n");
	}
	return 0;
}
