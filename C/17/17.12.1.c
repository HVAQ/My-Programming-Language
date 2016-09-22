#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TSIZE 45  // 存放名片的数组大小

struct film {
	char title[TSIZE];
	int rating;
	struct film * front;  // 存放链表的上一个结构
	struct film * next;  // 存放链表的下一个结构
};

int main (void)
{
	struct film * head = NULL;
	struct film * final = NULL;
	struct film * prev, * current;
	char input[TSIZE];

	// 收集并存储信息
	puts ("Enter the first movie title: ");
	while (gets (input) != NULL && input [0] != '\0')
	{
		current = (struct film *) malloc (sizeof (struct film));
		if (head == NULL)  // 如果第一个结构为空
		{
			head = current;  // 将现在的结构赋值给第一个结构
			current -> front = NULL;  // 此时现在结构的上一个结构为空
		}
		else
		{
			prev -> next = current;  // 将现在结构的地址赋值给上一个结构指向现在结构的指针
			current -> front = prev; // 将上个结构的地址赋值给现在结构指向上一个结构的指针
		}
		current -> next = NULL;  // 将现在结构指向下个结构的指针暂设为空
		strcpy (current -> title, input);
		puts ("Enter your rating <0-10>: ");
		scanf ("%d", &current -> rating);
		while (getchar() != '\n')
			continue;
		puts ("Enter next movie title (empty line to stop): ");
		prev = current;
	}
	// 设置末元素
	if (head != NULL)
	{
		// 设置末元素
		final = prev;

		// 正序给出电影列表
		printf ("1: Here is the movie list: \n");
		current = head;
		while (current != NULL)
		{
			printf ("Movie: %s  Rating: %d\n", current -> title, current -> rating);
			current = current -> next;
		}

		// 逆序给出电影列表
		printf ("2: Here is the movie list: \n");
		current = final;
		while (current != NULL)
		{
			printf ("Movie: %s   Rating: %d\n", current -> title, current -> rating);
			current = current -> front;
		}
	}
	else
		puts ("No data entered.");

	// 任务完成, 释放内存
	current = head;
	while (current != NULL)
	{
		free (current);
		current = current -> next;
	}
	printf ("Bye!\n");

	return 0;
}
