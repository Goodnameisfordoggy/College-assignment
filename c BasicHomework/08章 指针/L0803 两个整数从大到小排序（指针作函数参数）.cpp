#include <stdio.h>
void max_min(int *n_1, int *n_2);
int main()
{
	int a, b;
	int *num_1, *num_2;
	scanf("%d,%d", &a, &b);
	num_1 = &a;
	num_2 = &b;
	max_min(num_1, num_2);
	printf("max=%d,min=%d", *num_1, *num_2);
	return 0;
}
void max_min(int *n_1, int *n_2)
{
	int t;
	if (*n_1 < *n_2)
	{
		t = *n_1;
		*n_1 = *n_2;
		*n_2 = t;
	}
}