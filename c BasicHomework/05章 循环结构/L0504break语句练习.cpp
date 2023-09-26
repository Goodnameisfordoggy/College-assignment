#include <stdio.h>
int main()
{
	float amount, aver, total;
	int num;
	for (num = 1, total = 0; num <= 1000; num++)
	{
		scanf("%f\n", &amount);
		total += amount;
		if (total >= 100000)
			break;
	}
	aver = total / num;
	printf("num=%d,aver=%10.2f", num, aver);
	return 0;
}