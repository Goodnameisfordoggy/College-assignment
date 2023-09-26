#include <stdio.h>
main()
{
	int m, n, i = 0, sum = 0;
	scanf("%d,%d", &m, &n);
	if (m <= n)
	{
		for (; i <= n - m; i++)
			sum += i + m;
	}
	printf("sum=%d", sum);
}