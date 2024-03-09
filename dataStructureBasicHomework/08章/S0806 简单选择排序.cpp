/***
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2023-12-04 11:31:44
 * @FilePath: \c++\c++ BasicAlgorithmHomework\08��\S0806 ��ѡ������.cpp
 * @Description:
 * ��ϰ�����㷨8.6����ѡ������
������3��Ϊ�������
5
88 99 66 77 -22
  -22   66   77   88   99
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

// ��ѡ������
void SelectSort(SqList &S)
{
    for (int i = 1; i <= S.length - 1; ++i)
    {
        int minIndex = i;
        for (int j = i + 1; j <= S.length; ++j)
        {
            if (S.r[j] < S.r[minIndex])
            {
                minIndex = j; // Ѱ����Сֵ���±�
            }
        }
        if (minIndex != i)
        {
            swap(S.r[i], S.r[minIndex]); // ����Сֵ��������ǰλ��
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
    InitSqList(S, n); // ��ʼ��SqList��������n������
    SelectSort(S);    // ��ѡ������
    ShowList(S);      // ÿ��KEYֵռ5���ַ�λ��

    return 0;
}
