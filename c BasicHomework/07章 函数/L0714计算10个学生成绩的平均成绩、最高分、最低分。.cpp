#include <stdio.h>
#pragma warning(disable : 4996)
void sort(float array[], int n);
int main()
{
	float ar[10];
	int i;
	for (i = 0; i < 10; i++)
	{
		scanf("%f", &ar[i]);
	}
	sort(ar, 10);
}
void sort(float arr[], int n)
{
	float max, min, average, sum = 0;
	max = min = arr[0];
	int i;
	for (i = 0; i < 10; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	for (i = 0; i < 10; i++)
	{
		if (arr[i] < min)
		{
			min = arr[i];
		}
	}
	for (i = 0; i < 10; i++)
	{
		sum = sum + arr[i];
		average = sum / 10.0;
	}
	printf("max=%.2f,min=%.2f,average=%.2f", max, min, average);
}