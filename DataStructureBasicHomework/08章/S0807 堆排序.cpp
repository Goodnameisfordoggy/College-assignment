/***
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2023-12-04 11:33:21
 * @FilePath: \c++\c++ BasicAlgorithmHomework\08��\S0807 ������.cpp
 * @Description:
 * ��ϰ�����㷨8.9��������
�������1��Ϊ�������
5
234 3 5 34 -54
  -54    3    5   34  234
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

// �����ѣ�ʹ������ѵ�����
void HeapAdjust(SqList &S, int s, int m)
{
    int temp = S.r[s];
    for (int j = 2 * s; j <= m; j *= 2)
    {
        if (j < m && S.r[j] < S.r[j + 1])
        {
            ++j; // �ҵ����Һ��ӽڵ��нϴ��һ��
        }
        if (temp >= S.r[j])
        {
            break; // ������ڵ�������Һ��ӽڵ㣬���˳�ѭ��
        }
        S.r[s] = S.r[j]; // ���ϴ�ĺ��ӽڵ���������ڵ�λ��
        s = j;
    }
    S.r[s] = temp; // ��ԭ���ڵ�ֵ�ŵ�����λ��
}

// ������
void HeapSort(SqList &S)
{
    for (int i = S.length / 2; i > 0; --i)
    {
        HeapAdjust(S, i, S.length); // �����󶥶�
    }
    for (int i = S.length; i > 1; --i)
    {
        swap(S.r[1], S.r[i]);    // ���Ѷ�Ԫ����ĩβԪ�ؽ���
        HeapAdjust(S, 1, i - 1); // ����ʣ��Ԫ�أ�ʹ������ѵ�����
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
    HeapSort(S);      // ������
    ShowList(S);      // ÿ��KEYֵռ5���ַ�λ��

    return 0;
}
