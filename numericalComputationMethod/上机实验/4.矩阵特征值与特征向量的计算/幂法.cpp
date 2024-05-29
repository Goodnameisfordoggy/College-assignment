/***
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2024-05-12 12:02:15
 * @FilePath: \c++\numericalComputationMethod\�ϻ�ʵ��\4.��������ֵ�����������ļ���\�ݷ�.cpp
 * @Description:
 * @
 * @				*		д��¥��д�ּ䣬д�ּ������Ա��
 * @				*		������Աд�������ó��򻻾�Ǯ��
 * @				*		����ֻ���������������������ߣ�
 * @				*		��������ո��գ����������긴�ꡣ
 * @				*		��Ը�������Լ䣬��Ը�Ϲ��ϰ�ǰ��
 * @				*		���۱������Ȥ���������г���Ա��
 * @				*		����Ц��߯��񲣬��Ц�Լ���̫����
 * @				*		��������Ư���ã��ĸ���ó���Ա��
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
    printf("��1=%f\n", r2);
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
