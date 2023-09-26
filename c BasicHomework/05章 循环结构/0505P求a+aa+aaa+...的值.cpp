#include <stdio.h>
int main()
{
	int a, n, i, temp = 0, sum = 0;
	scanf("%d%d", &a, &n);
	for (i = 1; i <= n; i++)
	{
		temp = temp * 10 + a;
		sum = sum + temp;
	}
	printf("%d", sum);
}