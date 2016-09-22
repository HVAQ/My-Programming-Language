#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

static void CopyToItem (char item, Node * plist);

void ToFirst (Stack * plist)
{
	plist = NULL;
}

bool IsFull (const Stack * plist)
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

bool IsEmpty (const Stack * plist)
{
	return plist->head == NULL;
}

bool AddToString (char ch, Stack * plist)
{
	Node * pt;

	if (IsFull(plist))
		return false;

	pt = (Node *) malloc (sizeof (Node));
	CopyToItem (ch, pt);
	pt->next = NULL;
	if (IsEmpty(plist))
		plist->head = plist->end = pt;
	else
	{
		pt->next = plist->head;
		plist->head = pt;
	}

	return true;
}

void Tranverse (Stack * plist, void (*pfun) (char temp))
{
	Node * pnode = plist->head;

	while (pnode != NULL)
	{
		(*pfun) (pnode->item);
		pnode = pnode->next;
	}
	putchar ('\n');
}

void ToEmpty (Stack * plist)
{
	Node * pn = plist->head;
	Node * temp;

	while (pn != NULL)
	{
		temp = pn->next;
		free (pn);
		pn = temp;
	}
}

static void CopyToItem (char ch, Node * pt)
{
	pt->item = ch;
}
