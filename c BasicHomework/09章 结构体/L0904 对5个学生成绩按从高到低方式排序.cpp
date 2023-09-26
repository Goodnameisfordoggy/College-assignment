#include <stdio.h>
#pragma warning(disable : 4996)
/*
  0982 Zhang_Jingpeng 79
  0983 Gu_Ran 81
  1000 Li_Yanxin 76
  1018 Fu_JiaHao 77
  1019 Wang_Ruikang 80
  */
struct Student
{
    int num;
    char name[20];
    float score;
} stu[5];
int main()
{
    int i;
    for (i = 0; i < 5; i++)
    {
        scanf("%d%s%f", &stu[i].num, stu[i].name, &stu[i].score);
    }
    int j, k, n = 5;
    struct Student temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            k = i;
            if (stu[j].score > stu[k].score)
            {
                temp = stu[j];
                stu[j] = stu[k];
                stu[k] = temp;
            }
        }
    }
    for (i = 0; i < 5; i++)
    {
        printf("%6d,%15s,%6.2f\n", stu[i].num, stu[i].name, stu[i].score);
    }
    return 0;
}