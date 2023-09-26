#include <stdio.h>
#pragma warning(disable : 4996)
#define N 5
/*
  1004 ZhangShuyu 85 80 79
  1008 LiShuang 85 83 82
  1006 ChenHongyu 83 79 80
  1013 ChenDi 79 85 76
  1001 GuoTengyang 75 79 79
*/
struct Student
{
	int num;
	char name[20];
	float s_1, s_2, s_3;
	float aver;
} stu[N];
void input(struct Student *arr, int n);
void output(struct Student *arr, int n);
void average(struct Student *arr, int n);
int main()
{
	struct Student *p;
	p = stu;
	input(p, N);
	average(p, N);
	output(p, N);
	return 0;
}
void input(struct Student *arr, int n)
{
	int i;
	for (i = 0; i < N; i++)
	{
		scanf("%d%s%f%f%f", &arr[i].num, arr[i].name, &arr[i].s_1, &arr[i].s_2, &arr[i].s_3);
	}
}
void output(struct Student *arr, int n)
{
	int i = 0;
	printf("The highest score:\n");
	printf("%d,%s,%.2f,%.2f,%.2f,%.2f", arr[i].num, arr[i].name, arr[i].s_1, arr[i].s_2, arr[i].s_3, arr[i].aver);
}
void average(struct Student *arr, int n)
{
	int i, j;
	for (i = 0; i < N; i++)
	{
		arr[i].aver = (arr[i].s_1 + arr[i].s_2 + arr[i].s_3) / 3.0;
	}
	float max_aver = arr[0].aver;
	int k;
	for (i = 0; i < N; i++)
	{
		if (arr[i].aver > max_aver)
		{
			max_aver = arr[i].aver;
			k = i;
		}
	}
	// printf("%.2f,%d", max_aver, k);
	struct Student temp;
	temp = arr[k];
	arr[k] = arr[0];
	arr[0] = temp;
	return;
}