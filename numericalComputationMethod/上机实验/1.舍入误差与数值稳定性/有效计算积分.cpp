/*** 
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2024-05-11 21:39:42
 * @FilePath: \c++\numericalComputationMethod\上机实验\1.舍入误差与数值稳定性\1.cpp
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
double f(double x, int n)
{
    return pow(x, n) / (4 * x + 1);
}

// 计算定积分
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
    double a = 0;   // 下限
    double b = 1;   // 上限
    int n_max = 40; // 指数上限
    int N = 1000;   // 划分区间数
    double result;

    for (int n = 1; n <= n_max; n++)
    {
        result = integrate(n, a, b, N);
        printf("n=%d, I=%lf\n", n, result);
    }

    return 0;
}
