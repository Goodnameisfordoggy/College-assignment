/*** 
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2024-05-10 23:01:05
 * @FilePath: \c++\algorithmsAnalysisAndDesign\上机实验\5.插值法\拉格朗日插值多项式.cpp
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

// 计算阶乘的函数
double factorial(int n)
{
    double fact = 1.0;
    for (int i = 1; i <= n; ++i)
    {
        fact *= i;
    }
    return fact;
}

// 计算二项式系数的函数
double binomial_coefficient(int n, int k)
{
    return factorial(n) / (factorial(k) * factorial(n - k));
}

// 计算拉格朗日基函数的函数
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

// 执行拉格朗日插值的函数
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
    // 输入数据
    double xi[] = {0.30, 0.42, 0.50, 0.58, 0.66, 0.72};
    double yi[] = {1.04403, 1.08462, 1.11803, 1.15603, 1.19817, 1.23223};
    int n = sizeof(xi) / sizeof(xi[0]);

    // 需要估算的x值
    double x1 = 0.46;
    double x2 = 0.55;
    double x3 = 0.60;

    // 进行拉格朗日插值
    double y1 = lagrange_interpolation(x1, xi, yi, n);
    double y2 = lagrange_interpolation(x2, xi, yi, n);
    double y3 = lagrange_interpolation(x3, xi, yi, n);

    // 输出结果
    printf("x = %.2f时，y= %.6f\n", x1, y1);
    printf("x = %.2f时，y= %.6f\n", x2, y2);
    printf("x = %.2f时，y= %.6f\n", x3, y3);

    return 0;
}
