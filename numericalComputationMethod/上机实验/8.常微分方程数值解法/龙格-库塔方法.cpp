/***
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2024-05-11 16:32:44
 * @FilePath: \c++\algorithmsAnalysisAndDesign\�ϻ�ʵ��\8.��΢�ַ�����ֵ�ⷨ\1.cpp
 * @Description: Copy from textbook
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
#define N 10

float func(float x, float y)
{
    return 1.0 / (1 + y * y);
}

void Runge_Kutta(float (*func)(float x, float y), float a, float b, float y0)
{
    float x = a, y = y0, k1, k2, k3, k4;
    float h = (b - a) / N;
    int i;
    printf("x[0]=%f\ty[0]=%f\n", x, y);
    for (i = 1; i <= N; i++)
    {
        k1 = (*func)(x, y);
        k2 = (*func)(x + h / 2, y + h * k1 / 2);
        k3 = (*func)(x + h / 2, y + h * k2 / 2);
        k4 = (*func)(x + h, y + h * k3);
        y = y + h * (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        x = a + i * h;
        printf("x[%d]=%f\ty[%d]=%f\n", i, x, i, y);
    }
}

int main()
{
    float x_min = 0, x_max = 1.0, y0 = 0;
    Runge_Kutta(func, x_min, x_max, y0);
    return 0;
}