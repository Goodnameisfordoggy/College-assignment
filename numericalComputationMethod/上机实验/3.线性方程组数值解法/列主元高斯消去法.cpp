/***
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2024-05-10 23:47:25
 * @FilePath: \c++\algorithmsAnalysisAndDesign\�ϻ�ʵ��\3.���Է�������ֵ�ⷨ\����Ԫ��˹��ȥ��.cpp
 * @Description:
 * @
 * @				*		д��¥��д�ּ䣬д�ּ������Ա��
 * @				*		������Աд�������ó��򻻾�Ǯ��
 * @				*		����ֻ���������������������ߣ�
 * @				*		��������ո��գ����������긴�ꡣ
 * @				*		��Ը�������Լ䣬��Ը�Ϲ��ϰ�ǰ��
 * @				*		���۱������Ȥ���������г���Ա��
 * @				*		����Ц��߯��񲣬��Ц�Լ���̫����
 * @				*		��������Ư���ã��ĸ���ó���Ա��
 * @Copyright (c) 2024 by HDJ, All Rights Reserved.
 */
#include <stdio.h>
#include <stdlib.h>

#define N 4 // ��������δ֪���ĸ���

// ��ӡ����
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

// ��������
void swapRows(double matrix[N][N + 1], int row1, int row2)
{
    for (int i = 0; i <= N; i++)
    {
        double temp = matrix[row1][i];
        matrix[row1][i] = matrix[row2][i];
        matrix[row2][i] = temp;
    }
}

// �ҵ�����Ԫ���ڵ��У������ظ��е�����
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

// ����Ԫ��˹��ȥ��
void gaussElimination(double matrix[N][N + 1])
{
    for (int i = 0; i < N; i++)
    {
        // ѡȡ����Ԫ
        int pivotRow = findPivotRow(matrix, i);
        if (pivotRow != i)
            swapRows(matrix, pivotRow, i);

        // ����ǰ�еĵ�һ��Ԫ�ر�Ϊ1
        double pivot = matrix[i][i];
        for (int j = i; j <= N; j++)
        {
            matrix[i][j] /= pivot;
        }

        // �õ�ǰ����ȥ�������
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

// �ش����
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

    printf("ԭʼ����:\n");
    printMatrix(matrix);

    gaussElimination(matrix);

    printf("��˹��ȥ��ľ���:\n");
    printMatrix(matrix);

    double solutions[N];
    backSubstitution(matrix, solutions);

    printf("������Ľ�:\n");
    for (int i = 0; i < N; i++)
    {
        printf("x[%d] = %.6f\n", i + 1, solutions[i]);
    }

    return 0;
}
