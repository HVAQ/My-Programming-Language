#include <stdio.h>
#include <stdlib.h>
int main (int argc, char **argv)
{
	if(argc > 2){
		double m = atof(argv[1]);
		int n = atoi(argv[2]);
		int i;

		for (i = 1; i < n; i++)
			m *= m;
		if(n == 0)
			m = 1;
		printf("%s 的 %d 次幂为 %g\n", argv[1], n, m);
	}
	else
		puts("参数不足");
	
	return 0;
}
