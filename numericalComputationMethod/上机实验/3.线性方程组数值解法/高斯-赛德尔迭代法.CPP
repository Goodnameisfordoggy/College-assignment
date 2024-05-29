/*** 
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2024-05-10 15:28:59
 * @FilePath: \c++\algorithmsAnalysisAndDesign\上机实验\3.线性方程组数值解法\1.cpp
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

void printMatrix(double A[N][N+1]) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N+1; j++) {
            printf("%.2f\t", A[i][j]);
        }
        printf("\n");
    }
}

void gaussSeidel(double A[N][N+1], double X[N]) {
    double epsilon = EPSILON;
    double temp[N]; // 存储迭代过程中的临时解向量
    int iter = 0;
    double error;
    
    // 初始化解向量
    for(int i = 0; i < N; i++) {
        X[i] = 0;
    }
    
    do {
        error = 0;
        for(int i = 0; i < N; i++) {
            temp[i] = A[i][N];
            for(int j = 0; j < N; j++) {
                if(j != i) {
                    temp[i] -= A[i][j] * X[j];
                }
            }
            temp[i] /= A[i][i];
            if(fabs(X[i] - temp[i]) > error) {
                error = fabs(X[i] - temp[i]);
            }
            X[i] = temp[i];
        }
        iter++;
    } while(error > epsilon);

    printf("迭代次数为%d。\n", iter);
}

int main() {
    double A[N][N+1] = {
        {10, -1, 2, 0, -11},
        {0, 8, -1, 3, -11},
        {2, -1, 10, 0, 6},
        {-1, 3, -1, 11, 25}
    };

    double X[N]; // 存储解向量
    
    printf("初始增广矩阵:\n");
    printMatrix(A);

    gaussSeidel(A, X);

    printf("结果为：\n");
    for(int i = 0; i < N; i++) {
        printf("X[%d] = %.6f\n", i, X[i]);
    }

    return 0;
}
