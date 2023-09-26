#include <stdio.h>
int main()
{
	int n, m, i;
	scanf("%d,%d", &m, &n);
	for (; m <= n; m++)
	{
		for (i = 2; i <= n; i++)
		{
			if (m % i == 0)
			{
				break;
			}
		}
		if (m == i)
		{
			printf("%d ", m);
		}
	}
}