#include <stdio.h>

int main()
{
	int i;
	float sum = 100, h;
	h = sum / 2;
	for (i = 1; i < 10; i++)
	{
		sum += h * 2;
		h = h / 2;
	}
	printf("sum=%.2f,h=%.2f", sum, h);
}
