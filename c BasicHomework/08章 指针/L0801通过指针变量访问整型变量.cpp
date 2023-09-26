#include <stdio.h>
#pragma warning(disable : 4996)
int main()
{
	int a, b;
	int *pointer_1, *pointer_2;
	scanf("%d%d", &a, &b);
	pointer_1 = &a;
	pointer_2 = &b;
	printf("a=%d,b=%d\n", a, b);
	printf("*pointer_1=%d,pointer_2=%d\n", *pointer_1, *pointer_2);
	return 0;
}