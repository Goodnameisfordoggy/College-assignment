/***
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2023-12-04 10:44:39
 * @FilePath: \c++\c++ BasicAlgorithmHomework\07��\1.cpp
 * @Description:
 * ��S0703�Ļ������޸ĳ���ʹ�õݹ鷽�������۰���ҡ�
��1����1��2��5��Ϊ���룩��
5
88 90 78 66 89
   66   78   88   89   90
Please input the score you want to find:
88
Location of 88 is 3

��2����1��2��5��Ϊ���룩��
5
88 90 78 66 89
   66   78   88   89   90
Please input the score you want to find:
83
83 is not found!
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

// ���Ա�Ľṹ�嶨��
const int MAXSIZE = 100;
typedef struct
{
    int r[MAXSIZE]; // ���ڴ洢���ݵ�����
    int length;     // ���Ա�ĳ���
} SSTable;

// ��ʼ�����Ա�
void InitList(SSTable &L)
{
    L.length = 0;
}

// ���ɼ��������Ա�
void InsertList(SSTable &L, int n)
{
    for (int i = 1; i <= n; ++i)
    {
        cin >> L.r[i];
        L.length++;
    }
}

// �ɼ���С��������
void SortList(SSTable &L, int n)
{
    for (int i = 1; i <= n - 1; ++i)
    {
        for (int j = i + 1; j <= n; ++j)
        {
            if (L.r[i] > L.r[j])
            {
                int temp = L.r[i];
                L.r[i] = L.r[j];
                L.r[j] = temp;
            }
        }
    }
}

// ������Ա�
void ShowList(SSTable L, int n)
{
    for (int i = 1; i <= n; ++i)
    {
        cout.width(5);
        cout << L.r[i];
    }
    cout << endl;
}

// �۰���ң��ݹ�ʵ�֣�
int Search_Seq(SSTable L, int key, int low, int high)
{
    if (low > high)
    {
        return 0; // δ�ҵ�
    }

    int mid = (low + high) / 2;

    if (L.r[mid] == key)
    {
        return mid; // �ҵ���
    }
    else if (L.r[mid] > key)
    {
        return Search_Seq(L, key, low, mid - 1); // ����벿�ֲ���
    }
    else
    {
        return Search_Seq(L, key, mid + 1, high); // ���Ұ벿�ֲ���
    }
}

int main()
{
    // ���Ա�ĵĳ�ʼ�������롢ȡֵ
    SSTable Lscore;   // �����洢ѧ�������ݽṹ���ɼ�
    InitList(Lscore); // ��ʼ�����Ա�

    int n;
    cin >> n;
    InsertList(Lscore, n); // ����n��ѧ���ɼ������Ա�
    SortList(Lscore, n);   // �ɼ���С��������
    ShowList(Lscore, n);   // ����ɼ���ÿ���ɼ�ռ5���ַ�λ��

    cout << "Please input the score you want to find:" << endl;
    int s;
    cin >> s; // ����Ҫ���ҵĳɼ�
    int low = 1, high = n;
    int loc = Search_Seq(Lscore, s, low, high);
    if (loc != 0)
        cout << "Location of " << s << " is " << loc << endl;
    else
        cout << s << " is not found!" << endl;

    return 0;
}
