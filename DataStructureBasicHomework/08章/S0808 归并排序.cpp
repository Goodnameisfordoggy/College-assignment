/***
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2023-12-04 11:34:41
 * @FilePath: \c++\c++ BasicAlgorithmHomework\08��\S0808 �鲢����.cpp
 * @Description:
 * ��ϰ�����㷨8.11:�鲢����
�������1��Ϊ�������
6
24 -9 66 55 88 77
   -9   24   55   66   77   88
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

// �ϲ�������������
void Merge(SqList &S, int low, int mid, int high)
{
    int i = low, j = mid + 1, k = 1;
    int *temp = new int[MAXSIZE]; // ��ʱ����
    while (i <= mid && j <= high)
    {
        if (S.r[i] <= S.r[j])
        {
            temp[k++] = S.r[i++];
        }
        else
        {
            temp[k++] = S.r[j++];
        }
    }
    while (i <= mid)
    {
        temp[k++] = S.r[i++];
    }
    while (j <= high)
    {
        temp[k++] = S.r[j++];
    }
    for (int l = 1, m = low; l < k; ++l, ++m)
    {
        S.r[m] = temp[l]; // ���ź����Ԫ�طŻ�ԭ����
    }
    delete[] temp; // �ͷ���ʱ������ڴ�
}

// �鲢����
void MSort(SqList &S, int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        MSort(S, low, mid);       // ����벿�ֽ��й鲢����
        MSort(S, mid + 1, high);  // ���Ұ벿�ֽ��й鲢����
        Merge(S, low, mid, high); // �ϲ�������������
    }
}

void MergeSort(SqList &S)
{
    MSort(S, 1, S.length);
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
    MergeSort(S);     // �鲢����
    ShowList(S);      // ÿ��KEYֵռ5���ַ�λ��

    return 0;
}
