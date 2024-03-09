/***
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2023-12-04 11:30:02
 * @FilePath: \c++\c++ BasicAlgorithmHomework\08��\S0805 ��������.cpp
 * @Description:
 * ��ϰ�����㷨8.5����������
������3��Ϊ�������
5
45 56 5 9 -6
   -6    5    9   45   56
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

// ��������
int Partition(SqList &S, int low, int high)
{
    int pivot = S.r[low]; // ѡȡ��׼Ԫ��
    while (low < high)
    {
        while (low < high && S.r[high] >= pivot)
        {
            --high;
        }
        S.r[low] = S.r[high]; // �Ȼ�׼С��Ԫ���Ƶ��Ͷ�
        while (low < high && S.r[low] <= pivot)
        {
            ++low;
        }
        S.r[high] = S.r[low]; // �Ȼ�׼���Ԫ���Ƶ��߶�
    }
    S.r[low] = pivot; // ��׼Ԫ�طŵ�����λ��
    return low;       // ���ػ�׼Ԫ��λ��
}

void QSort(SqList &S, int low, int high)
{
    if (low < high)
    {
        int pivotpos = Partition(S, low, high); // ����
        QSort(S, low, pivotpos - 1);            // �ݹ����ӱ�
        QSort(S, pivotpos + 1, high);           // �ݹ����ӱ�
    }
}

void QuickSort(SqList &S)
{
    QSort(S, 1, S.length);
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
    QuickSort(S);     // ��������
    ShowList(S);      // ÿ��KEYֵռ5���ַ�λ��

    return 0;
}
