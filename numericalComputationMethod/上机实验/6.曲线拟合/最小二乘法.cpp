/***
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2024-05-14 14:04:33
 * @FilePath: \c++\numericalComputationMethod\上机实验\6.曲线拟合\2.cpp
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

// 定义数据点的数量
#define N 15

// 定义数据点的坐标
double x[N] = {1, 1.5, 2, 2.5, 3, 3.5, 4, 4.5, 5, 5.5, 6, 6.5, 7, 7.5, 8};
double y[N] = {33.4, 79.50, 122.65, 159.05, 189.15, 214.15, 238.65, 252.50, 267.55, 280.50, 296.65, 301.40, 310.40, 318.15, 325.15};

// 计算抛物线拟合参数
void parabola_fit(double x[], double y[], double *a, double *b, double *c)
{
    double sum_x = 0, sum_y = 0, sum_x2 = 0, sum_x3 = 0, sum_x4 = 0, sum_xy = 0, sum_x2y = 0;

    // 计算各项和
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

    // 构造方程组
    double A[3][3] = {
        {N, sum_x, sum_x2},
        {sum_x, sum_x2, sum_x3},
        {sum_x2, sum_x3, sum_x4}};
    double B[3] = {sum_y, sum_xy, sum_x2y};

    // 使用克拉默法则解方程组
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

// 计算指数曲线拟合参数
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
    double a1, b1, c1; // 抛物线参数
    double a2, b2;     // 指数曲线参数

    // 计算抛物线拟合参数
    parabola_fit(x, y, &a1, &b1, &c1);
    printf("抛物线方程: y = %.6f + %.6fx + %.6fx^2\n", a1, b1, c1);

    // 计算指数曲线拟合参数
    exponential_fit(x, y, &a2, &b2);
    printf("指数曲线方程: y = %.4fe^(%.6fx)\n", a2, b2);

    return 0;
}
