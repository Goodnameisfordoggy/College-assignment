/***
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2023-11-27 10:39:05
 * @FilePath: \c++\c++ BasicAlgorithmHomework\07��\S0702 ˳�����2(���ü�����) .cpp
 * @Description:
 * ��1����1��3��Ϊ���룩��
66 89 78 90
Please input the score you want to find:
78
78 is found!

��2����1��3��Ϊ���룩��
66 89 78 90
Please input the score you want to find:
79
79 is not found!
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
    int data[MAXSIZE + 1]; // ������洢���ݣ�����Ԥ��һ��λ����Ϊ������
    int length;            // ��ǰ���Ա�ĳ���
} SSTable;

// ��ʼ�����Ա�
void InitList(SSTable &L)
{
    L.length = 0; // �����Ա��ȳ�ʼ��Ϊ0
}

// �����Ա��в�������
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
    L.length = n;   // �������Ա���
    L.data[0] = -1; // ���ü�����Ϊ-1������ɼ�����Ϊ������
}

// �����Ա��н���˳����ң����ü����ڣ�
bool Search_Seq(const SSTable &L, int target)
{
    int i = L.length;       // �����Ա�ĩβ��ʼ��ǰ����
    SSTable tempL = L;      // ����һ�������������޸�ԭʼ����
    tempL.data[0] = target; // ���ü�����
    while (tempL.data[i] != target)
    {
        --i;
    }
    return i != 0; // ��i������0����ʾ�ҵ���Ŀ��
}

int main()
{
    // ���Ա�ĵĳ�ʼ�������롢ȡֵ
    SSTable Lscore;        // �����洢ѧ�������ݽṹ���ɼ�
    InitList(Lscore);      // ��ʼ�����Ա�
    InsertList(Lscore, 4); // ����4��ѧ���ɼ������Ա�
    cout << "Please input the score you want to find:" << endl;
    int s;
    cin >> s; // ����Ҫ���ҵĳɼ�
    if (Search_Seq(Lscore, s))
        cout << s << " is found!" << endl;
    else
        cout << s << " is not found!" << endl;

    return 0;
}
