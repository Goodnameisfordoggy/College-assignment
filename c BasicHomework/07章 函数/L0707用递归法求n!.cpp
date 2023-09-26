#include <stdio.h>
#pragma warning(disable : 4996)
unsigned long long factorial(int a)
{
	unsigned long long b;
	if (a == 1 || a == 0)
		b = 1;
	else
		b = factorial(a - 1) * a;
	return (b);
}
int main()
{
	unsigned long long i;
	int n;
	scanf("%d", &n);
	i = factorial(n);
	printf("%llu\n", i);
}
