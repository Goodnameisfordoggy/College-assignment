#include <stdio.h>
int main()
{
	int a[10], i, j, t;
	for (i = 0; i < 10; i++)
	{
		scanf("%d", &a[i]);
	}
	for (j = 0; j < 9; j++)
	{
		for (i = 0; i < 9 - j; i++)
		{
			if (a[i] > a[i + 1])
			{
				t = a[i];
				a[i] = a[i + 1];
				a[i + 1] = t;
			}
		}
	}
	for (i = 0; i < 10; i++)
	{
		printf("%5d", a[i]);
	}
}