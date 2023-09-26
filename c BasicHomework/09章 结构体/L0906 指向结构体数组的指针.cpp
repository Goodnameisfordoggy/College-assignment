#include <stdio.h>
#pragma warning(disable : 4996)
// 988 ZhangBo 88
// 989 LiuYue 89
// 990 WangXu 86
struct Student
{
	int num;
	char name[20];
	float score;
};
int main()
{
	struct Student stu[3];
	struct Student *p;
	p = stu;
	int i;
	for (i = 0; i < 3; i++)
	{
		scanf("%d%s%f", &p->num, p->name, &p->score);
		p++;
	}
	p = stu;
	for (i = 0; i < 3; i++)
	{
		printf("%d,%s,%.2f\n", p->num, p->name, p->score);
		p++;
	}
	return 0;
}