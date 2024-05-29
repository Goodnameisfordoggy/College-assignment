/*** 
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2024-05-10 15:19:31
 * @FilePath: \c++\algorithmsAnalysisAndDesign\上机实验\2.方程求根\牛顿迭代法.cpp
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

// 定义函数和其导数
double f(double x) {
    return x * exp(x) - 1;
}

double df(double x) {
    return exp(x) + x * exp(x);
}

// 牛顿迭代法函数
double newton_method(double x0, double tol, int max_iter) {
    int i;
    double fx, x = x0;
    for (i = 0; i < max_iter; ++i) {
        fx = f(x);
        if (fabs(fx) < tol) {
            return x;
        }
        x = x - fx / df(x);
    }
    return x;
}

int main() {
    double x0 = 1.0; // 初始值
    double tol = 1e-6; // 容许误差
    int max_iter = 100; // 最大迭代次数

    // 调用牛顿迭代法函数
    double root = newton_method(x0, tol, max_iter);
    printf("方程的根为: %f\n", root);
    
    return 0;
}
