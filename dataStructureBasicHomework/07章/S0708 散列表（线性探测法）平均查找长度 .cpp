/***
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2023-11-27 11:43:51
 * @FilePath: \c++\c++ BasicAlgorithmHomework\07��\S0708 ɢ�б�����̽�ⷨ��ƽ�����ҳ��� .cpp
 * @Description:
 * ��S0706�Ļ������޸ĳ��򣬼���ɢ�б��ڲ��ҳɹ�ʱ��ƽ�����ҳ��ȡ�
������1��2��Ϊ���룩��
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
2.5
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

int Hash(int key, int m, int i)
{
    return (key + i) % m; // ����̽�ⷨ H(key, i) = (key + i) % m
}

int InsertHash(HashTable hs[], int m, int key)
{
    int i = 0;
    int index;
    do
    {
        index = Hash(key, m, i);
        if (hs[index].key == 0)
        {
            hs[index].key = key;
            return i + 1; // ���سɹ�����ʱ�ıȽϴ���
        }
        ++i;
    } while (i < m);
    return i; // ���ز���ʧ��ʱ�ıȽϴ���
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
    int n, m, sum = 0;
    cin >> n >> m;
    HashTable hs[m];
    InitHash(hs, m);

    for (int i = 0; i < n - 1; ++i)
    {
        int t;
        cin >> t;
        sum += InsertHash(hs, m, t);
    }

    ShowHash(hs, m);
    cout << sum * 1.0 / (n - 1) << endl; // ���ҳɹ�ʱ��ƽ������
    return 0;
}
