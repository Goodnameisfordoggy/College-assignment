/***
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2024-05-11 15:43:45
 * @FilePath: \c++\algorithmsAnalysisAndDesign\�ϻ�ʵ��\8.��΢�ַ�����ֵ�ⷨ\�Ľ�ŷ������.cpp
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
    return x * x + y * y;
}

void ModEuler(float (*func)(float, float), float x0, float y0, float xn, int n)
{
    int i;
    float yp, yc, x = x0, y = y0, h = (xn - x0) / n;
    printf("x[0]=%f\ty[0]=%f\n", x, y);
    for (i = 1; i <= n; i++)
    {
        yp = y + h * (*func)(x, y);
        x = x0 + i * h; // ���� x ��ֵ
        yc = y + h * (*func)(x, yp);
        y = (yp + yc) / 2;
        printf("x[%d]=%f\ty[%d]=%f\n", i, x, i, y);
    }
}

int main()
{
    float x_max = 1.0, x0 = 0, y0 = 0;
    ModEuler(func, x0, y0, x_max, N);
    return 0;
}
