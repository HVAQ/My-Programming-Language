#pragma c9x on
#ifndef _QUEUE_H_
#define _QUEUE_H_
#include <stdbool.h>

typedef struct item 
{
	long arrive;  // 一位顾客加入队列的时间
	int processtime;  // 一位顾客咨询需要时长
} Item;

#define MAXQUEUE 10

typedef struct node 
{
	Item item;
	struct node * next;
} Node;

typedef struct queue 
{
	Node * front;  // 指向队列首的指针
	Node * rear;  // 指向队列尾的指针
	int items;  // 队列中项目的个数
} Queue;

/* 操作：初始化队列
 * 操作前：pq指向一个队列
 * 操作后：该队列被初始化为空队列
 */
void InitializeQueue (Queue * pq);

/* 操作：检查队列是否已满
 * 操作前：pq指向一个先前已被初始化的队列
 * 操作后：如果队列已满，返回True；
 */
bool QueueIsFull (const Queue * pq, int linenum);

/* 操作：检查队列是否为空
 * 操作前：pq指向一个先前已被初始化的队列
 * 操作后：如果队列为空，返回True；
 */
bool QueueIsEmpty (const Queue * pq);

/* 操作：确定队列中项目个数
 * 操作前：pq指向一个先前已被初始化的队列
 * 操作后：返回队列中项目个数
 */
int QueueItemCount (const Queue * pq);

/* 操作：向队列尾端添加项目
 * 操作前：pq指向一个先前已被初始化的队列
 *         item是要添加到队列尾端的项目
 * 操作后：队列未满，添加，返回True
 *         否则队列不改变，返回false
 */
bool EnQueue (Item item, Queue * pq, int linenum);

/* 操作：从队列首端删除项目
 * 操作前：pq指向一个先前已被初始化的队列
 * 操作后：对列非空，首端项目被复制到*pitem
 *         并从队列删除，返回true
 *         如果该操作使队列为空，把队列重置为空队列
 *         如果队列开始为空，不改变队列，返回false
 */
bool DeQueue (Item *pitem, Queue * pq);

/* 操作：清空队列
 * 操作前：pq指向一个先前已被初始化的队列
 * 操作后：队列被清空
 */
void EmptyTheQueue (Queue * pq);

#endif
