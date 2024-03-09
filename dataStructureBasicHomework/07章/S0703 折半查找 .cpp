/***
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2023-11-27 10:56:11
 * @FilePath: \c++\c++ BasicAlgorithmHomework\07��\S0703 �۰���� .cpp
 * @Description:
 * ע�������5��������С�������롣
��1����1��3��Ϊ���룩��
55 66 77 88 99
Please input the score you want to find:
99
Location of 99 is 5

��2����1��3��Ϊ���룩��
55 66 77 88 99
Please input the score you want to find:
90
90 is not found!
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

#define MAXSIZE 100 // �������Ա����󳤶�

typedef struct
{
    int data[MAXSIZE + 1]; // ������洢���ݣ�����Ԥ��һ��λ��
    int length;            // ��ǰ���Ա�ĳ���
} SSTable;

// ��ʼ�����Ա�
void InitList(SSTable &L)
{
    L.length = 0; // �����Ա��ȳ�ʼ��Ϊ0
}

// �����Ա��в������ݲ���������
void InsertList(SSTable &L, int n)
{
    if (n > MAXSIZE)
    {
        cout << "Exceeds maximum size!" << endl;
        return;
    }
    for (int i = 1; i <= n; ++i)
    {
        cin >> L.data[i]; // �������ɼ����ݣ����±�1��ʼ
    }
    L.length = n; // �������Ա���
}

// ���������Ա��н����۰����
int Search_Seq(const SSTable &L, int target)
{
    int low = 1, high = L.length;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (L.data[mid] == target)
        {
            return mid; // �ҵ�Ŀ��ֵ
        }
        else if (L.data[mid] < target)
        {
            low = mid + 1; // ���Ұ벿�ּ�������
        }
        else
        {
            high = mid - 1; // ����벿�ּ�������
        }
    }
    return 0; // δ�ҵ�Ŀ��ֵ
}

int main()
{
    // ���Ա�ĵĳ�ʼ�������롢ȡֵ
    SSTable Lscore;        // �����洢ѧ�������ݽṹ���ɼ�
    InitList(Lscore);      // ��ʼ�����Ա�
    InsertList(Lscore, 5); // ����5��ѧ���ɼ������Ա�
    cout << "Please input the score you want to find:" << endl;
    int s;
    cin >> s; // ����Ҫ���ҵĳɼ�
    int loc = Search_Seq(Lscore, s);
    if (loc != 0)
        cout << "Location of " << s << " is " << loc << endl;
    else
        cout << s << " is not found!" << endl;

    return 0;
}