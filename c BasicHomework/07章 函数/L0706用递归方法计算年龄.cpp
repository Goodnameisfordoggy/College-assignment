#include <stdio.h>
#pragma warning(disable : 4996)
void main()
{
	int age(int n);
	int n;
	scanf("%d", &n);
	printf("%d\n", age(n));
}
int age(int n)
{
	int c;
	if (n == 1)
	{
		c = 10;
	}
	else
	{
		c = age(n - 1) + 2;
	}
	return (c);
}
