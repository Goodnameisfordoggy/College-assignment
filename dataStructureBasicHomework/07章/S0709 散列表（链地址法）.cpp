/***
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2023-11-27 11:25:09
 * @FilePath: \c++\c++ BasicAlgorithmHomework\07��\S0709 ɢ�б�����ַ����.cpp
 * @Description:
 * ������ַ�������ͻ����n���ؼ��ֵ�ɢ�б�ɢ�к��� H(key)=key%m��
���ִ�����ͼ��ʾ��
ע�����ʱֻ���h[i]���йؼ��ֵ�����Ԫ��ֵ����ÿ��Ԫ��ֵֻռ5���ַ�λ�á�
������1��2��Ϊ���룩��
12 13
19 14 23 1 68 20 84 27 55 11 10 79
h[1]:   14    1   27   79
h[3]:   68   55
h[6]:   19   84
h[7]:   20
h[10]:   23   10
h[11]:   11
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
#include <vector>
using namespace std;

struct Node
{
    int value;
    Node *next;
    Node(int val) : value(val), next(NULL) {}
};

struct HashTable
{
    Node *head;
};

void InitHashTable(HashTable HT[], int m)
{
    for (int i = 0; i < m; ++i)
    {
        HT[i].head = NULL; // ��ʼ��ɢ�б�ÿ����λ��ͷ�ڵ���Ϊ��
    }
}

int Hash(int key, int m)
{
    return key % m; // ɢ�к��� H(key) = key % m
}

void InsertHash(HashTable HT[], int key, int m)
{
    int index = Hash(key, m);
    if (HT[index].head == NULL)
    {
        HT[index].head = new Node(key);
    }
    else
    {
        Node *newNode = new Node(key);
        newNode->next = HT[index].head;
        HT[index].head = newNode;
    }
}

void ShowHash(HashTable HT[], int m)
{
    for (int i = 0; i < m; ++i)
    {
        Node *current = HT[i].head;
        if (current != NULL)
        {
            cout << "h[" << i << "]:";
            while (current != NULL)
            {
                cout << "   " << current->value;
                current = current->next;
            }
            cout << endl;
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    HashTable HT[m];
    InitHashTable(HT, m);

    for (int i = 0; i < n; ++i)
    {
        int s;
        cin >> s;
        InsertHash(HT, s, m);
    }

    ShowHash(HT, m);
    return 0;
}
