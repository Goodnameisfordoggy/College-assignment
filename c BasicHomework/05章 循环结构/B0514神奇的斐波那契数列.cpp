#include <stdio.h>
int main()
{
	float a[20] = {1, 1}, x;
	int i, n;
	for (i = 2; i < 20; i++)
	{
		a[i] = a[i - 1] + a[i - 2];
	}
	scanf("%d", &n);
	x = a[n - 1] / a[n];
	printf("%.5f", x);
	return 0;
}