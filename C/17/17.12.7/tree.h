// 树种拥有相同项目时，项目的个数增加
#ifndef TREE_H_
#define TREE_H_
#include <stdbool.h>

#define WORDMAX 81 // 单词长度

// 单词存储结构
typedef struct item{
	char word[WORDMAX];
	int count; // 单词出现次数
} Item;

typedef struct node {
	Item item;
	struct node * left;
	struct node * right;
} Node;

typedef struct tree {
	Node * root;  // 树根
	int size;  // 树中项目的个数
} Tree;

// 函数原型
/*
 * 操作：把一个树初始化为空树
 * 操作前：ptree指向一个树
 * 操作后：该树被初始化为一个空树
 */
void InitializeTree (Tree * ptree);

/*
 * 操作：检查树是否为空
 * 操作前：ptree指向一个被初始化的树
 * 操作后：如果树为空树
 *         返回true，否则返回false
 */
bool TreeIsEmpty (const Tree * ptree);

/*
 * 操作：检查树是否已满
 * 操作前：ptree指向一个被初始化的树
 * 操作后：如果树已满
 *         返回true，否则返回false
 */
bool TreeIsFull (const Tree * ptree);

/*
 * 操作：检查树中是否存在指定项目
 * 操作前：ptree指向一个被初始化的树
 *         item指向被指定项目
 * 操作后：如果树中存在项目
 *         返回true，否则返回false
 */ 
bool InTree (const Item * item, const Tree * ptree);

/*
 * 操作：返回项目在树中的数目
 * 操作前：ptree指向一个被初始化的树
 *         item指向一个呗指定的项目
 * 操作后：返回指定项目在树中的个数
 */
int ItemCount (const Item * item, const Tree * ptree);

/*
 * 操作：将一个项目添加到树中
 * 操作前：ptree指向一个被初始化的树
 *         item指向被指定项目
 * 操作后：如果项目添加成功
 *         返回true，否则返回false
 */
bool AddToTree (Item * item, Tree * ptree);

/*
 * 操作：将指定函数作用于树的每一个项目
 * 操作前：ptree指向一个被初始化的树
 *         pfun指向一个函数
 *         该函数接受一个结构地址
 * 操作后：函数pfun被作用与树的每一个项目
 */
void Traverse (Tree * ptree, void (*pfun) (Item item));

/*
 * 操作：清空树
 * 操作前：ptree指向一个被初始化的树
 * 操作后：释放树所占用的内存
 *         树被清空
 */
void EmptyTree (Tree * ptree);

#endif
