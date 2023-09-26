#include <stdio.h>
main()
{
	int i = 0, sum = 0;
	while (i <= 100)
	{
		sum = sum + i;
		i = i + 2;
	}
	printf("%d", sum);
}