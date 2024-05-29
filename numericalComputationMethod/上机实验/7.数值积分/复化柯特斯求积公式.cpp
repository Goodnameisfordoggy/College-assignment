/***
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2024-05-11 17:07:47
 * @FilePath: \c++\numericalComputationMethod\上机实验\7.数值积分\复化柯特斯求积公式.cpp
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

// 定义被积函数
double func(double x)
{
    if (x == -1)
    {
        return INFINITY; // 当x为-1时，避免除零错误，直接返回1/0的极限值
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
        return 1.0; // 当x为0时，避免除零错误，直接返回sin(0)/0的极限值1
    }
    else
    {
        return sin(x) / x;
    }
}

/**
 *@name Cotes：复化柯特斯公式
 *@param1 below：区间下限
 *@param2 upper：区间上限
 *@param3 n：划分子区间的个数
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
        // 计算各区间1/4处的值 1/4~(n-3/4)共n项
        S1 += func(x);
        x += h;
    }

    x = below + h / 2;
    for (int i = 0; i < n; i++)
    {
        // 计算各区间1/2处的值 1/2~(n-1/2)共n项
        S2 += func(x);
        x += h;
    }

    x = below + 3 * h / 4;
    for (int i = 0; i < n; i++)
    {
        // 计算各区间3/4处的值 3/4~(n-1/4)共n项
        S3 += func(x);
        x += h;
    }

    x = below + h;
    for (int i = 1; i < n; i++)
    {
        // 计算各区间3/4处的值 1~(n-1)共n-1项
        S4 += func(x);
        x += h;
    }

    return (h / 90) * (7 * func(below) + 32 * S1 + 12 * S2 + 32 * S3 + 14 * S4 + 7 * func(upper));
}

int main()
{

    double target_precision = 1e-6; // 目标精度
    int n = 0;                      // 初始划分数
    double prev_integral_approximation = 0.0;
    double integral_approximation = Cotes(func, 0.0, 1.0, n);

    while (1)
    {
        if (fabs(integral_approximation - prev_integral_approximation) < target_precision)
        {
            printf("c(%d)=%.6f,", n - 2, Cotes(func, 0.0, 1.0, n - 2));
            printf("c(%d)=%.6f,n=%d时有6位有效数字\n", n, integral_approximation, n);
            break;
        }
        prev_integral_approximation = integral_approximation;
        n += 2; // 每次增加2，确保n为偶数
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
            printf("c(%d)=%.6f,n=%d时有6位有效数字\n", n, integral_approximation, n);
            break;
        }
        prev_integral_approximation = integral_approximation;
        n += 2; // 每次增加2，确保n为偶数
        integral_approximation = Cotes(func2, 0.0, 5.0, n);
    }

    return 0;
}
