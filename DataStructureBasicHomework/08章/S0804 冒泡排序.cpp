/***
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2023-12-04 11:38:02
 * @FilePath: \c++\c++ BasicAlgorithmHomework\08��\S0804 ð������.cpp
 * @Description:
 * ��ϰ�����㷨8.4��ð������
������3��Ϊ�������
5
78 65 12 33 41
   78   65   41   33   12
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

// ð������
void BubbleSort(SqList &S)
{
    for (int i = 1; i < S.length; ++i)
    {
        for (int j = 1; j <= S.length - i; ++j)
        {
            if (S.r[j] < S.r[j + 1])
            {
                swap(S.r[j], S.r[j + 1]); // ��������Ԫ��
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
    InitSqList(S, n); // ��ʼ��SqList��������n������
    BubbleSort(S);    // ð������
    ShowList(S);      // ÿ��KEYֵռ5���ַ�λ��

    return 0;
}
