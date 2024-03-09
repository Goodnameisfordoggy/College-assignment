/***
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2023-11-27 11:25:09
 * @FilePath: \c++\c++ BasicAlgorithmHomework\07章\S0709 散列表（链地址法）.cpp
 * @Description:
 * 用链地址法处理冲突构造n个关键字的散列表，散列函数 H(key)=key%m。
部分代码如图所示。
注：输出时只输出h[i]中有关键字的链表元素值，且每个元素值只占5个字符位置。
例（第1、2行为输入）：
12 13
19 14 23 1 68 20 84 27 55 11 10 79
h[1]:   14    1   27   79
h[3]:   68   55
h[6]:   19   84
h[7]:   20
h[10]:   23   10
h[11]:   11
 * @
 * @				*		写字楼里写字间，写字间里程序员；
 * @				*		程序人员写程序，又拿程序换酒钱。
 * @				*		酒醒只在网上坐，酒醉还来网下眠；
 * @				*		酒醉酒醒日复日，网上网下年复年。
 * @				*		但愿老死电脑间，不愿鞠躬老板前；
 * @				*		奔驰宝马贵者趣，公交自行程序员。
 * @				*		别人笑我忒疯癫，我笑自己命太贱；
 * @				*		不见满街漂亮妹，哪个归得程序员？
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
        HT[i].head = NULL; // 初始化散列表，每个槽位的头节点设为空
    }
}

int Hash(int key, int m)
{
    return key % m; // 散列函数 H(key) = key % m
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
