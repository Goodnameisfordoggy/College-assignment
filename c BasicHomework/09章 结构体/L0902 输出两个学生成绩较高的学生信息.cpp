#include <stdio.h>
#pragma warning(disable : 4996)
struct Student
{
	long num;
	char name[20];
	double score;
};
int main()
{
	int i;
	struct Student stu[2];
	for (i = 0; i < 2; i++)
	{
		scanf("%ld%s%lf", &stu[i].num, stu[i].name, &stu[i].score);
	}
	if (stu[0].score > stu[1].score)
	{
		printf("The higher score is:\n%ld %s %6.2lf", stu[0].num, stu[0].name, stu[0].score);
	}
	else if (stu[0].score < stu[1].score)
	{
		printf("The higher score is:\n%ld %s %6.2lf", stu[1].num, stu[1].name, stu[1].score);
	}
	else
	{
		printf("The higher score is:\n%ld %s %6.2lf\n%ld %s %6.2lf", stu[0].num, stu[0].name, stu[0].score, stu[1].num, stu[1].name, stu[1].score);
	}
	return 0;
}