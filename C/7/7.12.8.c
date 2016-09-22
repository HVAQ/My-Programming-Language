#include<stdio.h>
#define J_O 8.75
#define J_T 9.33
#define J_H 10.00
#define J_F 11.20
#define JB 1.5
#define T_O 40
#define GZ_O 300
#define GZ_T 450
#define SL_O 0.15
#define SL_T 0.2
#define SL_H 0.25
float gz_z(char m,float time);
float s_l(float zgz);
void xh(void);
float tm(void);
int main(void)
{
	float time,zgz,sl;
	char m;

	zgz=sl=0;
	xh();
	printf("Enter the number corresponding to the desired pay rate or action:\n");
	printf("1)$%g/hr\t2)$%g/hr\n",J_O,J_T);
	printf("3)$%g/hr\t4)$%g/hr\n5)quit\n",J_H,J_F);
	xh();
	while((m=getchar())!='5')
	{
		if(m>'0'&&m<'5'){
			switch(m)
			{
				case '1':{
							 time=tm();
							 zgz=gz_z(m,time);
							 sl=s_l(zgz);
						 }
						 break;
				case '2':{
							 time=tm();
							 zgz=gz_z(m,time);
							 sl=s_l(zgz);
						 }
						 break;
				case '3':{
							 time=tm();
							 zgz=gz_z(m,time);
							 sl=s_l(zgz);
						 }
						 break;
				default:{
							 time=tm();
							 zgz=gz_z(m,time);
							 sl=s_l(zgz);
						 }
			}
			break;
		}
		else if(m=='\n')
			continue;
		else{
			printf("请输入1-5内的整数\n");
			continue;
		}
	}
	printf("总工资%g,税率%g,净工资%g\n",zgz,sl,zgz-sl);
	return 0;
}
float tm(void)
{
	float tm;
	printf("请输入一周的工作时间\n");
	scanf("%f",&tm);
	return tm;
}
void xh(void)
{
	int i;
	for(i=0;i<65;i++)
		printf("*");
	printf("\n");
}
float gz_z(char m,float time)
{
	float gz_z;
	if(m=='1'){
		if(time<=T_O)
			gz_z=time*J_O;
		else
			gz_z=T_O*J_O+(time-T_O)*J_O*JB;
	}
	else if(m=='2'){
		if(time<=T_O)
			gz_z=time*J_T;
		else
			gz_z=T_O*J_T+(time-T_O)*J_T*JB;
	}
	else if(m=='3'){
		if(time<=T_O)
			gz_z=time*J_H;
		else
			gz_z=T_O*J_H+(time-T_O)*J_H*JB;
	}
	else{
		if(time<=T_O)
			gz_z=time*J_F;
		else
			gz_z=T_O*J_F+(time-T_O)*J_F*JB;
	}
	return gz_z;
}
float s_l(float zgz)
{
	float s_l;
	if(zgz<=GZ_O)
		s_l=zgz*SL_O;
	else if(zgz<=GZ_T)
		s_l=GZ_O*SL_O+(zgz-GZ_O)*SL_T;
	else
		s_l=GZ_O*SL_O+(GZ_T-GZ_O)*SL_T+(zgz-GZ_T)*SL_H;
	return s_l;
}
