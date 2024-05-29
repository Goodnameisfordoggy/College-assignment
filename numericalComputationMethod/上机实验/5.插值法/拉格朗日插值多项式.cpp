/*** 
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2024-05-10 23:01:05
 * @FilePath: \c++\algorithmsAnalysisAndDesign\�ϻ�ʵ��\5.��ֵ��\�������ղ�ֵ����ʽ.cpp
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

// ����׳˵ĺ���
double factorial(int n)
{
    double fact = 1.0;
    for (int i = 1; i <= n; ++i)
    {
        fact *= i;
    }
    return fact;
}

// �������ʽϵ���ĺ���
double binomial_coefficient(int n, int k)
{
    return factorial(n) / (factorial(k) * factorial(n - k));
}

// �����������ջ������ĺ���
double lagrange_basis(double x, double xi[], int n, int j)
{
    double l = 1.0;
    for (int m = 0; m < n; ++m)
    {
        if (m != j)
        {
            l *= (x - xi[m]) / (xi[j] - xi[m]);
        }
    }
    return l;
}

// ִ���������ղ�ֵ�ĺ���
double lagrange_interpolation(double x, double xi[], double yi[], int n)
{
    double result = 0.0;
    for (int j = 0; j < n; ++j)
    {
        result += yi[j] * lagrange_basis(x, xi, n, j);
    }
    return result;
}

int main()
{
    // ��������
    double xi[] = {0.30, 0.42, 0.50, 0.58, 0.66, 0.72};
    double yi[] = {1.04403, 1.08462, 1.11803, 1.15603, 1.19817, 1.23223};
    int n = sizeof(xi) / sizeof(xi[0]);

    // ��Ҫ�����xֵ
    double x1 = 0.46;
    double x2 = 0.55;
    double x3 = 0.60;

    // �����������ղ�ֵ
    double y1 = lagrange_interpolation(x1, xi, yi, n);
    double y2 = lagrange_interpolation(x2, xi, yi, n);
    double y3 = lagrange_interpolation(x3, xi, yi, n);

    // ������
    printf("x = %.2fʱ��y= %.6f\n", x1, y1);
    printf("x = %.2fʱ��y= %.6f\n", x2, y2);
    printf("x = %.2fʱ��y= %.6f\n", x3, y3);

    return 0;
}
