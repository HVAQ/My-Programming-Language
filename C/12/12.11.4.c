#include <stdio.h>
int show_num (int);

int main (void)
{
	int m;
	int n = 0;

	printf ("请输入要调用函数的次数: ");
	scanf ("%d", &m);
	for (int i = 0; i < m; i++)
		n = show_num (n);
	printf ("函数被调用了%d次\n", n);

	return 0;
}

int show_num (int n)
{
	++n;

	return n;
}
