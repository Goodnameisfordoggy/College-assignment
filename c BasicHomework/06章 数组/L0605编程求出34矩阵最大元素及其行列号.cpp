#include <stdio.h>
int main()
{
	int a[3][4], i, x, y;
	int max, row, col;
	for (y = 0; y < 3; y++)
	{
		for (x = 0; x < 4; x++)
		{
			scanf("%d", &a[y][x]);
		}
	}
	max = a[0][0];
	row = 0, col = 0;
	for (y = 0; y < 3; y++)
	{
		for (x = 0; x < 4; x++)
		{
			if (a[y][x] > max)
			{
				max = a[y][x];
				row = y;
				col = x;
			}
		}
	}
	printf("max=%d,row=%d,col=%d", max, row, col);
}