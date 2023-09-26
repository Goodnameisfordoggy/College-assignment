#include <stdio.h>
#pragma warning(disable : 4996)
#define N 10
void input(int *x, int n);
void output(int *x, int n);
void sort(int *x, int n);
int main()
{
	int a[N];
	int *p = a;
	input(a, N);
	sort(a, N);
	output(a, N);
	return 0;
}
void input(int *x, int n)
{
	int i;
	for (i = 0; i < N; i++)
	{
		scanf("%d", x + i);
	}
}
void output(int *x, int n)
{
	int i;
	for (i = 0; i < N; i++)
	{
		printf("%5d", *(x + i));
	}
}
void sort(int *x, int n)
{
	int i, j, temp;
	for (j = 0; j < N - 1; j++)
	{
		for (i = 0; i < N - 1 - j; i++)
		{
			if (*(x + i) < *(x + i + 1))
			{
				temp = *(x + i);
				*(x + i) = *(x + i + 1);
				*(x + i + 1) = temp;
			}
		}
	}
}
