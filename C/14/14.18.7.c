// 删除的原理是进行标记，再次写入时将其排除
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 10

struct book {
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
	int delete;
};

void eatline (void);
char next (void);
char show_mean (int);
int add_lib (struct book *, int);
void cha_lib (struct book *, int);
void del_lib (struct book *, int);

int main (void)
{
	struct book library[MAXBKS];
	int count = 0;
	int index, filecount;
	FILE * pbooks;
	int size = sizeof (struct book);
	char ch;

	if ((pbooks = fopen ("book", "a+b")) == NULL)
    {
        // 也可以用r+b模式, 但需要提前建立文件；不可用w+b模式, 否则会将所有内容覆盖掉
		fprintf (stderr, "打开文件 book 失败.\n");
		exit (EXIT_FAILURE);
	}
	// 读取文件并显示
	rewind (pbooks);  // 跳到文件开始部分
	while (count < MAXBKS && fread (&library[count], size, 1, pbooks) == 1)
	{
		if (count == 0)
			puts ("现在book中的内容是: ");
		printf ("%s by %s: $%.2f\n", library[count].title, library[count].author, library[count].value);
		count++;
	}
	// 显示交互式选择菜单
	ch = show_mean (count);
	if (ch != 'q')
	{
		switch(ch)
		{
			case 'a': count = add_lib (library, count); break;
			case 'c': cha_lib (library, count); break;
			case 'd': del_lib (library, count); break;
		}
		// 显示现在结构数组中的内容，并将其写入文件
		if (count >= 0)
		{
			fclose(pbooks);  // r+b 模式不能对文件进行覆盖写，所以必须关闭
			pbooks = fopen ("book", "w+b"); // 并以 w+b 模式重新打开
            rewind (pbooks);
			puts ("现在 book 中的内容是: ");
			for (index = 0; index < count; index++)
				{
					if (library[index].delete != -1)
					{
						printf ("%s by %s: $%.2f\n", library[index].title, library[index].author, library[index].value);
						fwrite (&library[index], size, 1, pbooks);
					}
				}
		}
		else
			puts ("book中没有书目.");
	}
	puts ("Bye!");
	if (fclose (pbooks) != 0)
		puts ("关闭文件 book 失败.");

	return 0;
}

void eatline (void)
{
	while (getchar() != '\n')
		continue;
}

char next (void)
{
	char ch;

	if ((ch = getchar()) != '\n')
		eatline();
	ch = tolower(ch);

	return ch;
}

char show_mean (int count)
{
	char ch;
	int n = 0;

	if (count == 0)
	{
		puts ("您的书目现在是空的");
		return 'a';
	}
	else if (count == MAXBKS)
	{
		n = 0;
		puts ("book 已满.");
		puts ("请选择修改(c)、删除(d)书目或退出(q).");
		ch = next();
	}
	else
	{
		n = 1;
		puts ("请选择增加(a)、修改(c)、删除(d)书目或退出(q).");
		ch = next();
	}
	while (ch != 'q')
	{
		if (n == 0 && (ch != 'c' && ch != 'd'))
		{
			puts ("您的输入有误, 请重新输入");
			ch = next();
		}
		else if (n == 1 && (ch != 'a' && ch != 'c' && ch != 'd'))
		{
			puts ("您的输入有误, 请重新输入");
			ch = next();
		}
		else
			break;
	}
	
	return ch;
}

int add_lib (struct book * lib, int count)
{
	puts ("请输入新书名.");
	puts ("键入空行退出.");
	while (count < MAXBKS && gets (lib[count].title) != NULL && lib[count].title[0] != '\0')
	{
		puts ("请输入作者名.");
		gets (lib[count].author);
		puts ("请输入书的单价.");
		scanf ("%f", &lib[count++].value);
		eatline();
		puts ("添加成功");
		if (count < MAXBKS)
			puts ("请输入下一个书名.");
	}
	if (count == MAXBKS)
		puts ("book 已满.");

	return count;
}

void cha_lib (struct book * lib, int count)
{
	int i;
	float value;
	char ch;
	char name[MAXTITL], title[MAXTITL], author[MAXAUTL];
	
	puts ("请输入要修改的书名.");
	gets (name);
	for (i = 0; i < count; i++)
		if (strcmp (lib[i].title, name) == 0)
			break;
	if (i == count)
		printf ("没有找到%s.", name);
	else
	{
		puts ("您要修改书名(t)、作者名(a)、书价(v)、退出(q)?");
		ch = next();
		while (ch != 'q' && ch != 't' && ch != 'a' && ch != 'v')
		{
			puts ("您的输入有误.");
			ch = next();
		}
		if (ch != 'q')
		{
			switch(ch)
			{
				case 't': puts ("请输入修改后的书名.");
						  while (gets (title) == NULL || title[0] == '\0')
							  puts ("您的输入有误, 请重新输入.");
						  strcpy (lib[i].title, title);
						  break;
				case 'a': puts ("请输入修改后的作者名.");
						  gets (author);
						  strcpy (lib[i].author, author);
						  break;
				case 'v': puts ("请输入书的单价.");
						  scanf ("%f", &value);
						  lib[i].value = value;
						  break;
			}
			puts ("修改成功");
		}
	}
}

void del_lib (struct book * lib, int count)
{
	int m, n, i;
	char ch;
	char name[MAXTITL];

	puts ("请输入要删除的书名");
	gets(name);
	for (i = 0; i < count; i++)
		if (strcmp (name, lib[i].title) == 0)
			break;
	if (i == count)
		printf ("没有找到%s.\n", name);
	else
	{
		printf ("确定删除: ");
		printf ("%s by %s: $%.2f (y / n)?\n",lib[i].title, lib[i].author, lib[i].value);
		ch = next();
		// 对要删除的书目进行标记
		if (ch == 'y')
		{
			lib[i].delete = -1;
			puts ("删除成功.");
		}
	}
}
