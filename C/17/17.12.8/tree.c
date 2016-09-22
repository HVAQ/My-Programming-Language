#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "tree.h"

typedef struct pair
{ 
	Node * parent;
	Node * child;
} Pair;

static Pair SeekItem (const Item * item, const Tree * ptree);
static bool ToRight (const Item * i1, const Item * i2);
static bool ToLeft (const Item * i1, const Item * i2);
static void SetItem (Item * item, Node * pt);
static void AddNode (Node * pt, Node * root);
static void SetKind (const Item * item, Kind * pt);
static void InOder (Tree * ptree, Node * root, void (*pfun) (Item item, Tree * ptree));
static void DeleteAllNode (Node * root);
static void DeleteNode (Node **ptr);
static bool DeleteKind (Kind * ptr, Pair look);
static bool AddItem (Item * item, Pair look);

void Intialization (Tree * ptree)
{
	ptree->root = NULL;
	ptree->size = 0;
} 

bool TreeIsEmpty (const Tree * ptree)
{ 
	return ptree->root == NULL ? true : false;
}

bool TreeIsFull (const Tree * ptree)
{ 
	Node * pt;
	bool full;

	pt = (Node *) malloc (sizeof (Node));
	if (pt == NULL)
		full = true;
	else
 	{ 
		full = false;
		free (pt);
	}

	return full;
}

bool ItemInTree (const Item * item, const Tree * ptree)
{ 
	return SeekItem (item, ptree).child == NULL ? false : true;
}

bool KindInItem (const Item * item, const Tree * ptree)
{ 
	// 找到宠物在树中的节点
	Kind * temp = SeekItem (item, ptree).child->item.head;

	while (temp != NULL)
	{
		if (strcmp (item->head->petkind, temp->petkind) == 0)
			return true;
		else
			temp = temp->next;
 	} 

	return false;
}

bool AddToTree (Item * item, Tree * ptree)
{ 
	Node * pt;

	if (TreeIsFull (ptree))
	{
		fprintf (stderr, "内存空间已满.\n");
		return false;
 	}

	if (SeekItem (item, ptree).child != NULL)
		return true;

	pt = (Node *) malloc (sizeof (Node));
	SetItem (item, pt);
	ptree->size++;
	if (ptree->root == NULL)
		ptree->root = pt;
	else
		AddNode (pt, ptree->root);

	return true;
}

bool AddToItem (Item * item, Tree * ptree)
{
	Pair seek;
	Kind * pt;
	Kind * temp;

	if (TreeIsFull (ptree))
	{
		fprintf (stderr, "内存空间已满.\n");
		exit (EXIT_FAILURE);
	}

	if ((seek = SeekItem (item, ptree)).child == NULL)
	{
		fprintf (stderr, "出错了.\n");
		return false;
	}

	if (!AddItem (item, seek))
	{
		fprintf (stderr, "内存空间已满.\n");
		return false;
	}

	return true;
}

bool DelNode (Item * item, Tree * ptree)
{
	Pair look;
	Kind * temp;

	// 搜索项目在树中的位置
	look = SeekItem (item, ptree);

	if (look.child == NULL)
		return false;

	// 删除所有种类
	while (look.child->item.kindsize != 0)
	{
		temp = look.child->item.head;
		DeleteKind (temp, look);
	}

	if (look.parent == NULL)
		DeleteNode (&ptree->root);
	else if (look.parent->left == look.child)
		DeleteNode (&look.parent->left);
	else
		DeleteNode (&look.parent->right);
	ptree->size--;

	return true;
}

bool DelKind (Item * item, Tree * ptree)
{
	Pair look;
	Node * pt;
	Kind * temp;

	// 搜索项目在树中的位置
	look = SeekItem (item, ptree);
	pt = look.child;
	temp = pt->item.head;
	while (strcmp (temp->petkind, item->head->petkind) != 0)
		temp = temp->next;
	if (!DeleteKind (temp, look))
		return false;
	// 如果种类全部被删除，删除宠物名
	if (pt->item.kindsize == 0)
		DelNode (&look.child->item, ptree);

	return true;
}

void Traversal (Tree * ptree, void (*pfun) (Item item, Tree * ptree))
{
	if (ptree->root != NULL)
		InOder (ptree, ptree->root, pfun);
}

void ShowKind (Tree * ptree, Item * item, void (*pfun) (Item item))
{
	(*pfun) (SeekItem (item, ptree).child->item);
}

void EmptyTree (Tree * ptree)
{
	if (ptree->root != NULL)
		DeleteAllNode (ptree->root);
	ptree->root = NULL;
	ptree->size = 0;
}

