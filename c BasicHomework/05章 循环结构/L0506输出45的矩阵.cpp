#include <stdio.h>

int main()
{
	int n, x;
	for (n = 1; n <= 20; n++, x++)
	{
		printf("%5d", n);
		if (x % 5 == 0)
		{
			printf("\n");
		}
	}
}
