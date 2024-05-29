/*** 
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2024-05-10 15:19:58
 * @FilePath: \c++\algorithmsAnalysisAndDesign\上机实验\3.线性方程组数值解法\列主元高斯消去法-验算方程根.cpp
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

#define N 4 // 方程组中未知数的个数

// 检查方程组的解是否满足原方程组
void checkSolution(double matrix[N][N+1], double solutions[N]) {
    printf("验算结果:\n");
    for (int i = 0; i < N; i++) {
        double sum = 0;
        for (int j = 0; j < N; j++) {
            sum += matrix[i][j] * solutions[j];
        }
        printf("方程%d: %.2f -- %.2f\n", i+1, sum, matrix[i][N]);
    }
}

int main() {
    double matrix[N][N+1] = {{1, 1, 0, 3, 4},
                             {2, 1, -1, 1, 1},
                             {3, -1, -1, 3, -3},
                             {-1, 2, 3, -1, 4}};

    double solutions[N] = {-1.33, 2.33, -0.33, 1.00}; // 求得的解

    printf("方程组的解:\n");
    for (int i = 0; i < N; i++) {
        printf("x%d = %.2f\n", i+1, solutions[i]);
    }

    checkSolution(matrix, solutions);

    return 0;
}
