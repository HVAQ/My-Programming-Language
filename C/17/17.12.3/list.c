#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "list.h"

// 接口函数
// 把列表置为空列表
void InitiallizeList (List * plist)
{
	int index = 0;
	Item * pnode;

	for (index = 0; index < MAXSIZE; index++)
	{
		pnode = plist -> enteries;
		pnode = NULL;
		pnode++;
	}
	(plist -> items) = 0;
}

//如果列表为空返回真
bool ListIsEmpty (const List * plist)
{
	if (plist -> items == 0)
		return true;
	else
		return false;
}

//如果列表已满返回真
bool ListIsFull (const List * plist)
{  
	Item * pt;
	bool full;

	if (plist -> items >= MAXSIZE)
		full = true;
	else
	{ 
		pt = (Item *) malloc (sizeof (Item));
		if (pt == NULL)
			full = true;
		else
			full = false;
		free (pt);
	}

	return full;
}

//创建存放项目的节点，并把它添加到
//由plist指向的列表(较慢的实现方法)尾部
bool AddItem (Item item, List * plist)
{
	Item * pnew;

	pnew = (Item *) malloc (sizeof (Item));

	if (pnew == NULL)
		return false;
	free (pnew);

	strcpy (plist -> enteries[plist -> items].title, item.title);
	plist -> enteries[plist -> items].rating = item.rating;
	++(plist -> items);

	return true;
} 

//访问每个节点并对它们分别执行由pfun指向的函数
void Trancerse (const List * plist, void (*pfun)(Item item))
{ 
	int index = 0;

	while (index < plist -> items)
	{
		(*pfun)(plist -> enteries[index]);
		++index;
	}
}

//释放由malloc()分配的内存
//把列表指针设置为NULL
void EmptyTheList (List * plist)
{
	plist -> items = 0;
}
