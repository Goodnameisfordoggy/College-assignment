#include <stdio.h>
int main()
{
	int a[6], i, max, min, ind1, ind2;
	for (i = 0; i < 6; i++)
	{
		scanf("%d", &a[i]);
	}
	max = min = a[0];
	for (i = 0; i < 6; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
			ind1 = i;
		}
		if (a[i] < min)
		{
			min = a[i];
			ind2 = i;
		}
	}
	printf("max=%d,ind1=%d;min=%d,ind2=%d", max, ind1, min, ind2);
}