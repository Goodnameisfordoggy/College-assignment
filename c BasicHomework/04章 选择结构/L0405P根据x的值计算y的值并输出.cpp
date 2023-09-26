#include <stdio.h>
main()
{
	int x, y;
	scanf("%d", &x);
	if (x < 0)
	{
		y = -1;
		printf("x=%d,y=%d", x, y);
	}
	else if (x == 0)
	{
		y = 0;
		printf("x=%d,y=%d", x, y);
	}
	else
	{
		y = 1;
		printf("x=%d,y=%d", x, y);
	}
}