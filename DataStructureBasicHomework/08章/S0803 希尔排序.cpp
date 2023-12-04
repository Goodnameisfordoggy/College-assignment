/***
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2023-12-04 11:20:21
 * @FilePath: \c++\c++ BasicAlgorithmHomework\08��\S0803 ϣ������.cpp
 * @Description:
 * ��ϰ�����㷨8.3��ϣ������
������3��Ϊ�������
6
1 345 45 78 6 5
    1    5    6   45   78  345
 * @
 * @				*		д��¥��д�ּ䣬д�ּ������Ա��
 * @				*		������Աд�������ó��򻻾�Ǯ��
 * @				*		����ֻ���������������������ߣ�
 * @				*		��������ո��գ����������긴�ꡣ
 * @				*		��Ը�������Լ䣬��Ը�Ϲ��ϰ�ǰ��
 * @				*		���۱������Ȥ���������г���Ա��
 * @				*		����Ц��߯��񲣬��Ц�Լ���̫����
 * @				*		��������Ư���ã��ĸ���ó���Ա��
 * @Copyright (c) ${2023} by ${HDJ}, All Rights Reserved.
 */
#include <iostream>
using namespace std;

const int MAXSIZE = 100;

typedef struct
{
    int r[MAXSIZE + 1]; // ���±�1��ʼ�洢���ݣ�r[0]��ʹ��
    int length;         // ˳���ĳ���
} SqList;

// ��ʼ��˳���
void InitSqList(SqList &S, int n)
{
    S.length = n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> S.r[i];
    }
}

// ϣ������
void ShellSort(SqList &S, int dt[], int t)
{
    for (int k = 0; k < t; ++k)
    {
        int dk = dt[k]; // ��������
        for (int i = dk + 1; i <= S.length; ++i)
        {
            if (S.r[i] < S.r[i - dk])
            {
                S.r[0] = S.r[i]; // �����ڱ�
                int j;
                for (j = i - dk; j > 0 && S.r[0] < S.r[j]; j -= dk)
                {
                    S.r[j + dk] = S.r[j]; // ��¼����
                }
                S.r[j + dk] = S.r[0]; // ���뵽��ȷλ��
            }
        }
    }
}

// ��ʾ˳���
void ShowList(SqList S)
{
    for (int i = 1; i <= S.length; ++i)
    {
        cout.width(5);
        cout << S.r[i];
    }
    cout << endl;
}

int main()
{
    int dt[3] = {5, 3, 1};
    int n;
    cin >> n;
    SqList S;
    InitSqList(S, n);    // ��ʼ��SqList��������n������
    ShellSort(S, dt, 3); // ϣ������
    ShowList(S);         // ÿ��KEYֵռ5���ַ�λ��

    return 0;
}
