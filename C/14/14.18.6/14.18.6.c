#include <stdio.h>
#include <string.h>  // 包含strcpy()函数
#define SIZE 19

struct aname {
	char fname[10];
	char lname[10];
};

struct info {
	int num;  // 球员号码
	struct aname name;  // 嵌套姓名结构 
	int sc;  // 上场次数
	int jz;  // 击中数
	int zl;  // 走垒数
	int pd;  // 跑点数
	double pj;  // 平均数
};

void set_info (struct info *);  // 初始化结构
void get_info (struct info *);  // 获取信息
void set_pj (struct info *);  // 计算平均分
void show_info (const struct info *);  // 打印信息

int main (void)
{
	struct info qy[SIZE];
	set_info(qy);
	get_info(qy);
	set_pj(qy);
	show_info(qy);

	return 0;
}

void set_info (struct info * qy)
{
	for (int i = 0; i < SIZE; i++)
	{
		qy[i].num = 0;
		strcpy (qy[i].name.fname, "fname");
		strcpy (qy[i].name.lname, "lname");
		qy[i].sc = 0;
		qy[i].jz = 0;
		qy[i].zl = 0;
		qy[i].pd = 0;
		qy[i].pj = 0.0;
	}
}

void get_info (struct info * qy)
{
	FILE *fp;
	char filename[20];
	int num, sc, jz, zl, pd;
	char fname[10], lname[10];

	// 获取并打开文件
	puts ("请输入文件名.");
	gets (filename);
	while ((fp = fopen(filename, "r")) == NULL)
	{
		fprintf (stderr, "打开文件[%s]失败.\n", filename);
		puts ("请重新输入文件名.");
		gets (filename);
	}
	// 读取文件
	while (fscanf (fp, "%d %s %s %d %d %d %d", &num, fname, lname, &sc, &jz, &zl, &pd) == 7)
	{
		qy[num].num = num;
		strcpy (qy[num].name.fname, fname);
		strcpy (qy[num].name.lname, lname);
		qy[num].sc += sc;
		qy[num].jz += jz;
		qy[num].zl += zl;
		qy[num].pd += pd;
	}
	// 关闭文件
	if (fclose(fp) != 0)
		fprintf (stderr, "关闭文件[%s]失败.\n", filename);
}

void set_pj (struct info * qy)
{
	//  球员平均成功率 ＝ 累计击中数 ／ 上场总次数
	int i;

	for (i = 0; i < SIZE; i++)
		qy[i].pj = (float) qy[i].jz / (float) qy[i].sc;
}

void show_info (const struct info * qy)
{
	int i;
	int ssc, sjz, szl, spd;
	float spj = 0.0;

	ssc = sjz = szl = spd = 0;
	for (i = 0; i < SIZE; i++)
	{
		printf ("%4d %10s %10s %4d %4d %4d %4d %4.2f\n",
				qy[i].num, qy[i].name.fname, qy[i].name.lname, qy[i].sc, qy[i].jz, qy[i].zl, qy[i].pd, qy[i].pj);
		ssc += qy[i].sc;
		sjz += qy[i].jz;
		szl += qy[i].zl;
		spd += qy[i].pd;
	}
	spj = (float) sjz / (float) ssc;
	// 打印全程统计数据
	printf ("数据统计: ");
	puts ("上场 击中 走垒 跑点 平均");
	printf ("          %2d  %3d  %3d  %3d  %2.2f\n", ssc, sjz, szl, spd, spj);
}
