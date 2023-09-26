#include <stdio.h>
#pragma warning(disable : 4996)
int main()
{
	int a, b, t;
	int *num_1, *num_2;
	scanf("%d,%d", &a, &b);
	printf("a=%d,b=%d,", a, b);
	num_1 = &a;
	num_2 = &b;
	if (a < b)
	{
		t = *num_1;
		*num_1 = *num_2;
		*num_2 = t;
	}
	printf("max=%d,min=%d", *num_1, *num_2);
	return 0;
}