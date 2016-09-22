#ifndef TREE_H_
#define TREE_H_
#include <stdbool.h>

#define NAMEMAX 81
#define KINDMAX 81

typedef struct kind
{
	struct kind * prev;
	char petkind[KINDMAX];
	struct kind * next;
} Kind;

typedef struct item
{
	char petname[NAMEMAX];
	Kind * head;
	Kind * end;
	int kindsize;
} Item;

typedef struct node
{
	Item item;
	struct node * left;
	struct node * right;
} Node;

typedef struct tree
{
	Node * root;
	int size;
} Tree;

// 函数原型
/*
 * 操作：初始化树为一个空树
 * 操作前：ptree指向一个树
 * 操作后：ptree指向的树被初始化为一个空树
 */
void Intialization (Tree * ptree);

/*
 * 操作：检测树是否为空树
 * 操作前：ptree指向一个已被初始化的树
 * 操作后：如果树为空树返回true，否则返回false
 */
bool TreeIsEmpty (const Tree * ptree);

/*
 * 操作：检测树是否已满
 * 操作前：ptree指向一个已被初始化的树
 * 操作后：如果树已满返回true，否则返回false
 */
bool TreeIsFull (const Tree * ptree);

/*
 * 操作：检测项目是否在树中
 * 操作前：ptree指向一个已被初始化的树
 *         item指向一个项目
 * 操作后：如果项目在树中，返回true
 *         否则返回false
 */
bool ItemInTree (const Item * item, const Tree * ptree);
/*
 * 操作：检测项目是否在链表中
 * 操作前：ptree指向一个已被初始化的树
 *         item指向一个项目
 * 操作后：如果项目在树与链表中，返回true
 *         否则返回false
 */
bool KindInItem (const Item * item, const Tree * ptree);

/*
 * 操作：将一个项目添加到树中
 * 操作前：ptree指向一个已被初始化的树
 *         item指向一个项目
 * 操作后：如果项目被成功添加到树中返回true
 *         否则返回false
 */
bool AddToTree (Item * item, Tree * ptree);

/*
 * 操作：将一个种类添加到链表中
 * 操作前：ptree指向一个已被初始化的树
 *         item指向一个项目
 * 操作后：如果种类被添加到链表中返回true
 *         否则返回false
 */
bool AddToItem (Item * item, Tree * ptree);

/*
 * 操作：删除一个项目
 * 操作前：ptree指向一个已被初始化的树
 *         item指向用户输入
 * 操作后：如果用户输入项目在树中
 *         并成功删除，返回true，否则返回false
 */
bool DelNode (Item * item, Tree * ptree);

/*
 * 操作：删除一个种类
 * 操作前：ptree指向一个树
 *         item指向用户输入
 * 操作后：如果用户输入在树中
 *         应成功删除，返回true，否则返回false
 */
bool DelKind (Item * item, Tree * ptree);

/*
 * 操作：遍历树
 * 操作前：ptree指向一个已被初始化的树
 *         pfun指向一个函数
 * 操作后：将pfun指向的函数作用于树的每一个项目
 */
void Traversal (Tree * ptree, void (*pfun) (Item item, Tree * ptree));

/*
 * 操作：遍历链表
 * 操作前：ptree指向一个已被初始化的树
 *         pfun指向一个函数
 * 操作后：将pfun指向的函数作用于链表的每一个项目
 */
void ShowKind (Tree * ptree, Item * item, void (*pfun) (Item item));

/*
 * 操作：清空树
 * 操作前：ptree指向一个已被初始化的树
 * 操作后：树被清空;
 */
void EmptyTree (Tree * ptree);

#endif
