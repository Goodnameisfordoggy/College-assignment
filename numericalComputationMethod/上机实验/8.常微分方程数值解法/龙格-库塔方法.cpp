/***
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2024-05-11 16:32:44
 * @FilePath: \c++\algorithmsAnalysisAndDesign\上机实验\8.常微分方程数值解法\1.cpp
 * @Description: Copy from textbook
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