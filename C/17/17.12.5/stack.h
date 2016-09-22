#ifndef STACK_H_
#define STACK_H_
#include <stdbool.h>

typedef struct node
{
	char item;
	// 要打印的下一个字符串的位置
	struct node * next;
} Node;

typedef struct stack
{
	// 打印栈队首
	Node * head;
	// 打印栈队尾
	Node * end;
} Stack;

// 初始化栈
void ToFirst (Stack * plist);

/*
 * 操作：测试栈是否已满
 * 操作前：plist指向一个已初始化的栈
 * 如果栈已满返回true，否则返回false
 */
bool IsFull (const Stack * plist);

/*
 * 操作：测试栈是否为空
 * 操作前：plist指向一个已初始化的栈
 * 操作后：栈为空返回true，否则返回false
 */
bool IsEmpty (const Stack * plist);

/*
 * 操作：将字符压入栈
 * 操作前：item指向输入
 *         plsit指向一个已初始化栈
 * 操作后：如果申请内存失败，返回false
 *         如果栈为空，输入即是打印队列队首，也是队尾
 *         否则，输入为打印队列队首，其next指向下一个打印元素
 */
bool AddToString (char ch, Stack * plist);

/*
 * 操作：将函数运用于栈的每一个元素
 * 操作前：plist指向一个已初始化的栈
 *         pfun指向一个无返回值，接受Node类型值的函数
 * 操作后：将函数运用于栈的每一个元素
 */
void Tranverse (Stack * plist, void (*pfun) (char temp));

/*
 * 操作：清空栈
 * 操作前：plist指向一个已初始化的栈
 * 操作后：将栈的plist设为空指针
 */
void ToEmpty (Stack * plist);

#endif
