/*** 
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2024-05-10 16:00:12
 * @FilePath: \c++\algorithmsAnalysisAndDesign\�ϻ�ʵ��\3.���Է�������ֵ�ⷨ\2.cpp
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

#define N 4 // ������Ľ���
#define EPSILON 0.00001 // ��������

void verifySolution(double X[N]) {
    double a = X[0];
    double b = X[1];
    double c = X[2];
    double d = X[3];

    // ԭ������
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
    // ���㷽��4����
    double X[N] = {-1.467392, -2.358696, 0.657609, 2.842391};

    verifySolution(X);

    return 0;
}
