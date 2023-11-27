/***
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2023-11-27 11:20:02
 * @FilePath: \c++\c++ BasicAlgorithmHomework\07��\S0706 ɢ�б�����̽�ⷨ��.cpp
 * @Description:
 * ��ɢ�к���ΪH(key)=key%n�����Ϊm��������̽�ⷨ�����ͻ��
����ؼ�ֵ������ɢ�б�
������1��2�����룩��
13 16
19 14 23 1 68 20 84 27 55 11 10 79
hs[1].key=14
hs[2].key=1
hs[3].key=68
hs[4].key=27
hs[5].key=55
hs[6].key=19
hs[7].key=20
hs[8].key=84
hs[9].key=79
hs[10].key=23
hs[11].key=11
hs[12].key=10
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

struct HashTable
{
    int key;
};

void InitHash(HashTable hs[], int m)
{
    for (int i = 0; i < m; ++i)
    {
        hs[i].key = 0; // ������Ԫ�ص�keyֵ��Ϊ0����ʾ��ֵ��
    }
}

int Hash(int key, int m)
{
    return key % m; // ɢ�к��� H(key) = key % m
}

void InsertHash(HashTable hs[], int n, int m, int key)
{
    int index = Hash(key, m);
    while (hs[index].key != 0)
    {
        index = (index + 1) % m; // ����̽�ⷨ�����ͻ
    }
    hs[index].key = key;
}

void ShowHash(HashTable hs[], int m)
{
    for (int i = 0; i < m; ++i)
    {
        if (hs[i].key != 0)
        {
            cout << "hs[" << i + 1 << "].key=" << hs[i].key << endl;
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    HashTable hs[m];
    InitHash(hs, m);

    for (int i = 0; i < n - 1; ++i)
    {
        int t;
        cin >> t;
        InsertHash(hs, n, m, t);
    }

    ShowHash(hs, m);
    return 0;
}
