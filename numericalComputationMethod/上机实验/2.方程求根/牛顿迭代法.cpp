/*** 
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2024-05-10 15:19:31
 * @FilePath: \c++\algorithmsAnalysisAndDesign\�ϻ�ʵ��\2.�������\ţ�ٵ�����.cpp
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

// ���庯�����䵼��
double f(double x) {
    return x * exp(x) - 1;
}

double df(double x) {
    return exp(x) + x * exp(x);
}

// ţ�ٵ���������
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
    double x0 = 1.0; // ��ʼֵ
    double tol = 1e-6; // �������
    int max_iter = 100; // ����������

    // ����ţ�ٵ���������
    double root = newton_method(x0, tol, max_iter);
    printf("���̵ĸ�Ϊ: %f\n", root);
    
    return 0;
}
