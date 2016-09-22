#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tree.h"

typedef struct pair {
	Node * parten;
	Node * child;
} Pair;

static Node * SetNode (const Item * pi);
static bool ToLeft (const Item * i1, const Item * i2);
static bool ToRight (const Item * i1, const Item * i2);
static void AddNode (Node * new_node, Node * root);
static Pair SeekItem (const Item * item, const Tree * ptree);
static void EmptyAllNode (Node * root);
static void InOder (Node * root, void (*pfun) (Item item));

// 初始化树
void InitializeTree (Tree * ptree)
{
	ptree->root = NULL;
	ptree->size = 0;
} 

// 测试树是否为空
bool TreeIsEmpty (const Tree * ptree)
{
	if (ptree->root == NULL)
		return true;
	else
		return false;
}

// 测试内存空间是否注意存储一个node项目
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
		free(pt);
	}

	return full;
} 

// 返回项目是否在树中的个数
bool InTree (const Item * item, const Tree * ptree)
{
	return SeekItem (item, ptree).child == NULL ? false : true;
}

int ItemCount (const Item * item, const Tree * ptree)
{
	return SeekItem (item, ptree).child->item.count;
}

bool AddToTree (Item * item, Tree * ptree)
{ 
	Node * new_node;
	Pair seek;

	if (TreeIsFull (ptree))
 	{
		fprintf (stderr, "内存空间不足.\n");
		return false;
	}

	if ((seek = SeekItem (item, ptree)).child != NULL)
	{
		seek.child->item.count++;
		return true;
	}
	
	new_node = SetNode (item);
	if (new_node == NULL) // 如果读入数据为空，出错
	{
		fprintf (stderr, "读取错误.\n");
		exit (EXIT_FAILURE);
	}
	
	ptree->size++;

	if (TreeIsEmpty (ptree))
		ptree->root = new_node;
	else
		AddNode (new_node, ptree->root);  // 将新节点添加到树中
	
	return true;
}

// 遍历树
void Traverse (Tree * ptree, void (*pfun) (Item item))
{
	if (ptree != NULL)
		InOder (ptree->root, pfun);
}

// 清空树
void EmptyTree (Tree * ptree)
{
	if (ptree != NULL)
		EmptyAllNode (ptree->root);
	// 清空根
	ptree->root = NULL;
	// 重置树计数
	ptree->size = 0;
}

// 逐个清空树各个项目
static void EmptyAllNode (Node * root)
{
	Node * pt;

	if (root != NULL)
	{ 
		pt = root->right;
		// 清空最左子树
		EmptyAllNode (root->left);
		free(root);
		// 清空最右子树
		EmptyAllNode (pt);
	}
}

static void InOder (Node * root, void (*pfun) (Item item))
{
	if (root != NULL)
	{ 
		// 遍历左子树
		InOder (root->left, pfun);
		(*pfun) (root->item);
		// 遍历右子树
		InOder (root->right, pfun);
	}
}

// 搜索项目在树中的位置
static Pair SeekItem (const Item * item, const Tree * ptree)
{
	Pair look;
	look.parten = NULL;  // 父节点
	look.child = ptree->root;  // 当前节点

	if (look.child == NULL)
		return look;

	while (look.child != NULL)
	{
		if (ToLeft (item, &look.child->item))
		{
			look.parten = look.child;  // 父节点
			look.child = look.child->left;  // 当前节点
	  	}
		else if (ToRight (item, &look.child->item))
		{ 
			look.parten = look.child;
			look.child = look.child->right;
	  	}
		else  // 当前节点项目与输入相同
			break;
	} 

	return look;
}

static void AddNode (Node * new_node, Node * root)
{
	if (ToLeft (&new_node->item, &root->item))
	{
		if (root->left == NULL)
			root->left = new_node;
		else
			AddNode (new_node, root->left);
	}  
	else if (ToRight (&new_node->item, &root->item))
	{
		if (root->right == NULL)
			root->right = new_node;
		else
			AddNode (new_node, root->right);
	}  
	else
	{
		printf ("出错了-_-#.\n");
		exit (EXIT_FAILURE);
	}

}

// 初始化项目值
static Node * SetNode (const Item * pi)
{ 
	Node * new_node;

	new_node = (Node *) malloc (sizeof (Node));
	if (new_node != NULL)
 	{
		new_node->item = *pi;
		new_node->item.count = 1;
		new_node->left = NULL;
		new_node->right = NULL;
	}

	return new_node;
}

static bool ToLeft (const Item * i1, const Item * i2)
{
	if (strcmp (i1->word, i2->word) < 0)
		return true;
	else
		return false;
} 

static bool ToRight (const Item * i1, const Item * i2)
{  
	if (strcmp (i1->word, i2->word) > 0)
		return true;
	else
		return false;
}
