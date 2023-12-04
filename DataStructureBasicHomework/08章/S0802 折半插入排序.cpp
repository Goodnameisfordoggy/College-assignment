/***
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2023-12-04 11:19:18
 * @FilePath: \c++\c++ BasicAlgorithmHomework\08��\S0802 �۰��������.cpp
 * @Description:
 * ��ϰ�㷨8.2���۰��������
������3��Ϊ�������
6
96 -2 65 7 89 36
   96   89   65   36    7   -2
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

// �۰��������
void BInsertSort(SqList &S)
{
    for (int i = 2; i <= S.length; ++i)
    {
        S.r[0] = S.r[i]; // �����ڱ�
        int low = 1, high = i - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (S.r[0] > S.r[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        for (int j = i - 1; j >= high + 1; --j)
        {
            S.r[j + 1] = S.r[j]; // ��¼����
        }
        S.r[high + 1] = S.r[0]; // ���뵽��ȷλ��
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
    BInsertSort(S);   // �۰��������
    ShowList(S);      // ÿ��KEYֵռ5���ַ�λ��

    return 0;
}
