#include <stdio.h>
#define N 5
int main()
{
	int a[N], i;
	int *p;
	for (i = 0; i < N; i++)
	{
		scanf("%d", &a[i]);
	}
	for (p = a; p < (a + N); p++)
	{
		printf("%5d", *p);
	}
	printf("\n");
	return 0;
}