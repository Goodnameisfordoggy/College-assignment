/*** 
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2024-05-10 23:19:37
 * @FilePath: \c++\algorithmsAnalysisAndDesign\上机实验\5.插值法\2.cpp
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

// 常量定义
#define MAX_SIZE 5

// 函数声明
double calculateInterpolation(double x[], double y[], int n, double target);
void printDifferenceTable(double y[], int n);

int main()
{
    // 给出数据
    double x[MAX_SIZE] = {20, 21, 22, 23, 24};
    double y[MAX_SIZE] = {1.30103, 1.32222, 1.34242, 1.36173, 1.38021};
    int n = MAX_SIZE;

    // 输出差分表
    printf("查分表为:\n");
    printDifferenceTable(y, n);

    // 计算x=21.4时的函数值
    double target = 21.4;
    double interpolatedValue = calculateInterpolation(x, y, n, target);
    printf("\n当x=%.1f时, y=%.6f\n", target, interpolatedValue);

    return 0;
}

// 计算牛顿前插法的插值
double calculateInterpolation(double x[], double y[], int n, double target)
{
    double h = x[1] - x[0]; // 计算步长
    double p = (target - x[0]) / h;
    double result = y[0];
    double f[MAX_SIZE][MAX_SIZE] = {0};

    // 构建差分表
    for (int i = 0; i < n; i++)
    {
        f[i][0] = y[i];
    }

    for (int j = 1; j < n; j++)
    {
        for (int i = 0; i < n - j; i++)
        {
            f[i][j] = f[i + 1][j - 1] - f[i][j - 1];
        }
    }

    // 计算插值
    for (int j = 1; j < n; j++)
    {
        result += (p * f[0][j]) / (1.0 * j);
        p *= (p - 1);
    }

    return result;
}

// 输出差分表
void printDifferenceTable(double y[], int n)
{
    double f[MAX_SIZE][MAX_SIZE] = {0};

    // 构建差分表
    for (int i = 0; i < n; i++)
    {
        f[i][0] = y[i];
    }

    for (int j = 1; j < n; j++)
    {
        for (int i = 0; i < n - j; i++)
        {
            f[i][j] = f[i + 1][j - 1] - f[i][j - 1];
        }
    }

    // 输出差分表
    for (int i = 0; i < n; i++)
    {
        // printf("%.2f", x[i]);
        for (int j = 0; j <= i; j++)
        {
            printf("%9.4f", f[i - j][j]);
        }
        // 输出0填充的差分表项
        for (int j = i + 1; j < n; j++)
        {
            printf("%9d", 0);
        }
        printf("\n");
    }
}
