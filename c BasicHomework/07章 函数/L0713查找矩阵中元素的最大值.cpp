#include <stdio.h>
#pragma warning(disable : 4996)
int main()
{
	void input(int arr[][4], int n);
	int p[3][4];
	input(p, 3);
	int i, j, max;
	max = p[0][0];
	for (j = 0; j < 3; j++)
	{
		for (i = 0; i < 4; i++)
		{
			if (p[j][i] > max)
			{
				max = p[j][i];
			}
		}
	}
	for (j = 0; j < 3; j++)
	{
		for (i = 0; i < 4; i++)
		{
			printf("%5d", p[j][i]);
		}
		printf("\n");
	}
	printf("max=%d", max);
	return 0;
}
void input(int arr[][4], int n)
{
	int i, j;
	for (j = 0; j < 3; j++)
	{
		for (i = 0; i < 4; i++)
		{
			scanf("%d", &arr[j][i]);
		}
	}
}