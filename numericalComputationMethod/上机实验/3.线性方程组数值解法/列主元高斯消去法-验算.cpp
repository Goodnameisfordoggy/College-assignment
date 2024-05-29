/*** 
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2024-05-10 15:19:58
 * @FilePath: \c++\algorithmsAnalysisAndDesign\�ϻ�ʵ��\3.���Է�������ֵ�ⷨ\����Ԫ��˹��ȥ��-���㷽�̸�.cpp
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
#include <math.h>

#define N 4 // ��������δ֪���ĸ���

// ��鷽����Ľ��Ƿ�����ԭ������
void checkSolution(double matrix[N][N+1], double solutions[N]) {
    printf("������:\n");
    for (int i = 0; i < N; i++) {
        double sum = 0;
        for (int j = 0; j < N; j++) {
            sum += matrix[i][j] * solutions[j];
        }
        printf("����%d: %.2f -- %.2f\n", i+1, sum, matrix[i][N]);
    }
}

int main() {
    double matrix[N][N+1] = {{1, 1, 0, 3, 4},
                             {2, 1, -1, 1, 1},
                             {3, -1, -1, 3, -3},
                             {-1, 2, 3, -1, 4}};

    double solutions[N] = {-1.33, 2.33, -0.33, 1.00}; // ��õĽ�

    printf("������Ľ�:\n");
    for (int i = 0; i < N; i++) {
        printf("x%d = %.2f\n", i+1, solutions[i]);
    }

    checkSolution(matrix, solutions);

    return 0;
}
