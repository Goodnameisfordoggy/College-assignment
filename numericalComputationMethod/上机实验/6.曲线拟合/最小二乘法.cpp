/***
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2024-05-14 14:04:33
 * @FilePath: \c++\numericalComputationMethod\�ϻ�ʵ��\6.�������\2.cpp
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

// �������ݵ������
#define N 15

// �������ݵ������
double x[N] = {1, 1.5, 2, 2.5, 3, 3.5, 4, 4.5, 5, 5.5, 6, 6.5, 7, 7.5, 8};
double y[N] = {33.4, 79.50, 122.65, 159.05, 189.15, 214.15, 238.65, 252.50, 267.55, 280.50, 296.65, 301.40, 310.40, 318.15, 325.15};

// ������������ϲ���
void parabola_fit(double x[], double y[], double *a, double *b, double *c)
{
    double sum_x = 0, sum_y = 0, sum_x2 = 0, sum_x3 = 0, sum_x4 = 0, sum_xy = 0, sum_x2y = 0;

    // ��������
    for (int i = 0; i < N; i++)
    {
        double xi = x[i];
        double yi = y[i];
        sum_x += xi;
        sum_y += yi;
        sum_x2 += xi * xi;
        sum_x3 += xi * xi * xi;
        sum_x4 += xi * xi * xi * xi;
        sum_xy += xi * yi;
        sum_x2y += xi * xi * yi;
    }

    // ���췽����
    double A[3][3] = {
        {N, sum_x, sum_x2},
        {sum_x, sum_x2, sum_x3},
        {sum_x2, sum_x3, sum_x4}};
    double B[3] = {sum_y, sum_xy, sum_x2y};

    // ʹ�ÿ���Ĭ����ⷽ����
    double detA = A[0][0] * (A[1][1] * A[2][2] - A[2][1] * A[1][2]) -
                  A[0][1] * (A[1][0] * A[2][2] - A[2][0] * A[1][2]) +
                  A[0][2] * (A[1][0] * A[2][1] - A[2][0] * A[1][1]);

    double invDetA = 1.0 / detA;

    *a = ((B[0] * (A[1][1] * A[2][2] - A[2][1] * A[1][2]) -
           A[0][1] * (B[1] * A[2][2] - A[2][1] * B[2]) +
           A[0][2] * (B[1] * A[2][1] - A[1][1] * B[2])) *
          invDetA);

    *b = ((A[0][0] * (B[1] * A[2][2] - A[2][1] * B[2]) -
           B[0] * (A[1][0] * A[2][2] - A[2][0] * A[1][2]) +
           A[0][2] * (A[1][0] * B[2] - B[1] * A[2][0])) *
          invDetA);

    *c = ((A[0][0] * (A[1][1] * B[2] - B[1] * A[2][1]) -
           A[0][1] * (A[1][0] * B[2] - B[1] * A[2][0]) +
           B[0] * (A[1][0] * A[2][1] - A[2][0] * A[1][1])) *
          invDetA);
}

// ����ָ��������ϲ���
void exponential_fit(double x[], double y[], double *a, double *b)
{
    double sum_x = 0, sum_y = 0, sum_x2 = 0, sum_xy = 0;

    for (int i = 0; i < N; i++)
    {
        double xi = x[i];
        double yi = log(y[i]);
        sum_x += xi;
        sum_y += yi;
        sum_x2 += xi * xi;
        sum_xy += xi * yi;
    }

    double denominator = (N * sum_x2) - (sum_x * sum_x);
    *b = ((N * sum_xy) - (sum_x * sum_y)) / denominator;
    *a = exp((sum_y - (*b) * sum_x) / N);
}

int main()
{
    double a1, b1, c1; // �����߲���
    double a2, b2;     // ָ�����߲���

    // ������������ϲ���
    parabola_fit(x, y, &a1, &b1, &c1);
    printf("�����߷���: y = %.6f + %.6fx + %.6fx^2\n", a1, b1, c1);

    // ����ָ��������ϲ���
    exponential_fit(x, y, &a2, &b2);
    printf("ָ�����߷���: y = %.4fe^(%.6fx)\n", a2, b2);

    return 0;
}
