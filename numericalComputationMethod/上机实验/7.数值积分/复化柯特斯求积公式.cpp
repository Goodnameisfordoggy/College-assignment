/***
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2024-05-11 17:07:47
 * @FilePath: \c++\numericalComputationMethod\�ϻ�ʵ��\7.��ֵ����\��������˹�����ʽ.cpp
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

// ���屻������
double func(double x)
{
    if (x == -1)
    {
        return INFINITY; // ��xΪ-1ʱ������������ֱ�ӷ���1/0�ļ���ֵ
    }
    else
    {
        return 1.0 / sqrt(1 + x * x * x);
    }
}

double func2(double x)
{
    if (x == 0)
    {
        return 1.0; // ��xΪ0ʱ������������ֱ�ӷ���sin(0)/0�ļ���ֵ1
    }
    else
    {
        return sin(x) / x;
    }
}

/**
 *@name Cotes����������˹��ʽ
 *@param1 below����������
 *@param2 upper����������
 *@param3 n������������ĸ���
 **/
double Cotes(double (*func)(double), double below, double upper, int n)
{
    double h = (upper - below) / n;
    double S1 = 0;
    double S2 = 0;
    double S3 = 0;
    double S4 = 0;
    double x = below + h / 4;

    for (int i = 0; i < n; i++)
    {
        // ���������1/4����ֵ 1/4~(n-3/4)��n��
        S1 += func(x);
        x += h;
    }

    x = below + h / 2;
    for (int i = 0; i < n; i++)
    {
        // ���������1/2����ֵ 1/2~(n-1/2)��n��
        S2 += func(x);
        x += h;
    }

    x = below + 3 * h / 4;
    for (int i = 0; i < n; i++)
    {
        // ���������3/4����ֵ 3/4~(n-1/4)��n��
        S3 += func(x);
        x += h;
    }

    x = below + h;
    for (int i = 1; i < n; i++)
    {
        // ���������3/4����ֵ 1~(n-1)��n-1��
        S4 += func(x);
        x += h;
    }

    return (h / 90) * (7 * func(below) + 32 * S1 + 12 * S2 + 32 * S3 + 14 * S4 + 7 * func(upper));
}

int main()
{

    double target_precision = 1e-6; // Ŀ�꾫��
    int n = 0;                      // ��ʼ������
    double prev_integral_approximation = 0.0;
    double integral_approximation = Cotes(func, 0.0, 1.0, n);

    while (1)
    {
        if (fabs(integral_approximation - prev_integral_approximation) < target_precision)
        {
            printf("c(%d)=%.6f,", n - 2, Cotes(func, 0.0, 1.0, n - 2));
            printf("c(%d)=%.6f,n=%dʱ��6λ��Ч����\n", n, integral_approximation, n);
            break;
        }
        prev_integral_approximation = integral_approximation;
        n += 2; // ÿ������2��ȷ��nΪż��
        integral_approximation = Cotes(func, 0.0, 1.0, n);
    }

    n = 0;
    prev_integral_approximation = 0.0;
    integral_approximation = Cotes(func2, 0.0, 5.0, n);
    while (1)
    {
        if (fabs(integral_approximation - prev_integral_approximation) < target_precision)
        {
            printf("c(%d)=%.6f,", n - 2, Cotes(func2, 0.0, 5.0, n - 2));
            printf("c(%d)=%.6f,n=%dʱ��6λ��Ч����\n", n, integral_approximation, n);
            break;
        }
        prev_integral_approximation = integral_approximation;
        n += 2; // ÿ������2��ȷ��nΪż��
        integral_approximation = Cotes(func2, 0.0, 5.0, n);
    }

    return 0;
}
