#include <stdio.h>
#pragma warning(disable : 4996)
#define N 6
int main()
{
	void input(int array[], int n);
	void sort(int array[], int n);
	void output(int array[], int n);
	int num[N];
	input(num, N);
	sort(num, N);
	output(num, N);
	return 0;
}
void input(int array[], int n)
{
	int i;
	for (i = 0; i < N; i++)
	{
		scanf("%d", &array[i]);
	}
}
void sort(int array[], int n)
{
	int i, j, temp;
	for (j = 0; j < N - 1; j++)
	{
		for (i = 0; i < N - 1 - j; i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
			}
		}
	}
}
void output(int array[], int n)
{
	int i;
	for (i = 0; i < N; i++)
	{
		printf("%d ", array[i]);
	}
}