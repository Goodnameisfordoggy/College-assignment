#include <stdio.h>
int main()
{
	int a[2][3];
	int i, x, y;
	for (y = 0; y < 2; y++)
	{
		for (x = 0; x < 3; x++)
		{
			scanf("%d", &a[y][x]);
		}
	}
	printf("array a:\n");
	for (y = 0; y < 2; y++)
	{
		for (x = 0; x < 3; x++)
		{
			printf("%5d", a[y][x]);
		}
		printf("\n");
	}
	printf("array b:\n");
	for (x = 0; x < 3; x++)
	{
		for (y = 0; y < 2; y++)
		{
			printf("%5d", a[y][x]);
		}
		printf("\n");
	}
}