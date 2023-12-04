/***
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2023-12-04 11:19:33
 * @FilePath: \c++\c++ BasicAlgorithmHomework\08��\S0801 ��������.cpp
 * @Description:
 * ��ϰ�����㷨8.1��ֱ�Ӳ�������

�������1��Ϊ�������
5
77 66 88 99 33
   33   66   77   88   99
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

// ֱ�Ӳ�������
void InsertSort(SqList &S)
{
    for (int i = 2; i <= S.length; ++i)
    {
        if (S.r[i] < S.r[i - 1])
        {
            S.r[0] = S.r[i]; // �����ڱ�
            int j;
            for (j = i - 1; S.r[0] < S.r[j]; --j)
            {
                S.r[j + 1] = S.r[j]; // ��¼����
            }
            S.r[j + 1] = S.r[0]; // ���뵽��ȷλ��
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
    int n;
    cin >> n;
    SqList S;
    InitSqList(S, n); // ��ʼ��SqList��������n������
    InsertSort(S);    // ֱ�Ӳ�������
    ShowList(S);      // ÿ��KEYֵռ5���ַ�λ��

    return 0;
}
