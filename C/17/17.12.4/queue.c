#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

static void CopyToNode (Item, Node *);
static void CopyToItem (Node *, Item *);

void InitializeQueue (Queue * pq)
{
	pq -> front = pq -> rear = NULL;
	pq -> items = 0;
}

bool QueueIsFull (const Queue * pq, int linenum)
{
	return pq -> items == MAXQUEUE * linenum;
}

bool QueueIsEmpty (const Queue * pq)
{
	return pq -> items == 0;
}

int QueueItemCount (const Queue * pq)
{
	return pq -> items;
}

bool EnQueue (Item item, Queue * pq, int linenum)
{
	Node * pnew;

	if (QueueIsFull (pq, linenum))
		return false;
	pnew = (Node *) malloc (sizeof(Node));
	if (pnew == NULL)
	{
		fprintf (stderr, "Unable to allocate memory!\n");
		exit (EXIT_FAILURE);
	}
	CopyToNode (item, pnew);
	pnew -> next = NULL;
	if (QueueIsEmpty (pq))
		pq -> front = pnew;
	else
		pq -> rear -> next = pnew;  // 链接到队列尾端
	pq -> rear = pnew;  // 纪录队列尾端的位置
	pq -> items++;

	return true;
}

bool DeQueue (Item * pitem, Queue * pq)
{
	Node * pnew;

	if (QueueIsEmpty (pq))
		return false;
	CopyToItem (pq -> front, pitem);
	pnew = pq -> front;
	pq -> front = pq -> front -> next;
	free (pnew);
	pq -> items--;
	if (pq -> items == 0)
		pq -> rear = NULL;

	return true;
}

void EmptyTheQueue (Queue * pq)
{
	Item dummy;

	while (!QueueIsEmpty (pq))
		DeQueue (&dummy, pq);
}

static void CopyToNode (Item item, Node * pq)
{
	pq -> item = item;
}

static void CopyToItem (Node * pn, Item * pi)
{
	*pi = pn -> item;
}
