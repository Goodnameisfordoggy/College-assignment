/*** 
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2024-05-10 16:00:12
 * @FilePath: \c++\algorithmsAnalysisAndDesign\上机实验\3.线性方程组数值解法\2.cpp
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

#define N 4 // 方程组的阶数
#define EPSILON 0.00001 // 收敛条件

void verifySolution(double X[N]) {
    double a = X[0];
    double b = X[1];
    double c = X[2];
    double d = X[3];

    // 原方程组
    double eq1 = 10 * a - b + 2 * c;
    double eq2 = 8 * b - c + 3 * d;
    double eq3 = 2 * a - b + 10 * c;
    double eq4 = -a + 3 * b - c + 11 * d;

    printf("Verification of the solution:\n");
    printf("Equation 1: 10a - b + 2c = %.6f\n", eq1);
    printf("Equation 2: 8b - c + 3d = %.6f\n", eq2);
    printf("Equation 3: 2a - b + 10c = %.6f\n", eq3);
    printf("Equation 4: -a + 3b - c + 11d = %.6f\n", eq4);
}

int main() {
    // 验算方程4个根
    double X[N] = {-1.467392, -2.358696, 0.657609, 2.842391};

    verifySolution(X);

    return 0;
}
