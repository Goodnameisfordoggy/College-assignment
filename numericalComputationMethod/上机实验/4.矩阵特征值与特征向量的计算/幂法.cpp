/***
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2024-05-12 12:02:15
 * @FilePath: \c++\numericalComputationMethod\上机实验\4.矩阵特征值与特征向量的计算\幂法.cpp
 * @Description:
 * @
 * @				*		写字楼里写字间，写字间里程序员；
 * @				*		程序人员写程序，又拿程序换酒钱。
 * @				*		酒醒只在网上坐，酒醉还来网下眠；
 * @				*		酒醉酒醒日复日，网上网下年复年。
 * @				*		但愿老死电脑间，不愿鞠躬老板前；
 * @				*		奔驰宝马贵者趣，公交自行程序员。
 * @				*		别人笑我忒疯癫，我笑自己命太贱；
 * @				*		不见满街漂亮妹，哪个归得程序员？
 * @Copyright (c) 2024 by HDJ, All Rights Reserved.
 */
#include <stdio.h>
#include <math.h>

#define N 4
#define EPS 1e-6
#define KM 30

double MaxValue(double x[], int n)
{
    double Max = x[0];
    int i;
    for (i = 1; i < n; i++)
    {
        if (fabs(x[i]) > fabs(Max))
        {
            Max = x[i];
        }
    }
    return Max;
}

void PowerMethod(double A[N][N])
{
    double U[N], V[N], r1, r2, temp;
    int i, j, k = 0;
    for (i = 0; i < N; i++)
    {
        U[i] = 1;
    }
    while (k < KM)
    {
        k++;
        for (i = 0; i < N; i++)
        {
            temp = 0;
            for (j = 0; j < N; j++)
            {
                temp += A[i][j] * U[j];
            }
            V[i] = temp;
        }
        temp = MaxValue(V, N);
        for (i = 0; i < N; i++)
        {
            U[i] = V[i] / temp;
        }
        if (k == 1)
        {
            r1 = temp;
        }
        else
        {
            r2 = temp;
            if (fabs(r2 - r1) < EPS)
            {
                break;
            }
            r1 = r2;
        }
    }
    printf("λ1=%f\n", r2);
    for (i = 0; i < N; i++)
    {
        printf("x[%d]=%f\n", i + 1, U[i]);
    }
}

int main()
{
    double A[N][N] = {{25, -41, 10, -6}, {-41, 68, -17, 10}, {10, -17, 5, -3}, {-6, 10, -3, 2}};
    PowerMethod(A);
    return 0;
}
