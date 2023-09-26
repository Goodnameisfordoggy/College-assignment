#include <stdio.h>
#pragma warning(disable : 4996)
struct Student
{
	int num;
	char name[20];
	float score;
};
int main()
{
	struct Student stu_1;
	struct Student *p;
	p = &stu_1;
	scanf("%d%s%f", &p->num, &p->name, &p->score);
	printf("%d,%s,%.2f", p->num, p->name, p->score);
}