static bool AddItem (Item * item, Pair look)
{
	Kind * pt;

	pt = (Kind *) malloc (sizeof (Kind));

	if (pt == NULL)
		return false;

	SetKind (item, pt);
	look.child->item.kindsize++;
	if (look.child->item.head == NULL)
	{
		look.child->item.head = pt;
		look.child->item.end = look.child->item.head;
	}
	else
	{
		look.child->item.end->next = pt;
		pt->prev = look.child->item.end;
		look.child->item.end = look.child->item.end->next;
	}

	return true;
}

static bool DeleteKind (Kind * ptr, Pair look)
{
	if (ptr == NULL)
		return false;

	// 面向链表中有且只有一项
	if (ptr->prev == NULL && ptr->next == NULL)
		free (ptr);
	// 面向链表首项
	else if (ptr->prev ==  NULL)
	{
		ptr->next->prev = NULL;
		look.child->item.head = ptr->next;
		free (ptr);
	}
	// 面向链表尾项
	else if (ptr->next == NULL)
	{
		ptr->prev->next = NULL;
		look.child->item.end = ptr->prev;
		free (ptr);
	}
	// 面向链表其他项
	else if (ptr->prev != NULL && ptr->next != NULL)
	{
		ptr->prev->next = ptr->next;
		free (ptr);
	}
	else
		return false;
	look.child->item.kindsize--;

	return true;
}

static void DeleteNode (Node **ptr)
{
	Node * temp;

	if ((*ptr)->left == NULL)
	{
		temp = *ptr;
		*ptr = (*ptr)->right;
		free (temp);
	}
	else if ((*ptr)->right == NULL)
	{
		temp = *ptr;
		*ptr = (*ptr)->left;
		free (temp);
	}
	else
	{
		// 找到右子树的依附位置
		for (temp = (*ptr)->left; temp->right != NULL; temp = temp->right)
			continue;
		temp->right = (*ptr)->right;
		temp = *ptr;
		*ptr = (*ptr)->left;
		free (temp);
	}
}

static void DeleteAllNode (Node * root)
{
	Node * pt;

	if (root != NULL)
	{
		pt = root->right;
		DeleteAllNode (root->left);
		free (root);
		DeleteAllNode (pt);
	}
}

static void InOder (Tree * ptree, Node * root, void (*pfun) (Item item, Tree * ptree))
{
	if (root != NULL)
	{
		InOder (ptree, root->left, pfun);
		(*pfun) (root->item, ptree);
		InOder (ptree, root->right, pfun);
	}
}

static void SetKind (const Item * item, Kind * pt)
{
	strcpy (pt->petkind, item->head->petkind);
	pt->prev = NULL;
	pt->next = NULL;
}

static void AddNode (Node * pt, Node * root)
{
	// 添加到左子树
	if (ToLeft (&pt->item, &root->item))
	{
		if (root->left == NULL)
			root->left = pt;
		else
			AddNode (pt, root->left);
	 }
	// 添加到右子树
	else if (ToRight (&pt->item, &root->item))
	{
		if (root->right == NULL)
			root->right = pt;
		else
			AddNode (pt, root->right);
	}
	// 项目在树中
	else
 	{
		fprintf (stderr, "出错了.\n");
		exit (EXIT_FAILURE);
	}
}

static void SetItem (Item * item, Node * pt)
{
	pt->item = *item;
	pt->item.head = NULL;
	pt->item.end = NULL;
	pt->left = NULL;
	pt->right = NULL;
}

static bool ToLeft (const Item * i1, const Item * i2)
{
	if (strcmp (i1->petname, i2->petname) < 0)
		return true;
	else
		return false;
}

static bool ToRight (const Item * i1, const Item * i2)
{
	if (strcmp (i1->petname, i2->petname) > 0)
		return true;
	else
		return false;
}

static Pair SeekItem (const Item * item, const Tree * ptree)
{ 
	Pair look;
	look.parent = NULL;
	look.child = ptree->root;

	// 树为空
	if (look.child == NULL)
		return look;

	while (look.child != NULL)
	{
		// 搜索左子树
		if (ToLeft(item, &(look.child->item)))
		{
			look.parent = look.child;
			look.child = look.child->left;
 	 	}
		// 搜索右子树
		else if (ToRight(item, &(look.child->item)))
 	 	{
			look.parent = look.child;
			look.child = look.child->right;
		}
		// 项目在树中
		else
			break;
 	}

	return look;
}
