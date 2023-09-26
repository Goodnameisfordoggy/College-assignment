#include <stdio.h>
#define N 6
#pragma warning(disable : 4996)
void inv(int *x, int n);
int main()
{
	int a[N];
	int *p, i;
	p = a;
	for (; p < a + N; p++)
	{
		scanf("%d", p);
	}
	p = a;
	inv(a, 6);
	p = a;
	for (i = 0; i < N; i++)
	{
		printf("%6d", *p++);
	}
	return 0;
}
void inv(int *x, int n)
{
	int *i, *j, temp, m;
	i = x;
	j = x + N - 1;
	m = (n - 1) / 2;
	for (; i <= x + m; i++, j--)
	{
		temp = *i;
		*i = *j;
		*j = temp;
	}
}