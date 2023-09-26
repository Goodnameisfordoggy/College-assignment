#include <stdio.h>
int main()
{
	int num, a, b, c;

	for (num = 100; num <= 999; num++)
	{
		a = num / 100;
		b = num / 10 % 10;
		c = num % 10;
		if (num == a * a * a + b * b * b + c * c * c)
			printf("%d ", num);
	}
	return 0;
}