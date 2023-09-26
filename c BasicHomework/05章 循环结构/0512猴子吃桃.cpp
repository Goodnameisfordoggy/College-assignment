#include <stdio.h>

int main()
{
	int i, n;
	scanf("%d", &n);
	for (i = 1; n > 1; n--)
	{
		i = (i + 1) * 2;
	}
	printf("%d", i);
}
