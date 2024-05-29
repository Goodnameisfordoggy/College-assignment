/*** 
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2024-05-10 23:19:37
 * @FilePath: \c++\algorithmsAnalysisAndDesign\�ϻ�ʵ��\5.��ֵ��\2.cpp
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

// ��������
#define MAX_SIZE 5

// ��������
double calculateInterpolation(double x[], double y[], int n, double target);
void printDifferenceTable(double y[], int n);

int main()
{
    // ��������
    double x[MAX_SIZE] = {20, 21, 22, 23, 24};
    double y[MAX_SIZE] = {1.30103, 1.32222, 1.34242, 1.36173, 1.38021};
    int n = MAX_SIZE;

    // �����ֱ�
    printf("��ֱ�Ϊ:\n");
    printDifferenceTable(y, n);

    // ����x=21.4ʱ�ĺ���ֵ
    double target = 21.4;
    double interpolatedValue = calculateInterpolation(x, y, n, target);
    printf("\n��x=%.1fʱ, y=%.6f\n", target, interpolatedValue);

    return 0;
}

// ����ţ��ǰ�巨�Ĳ�ֵ
double calculateInterpolation(double x[], double y[], int n, double target)
{
    double h = x[1] - x[0]; // ���㲽��
    double p = (target - x[0]) / h;
    double result = y[0];
    double f[MAX_SIZE][MAX_SIZE] = {0};

    // ������ֱ�
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

    // �����ֵ
    for (int j = 1; j < n; j++)
    {
        result += (p * f[0][j]) / (1.0 * j);
        p *= (p - 1);
    }

    return result;
}

// �����ֱ�
void printDifferenceTable(double y[], int n)
{
    double f[MAX_SIZE][MAX_SIZE] = {0};

    // ������ֱ�
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

    // �����ֱ�
    for (int i = 0; i < n; i++)
    {
        // printf("%.2f", x[i]);
        for (int j = 0; j <= i; j++)
        {
            printf("%9.4f", f[i - j][j]);
        }
        // ���0���Ĳ�ֱ���
        for (int j = i + 1; j < n; j++)
        {
            printf("%9d", 0);
        }
        printf("\n");
    }
}
