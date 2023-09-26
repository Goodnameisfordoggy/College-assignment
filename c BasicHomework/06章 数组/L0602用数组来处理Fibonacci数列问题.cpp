#include <stdio.h>
int main()
{
	int a[100] = {1, 1}, i, n, x;
	scanf("%d", &n);
	for (i = 2; i < n; i++)
	{
		a[i] = a[i - 1] + a[i - 2];
	}
	for (i = 0, x = 1; i < n; i++, x++)
	{
		printf("%12d", a[i]);
		if (x % 5 == 0)
		{
			printf("\n");
		}
	}
	return 0;
}