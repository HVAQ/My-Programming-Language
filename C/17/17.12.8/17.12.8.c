#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "tree.h"

char menu (void);
void menu_a(Tree *);
void menu_d(Tree *);
void menu_f(Tree *);
void menu_s(Tree *);
void showpet (Item, Tree *);
void showkind (Item);

int main (void)
{
	Item item;
	Tree ptree;
	char chioce;

	Intialization(&ptree);
	if (TreeIsFull(&ptree))
	{
		fprintf (stderr, "内存空间不足.\n");
		exit (EXIT_FAILURE);
	}  

	while ((chioce = menu()) != 'q')
	{  
		switch(chioce)
	  	{
			case 'a': menu_a(&ptree); break;
			case 'd': menu_d(&ptree); break;
			case 'f': menu_f(&ptree); break;
			case 's': menu_s(&ptree); break;
			default: puts("出错了.");
		}
	}
	EmptyTree(&ptree);
	puts ("Bye!");

	return 0;
}

void showpet (Item item, Tree * ptree)
{
	puts ("--------------------------------");
	printf ("%s", item.petname);
	ShowKind (ptree, &item, showkind);
}

void showkind (Item item)
{
	Kind * temp = item.head;

	while (temp != NULL)
	{
		printf ("\t\t\t%s\n", temp->petkind);
		temp = temp->next;
	}
}

void menu_s (Tree * ptree)
{
	if (TreeIsEmpty (ptree))
		fprintf (stderr, "没有任何宠物.\n");
	else
	{ 
		puts ("********************************");
		puts ("          宠物及其种类");
		printf ("%s\t\t\t%s\n", "宠物", "种类");
		Traversal (ptree, showpet);
		puts ("********************************");
		putchar ('\n');
	}
}

void menu_f (Tree * ptree)
{
	Item item;
	char petname[NAMEMAX];

	if (TreeIsEmpty (ptree))
		fprintf (stderr, "没有任何宠物.\n");
	else
	{
		printf ("请输入宠物名: ");
		gets (petname);
		strcpy (item.petname, petname);
		if (!ItemInTree (&item, ptree))
			fprintf (stderr, "没有名为%s的宠物.\n", petname);
		else
		{
			puts ("--------------------------------");
			printf ("%s\t\t\t%s\n", "宠物", "种类");
			printf ("%s", petname);
			ShowKind (ptree, &item, showkind);
			puts ("--------------------------------");
		}
	}
}

void menu_d (Tree * ptree)
{
	char petname[NAMEMAX];
	char petkind[KINDMAX];
	Item item;
	Kind kind;
	char ch;

	if (TreeIsEmpty (ptree))
		fprintf (stderr, "没有任何宠物.\n");
	else
	{
		printf ("请输入要删除的宠物名: ");
		gets (petname);
		strcpy (item.petname, petname);
		if (!ItemInTree (&item, ptree))
			fprintf (stderr, "没有名为%s的宠物.\n", petname);
		else
		{
			puts ("********************************");
			puts ("            请选择");
			printf ("a) 删除%s的所有种类\n", petname);
			printf ("o) 删除%s的一个种类\n", petname);
			puts ("q) 退出");
			puts ("********************************");
			printf ("请输入: ");
			while ((ch = getchar()) != 'q' && ch != 'Q')
			{
				while (getchar() != '\n')
					continue;
				ch = tolower(ch);
				if (ch != 'a' && ch != 'o')
					printf ("请输入列表中的选项: ");
				else
					break;
			}
			
			if (ch == 'a')
			{
				if (!DelNode (&item, ptree))
				{
					fprintf (stderr, "出错了.\n");
					exit (EXIT_FAILURE);
				}
			}
			else if (ch == 'o')
			{
				printf ("请输入要删除的种类: ");
				gets (petkind);
				strcpy (kind.petkind, petkind);
				item.head = &kind;
				if (!KindInItem (&item, ptree))
					fprintf (stderr, "名叫%s的宠物中, 没有种类为%s的宠物.\n", petname, petkind);
				else
					while (!DelKind (&item, ptree))
					{
						fprintf (stderr, "删除失败, 正在重新删除.\n");
						continue;
					}
			}
			else
			{
				while (getchar() != '\n')
					continue;
			}
		}
	}
}

void menu_a (Tree * ptree)
{
	char petname[NAMEMAX];
	char petkind[KINDMAX];
	Item item;
	Kind kind;

	printf ("请输入宠物名: ");
	gets (petname);
	strcpy (item.petname, petname);
	if(!AddToTree(&item, ptree))
		exit (EXIT_FAILURE);
	printf ("请输入宠物种类: ");
	gets (petkind);
	strcpy (kind.petkind, petkind);
	item.head = &kind;
	if (KindInItem (&item, ptree))
		fprintf (stderr, "%s中已有%s.\n", petname, petkind);
	else if (!AddToItem (&item, ptree))
	{
		fprintf (stderr, "种类%s添加失败.\n", petkind);
		exit (EXIT_FAILURE);
	}
}

char menu (void)
{
	char chioce;
	char ch[] = "adfs";

	puts ("================================");
	puts ("             请选择");
	puts ("a) 增加一个宠物  d) 删除一个宠物");
	puts ("f) 查找一个宠物  s) 显示所有宠物");
	puts ("q) 退出");
	puts ("================================");
	printf ("请输入: ");

	while ((chioce = getchar()) != 'q' && chioce != 'Q')
	{
		while (getchar() != '\n')
			continue;
		chioce = tolower(chioce);
		if (strpbrk (&chioce, ch) == NULL)
			printf ("请输入列表中的选项: ");
		else
			break;
	}
	chioce = tolower(chioce);

	return chioce;
}
