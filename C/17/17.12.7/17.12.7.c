#include <stdio.h>
#include <stdlib.h>  // 包含exit()函数
#include <ctype.h>  // 包含tolower()函数
#include <string.h>

#include "tree.h"

#define NAMEMAX 81

char menu (void);
char choose (void);
void menu_a (Tree * ptree);
void menu_b (Tree * ptree);
void showtree (Item item);

int main (void)
{
	Tree ptree;
	Item item;
	char filename[NAMEMAX], word[WORDMAX]; 
	FILE * fp;
	char ch;

	if (TreeIsFull (&ptree))
	{ 
		fprintf (stderr, "内存空间不足.\n");
		exit (EXIT_FAILURE);
	}

	printf ("请输入要打开的文件名: ");
	gets(filename);
	if ((fp = fopen (filename, "r")) == NULL)
	{
		fprintf (stderr, "打开文件[%s]失败.\n", filename);
		exit (EXIT_FAILURE);
	} 

	InitializeTree (&ptree);
	rewind (fp); // 跳到文件开始处
	while (fscanf (fp, "%s", word) == 1 && !TreeIsFull (&ptree))
 	{
		strcpy (item.word, word);

		if (!AddToTree (&item, &ptree))
		{
			fprintf (stderr, "内存空间不足.\n");
			exit (EXIT_FAILURE);
 		}
	}

	while ((ch = menu()) != 'q')
	{
		switch (ch)
		{
			case 'a': menu_a (&ptree);
					  break;
			case 'b': menu_b (&ptree);
					  break;
			default: printf ("menu "); puts ("出错了-_-#");
		}
	}

	EmptyTree (&ptree);
	puts ("Bye!");

	return 0;
} 

char menu (void)
{
	char ch;

	puts ("************************************");
	puts ("a) 显示所有单词及其出现次数");
	puts ("b) 搜索单词\tq) 退出");
	puts ("************************************");
	printf ("请输入您的选择: ");

	while ((ch = choose()) != 'q' && ch != 'a' && ch != 'b')
		printf ("请输入菜单中的选项: ");

	return ch;
} 
char choose (void)
{
	char ch;

	ch = getchar();
	while (getchar() != '\n')
		continue;
	ch = tolower (ch);

	return ch;
}

void menu_a (Tree * ptree)
{
	if (TreeIsEmpty (ptree))
	{
		puts ("文件中没有任何内容.");
		exit (EXIT_FAILURE);
	}
	
	printf ("%3s %17s\n", "出现次数", "单词");
	Traverse (ptree, showtree);
	printf ("文件中共有%d种单词.\n\n", ptree->size);
}

void menu_b (Tree * ptree)
{
	Item item;
	char word[WORDMAX];

	if (TreeIsEmpty (ptree))
 	{
		fprintf (stderr, "文件中没有任何内容.\n");
		exit (EXIT_FAILURE);
	}

	printf ("请输入要查询的单词: ");
	gets (word);
	strcpy (item.word, word);
	if (InTree (&item, ptree))
		printf ("%s在文件中出现%d次.\n\n", item.word, ItemCount (&item, ptree));
	else
		printf ("文件中没有%s.\n\n", item.word);
}

void showtree (Item item)
{
	printf ("%4d %20s\n", item.count, item.word);
}
