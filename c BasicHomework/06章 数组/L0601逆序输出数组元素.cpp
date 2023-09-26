#include <stdio.h>

int main()
{
	int a[10], i, j, t;
	for (i = 0; i < 10; i++)
	{
		scanf("%d", &a[i]);
	}

	for (i = 0, j = 9; i<5, j> 4; i++, j--)
	{
		t = a[i];
		a[i] = a[j];
		a[j] = t;
	}
	for (i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}
}
