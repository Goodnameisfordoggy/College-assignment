#include <stdio.h>
int main()
{
	int a[3][3], x, y, sum;
	for (y = 0; y < 3; y++)
	{
		for (x = 0; x < 3; x++)
		{
			scanf("%d", &a[y][x]);
		}
	}
	sum = a[0][0] + a[1][1] + a[2][2];
	printf("sum=%d", sum);
	return 0;
}