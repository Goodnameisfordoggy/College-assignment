#include <stdio.h>
#pragma warning(disable : 4996)
void main()
{
	int max_4(int a, int b, int c, int d);
	int max, a, b, c, d;
	scanf("%d%d%d%d", &a, &b, &c, &d);
	max = max_4(a, b, c, d);
	printf("max=%d", max);
}
int max_4(int a, int b, int c, int d)
{
	int max(int a, int b);
	int m;
	m = max(a, b);
	m = max(m, c);
	m = max(m, d);
	return (m);
}
int max(int x, int y)
{
	if (x > y)
	{
		return (x);
	}
	else
	{
		return (y);
	}
}