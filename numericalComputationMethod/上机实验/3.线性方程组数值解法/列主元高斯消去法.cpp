/***
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2024-05-10 23:47:25
 * @FilePath: \c++\algorithmsAnalysisAndDesign\上机实验\3.线性方程组数值解法\列主元高斯消去法.cpp
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
#include <stdlib.h>

#define N 4 // 方程组中未知数的个数

// 打印矩阵
void printMatrix(double matrix[N][N + 1])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= N; j++)
        {
            printf("%10.6f", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// 交换两行
void swapRows(double matrix[N][N + 1], int row1, int row2)
{
    for (int i = 0; i <= N; i++)
    {
        double temp = matrix[row1][i];
        matrix[row1][i] = matrix[row2][i];
        matrix[row2][i] = temp;
    }
}

// 找到列主元所在的行，并返回该行的索引
int findPivotRow(double matrix[N][N + 1], int col)
{
    double max = matrix[col][col];
    int maxIndex = col;
    for (int i = col + 1; i < N; i++)
    {
        if (matrix[i][col] > max)
        {
            max = matrix[i][col];
            maxIndex = i;
        }
    }
    return maxIndex;
}

// 列主元高斯消去法
void gaussElimination(double matrix[N][N + 1])
{
    for (int i = 0; i < N; i++)
    {
        // 选取列主元
        int pivotRow = findPivotRow(matrix, i);
        if (pivotRow != i)
            swapRows(matrix, pivotRow, i);

        // 将当前列的第一个元素变为1
        double pivot = matrix[i][i];
        for (int j = i; j <= N; j++)
        {
            matrix[i][j] /= pivot;
        }

        // 用当前行消去下面的行
        for (int k = i + 1; k < N; k++)
        {
            double factor = matrix[k][i];
            for (int j = i; j <= N; j++)
            {
                matrix[k][j] -= factor * matrix[i][j];
            }
        }
    }
}

// 回代求解
void backSubstitution(double matrix[N][N + 1], double solutions[N])
{
    for (int i = N - 1; i >= 0; i--)
    {
        solutions[i] = matrix[i][N];
        for (int j = i + 1; j < N; j++)
        {
            solutions[i] -= matrix[i][j] * solutions[j];
        }
    }
}

int main()
{
    double matrix[N][N + 1] = {{1, 1, 0, 3, 4},
                               {2, 1, -1, 1, 1},
                               {3, -1, -1, 3, -3},
                               {-1, 2, 3, -1, 4}};

    printf("原始矩阵:\n");
    printMatrix(matrix);

    gaussElimination(matrix);

    printf("高斯消去后的矩阵:\n");
    printMatrix(matrix);

    double solutions[N];
    backSubstitution(matrix, solutions);

    printf("方程组的解:\n");
    for (int i = 0; i < N; i++)
    {
        printf("x[%d] = %.6f\n", i + 1, solutions[i]);
    }

    return 0;
}
