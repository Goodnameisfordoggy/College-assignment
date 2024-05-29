/*** 
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2024-05-11 21:39:42
 * @FilePath: \c++\numericalComputationMethod\�ϻ�ʵ��\1.�����������ֵ�ȶ���\1.cpp
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
double f(double x, int n)
{
    return pow(x, n) / (4 * x + 1);
}

// ���㶨����
double integrate(int n, double a, double b, int N)
{
    double h = (b - a) / N;
    double sum = 0.5 * (f(a, n) + f(b, n));

    for (int i = 1; i < N; i++)
    {
        double x = a + i * h;
        sum += f(x, n);
    }

    return sum * h;
}

int main()
{
    double a = 0;   // ����
    double b = 1;   // ����
    int n_max = 40; // ָ������
    int N = 1000;   // ����������
    double result;

    for (int n = 1; n <= n_max; n++)
    {
        result = integrate(n, a, b, N);
        printf("n=%d, I=%lf\n", n, result);
    }

    return 0;
}
