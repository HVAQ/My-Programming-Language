#include <stdio.h>
#include <stdlib.h>
#include "list.h"

// 局部函数原型
static void CopyToNode (Item item, Node * pnods);

// 接口函数
// 把列表置为空列表
void InitiallizeList (List * plist)
{
	plist -> head = NULL;
	plist -> end = NULL;
}

//如果列表为空返回真
bool ListIsEmpty (const List * plist)
{
	if (plist -> head == NULL)
		return true;
	else
		return false;
}

//如果列表已满返回真
bool ListIsFull (void)
{ 
	Node * pt;
	bool full;

	pt = (Node *) malloc (sizeof (Node));
	if (pt == NULL)
		full = true;
	else
		full = false;
	free (pt);

	return full;
}

//返回节点数
unsigned int ListItemCount (const List * plist)
{
	unsigned int count = 0;
	Node * poned = plist -> head;  // 设置列表的开始

	while (poned != NULL)
	{ 
		++count;
		poned = poned -> next;
	}

	return count;
}

//创建存放项目的节点，并把它添加到
//由plist指向的列表(较慢的实现方法)尾部
bool AddItem (Item item, List * plist)
{
	Node * pnew;
	Node * scan = plist -> head;

	pnew = (Node *) malloc (sizeof (Node));

	if (pnew == NULL)
		return false;

	CopyToNode (item, pnew);
	pnew -> next = NULL;  // 将输入项设为最后一项
	plist -> end = pnew;
	if (scan == NULL) // 如果首项为空, 将项目设置为首项, 并将他的位置传递给head
		plist -> head = pnew;
	else
	{ 
		while (scan -> next != NULL)
			scan = scan -> next;
		scan -> next = pnew;
 	} 

	return true;
} 

//访问每个节点并对它们分别执行由pfun指向的函数
void Trancerse (const List * plist, void (*pfun)(Item item))
{ 
	Node * pnode = plist -> head;

	while (pnode != NULL)
	{ 
		(*pfun)(pnode -> item);
		pnode = pnode -> next;
	}
}

//释放由malloc()分配的内存
//把列表指针设置为NULL
void EmptyTheList (List * plist)
{
	Node * psave;

	while (plist -> head != NULL)
	{
		psave = plist -> head -> next;
		free (plist -> head);
		plist -> head = psave;
	} 
}

//局部函数定义
//把一个项目复制到一个节点中
static void CopyToNode (Item item, Node * pnode)
{
	pnode -> item = item;
}
