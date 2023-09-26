#include <stdio.h>
int main()
{
	int a = 2, b = 1, c, n, i;
	double s = 0;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		s += (1.0 * a / b);
		c = b;
		b = a;
		a = a + c;
	}
	printf("%.2f", s);
	return 0;
}