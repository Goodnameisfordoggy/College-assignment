#include <stdio.h>

int fact(int n)
{
	if (n == 1 || n == 2)
		return 1;
	else
		return fact(n - 1) + fact(n - 2);
}
int main()
{
	int n, m, x;
	for (n = 1, x = 1; n <= 40; n++, x++)
	{
		m = fact(n);
		printf("%12d", m);
		if (x % 4 == 0)
		{
			printf("\n");
		}
	}
}