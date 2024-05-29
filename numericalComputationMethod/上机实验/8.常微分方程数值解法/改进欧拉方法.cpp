/***
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2024-05-11 15:43:45
 * @FilePath: \c++\algorithmsAnalysisAndDesign\上机实验\8.常微分方程数值解法\改进欧拉方法.cpp
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
        x = x0 + i * h; // 更新 x 的值
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
