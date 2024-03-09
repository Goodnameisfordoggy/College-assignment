/***
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2023-12-04 12:11:48
 * @FilePath: \c++\c++ BasicAlgorithmHomework\07章\S0707 散列表（二次探测法）.cpp
 * @Description:
 * 设散列函数为H(key)=key%n，设表长为m，用二次探测法处理冲突。
输入关键值，创建散列表。
例（第1、2行输入）：
13 16
19 14 23 1 68 20 84 27 55 11 10 79
hs[0].key=27
hs[1].key=14
hs[2].key=1
hs[3].key=68
hs[4].key=55
hs[5].key=84
hs[6].key=19
hs[7].key=20
hs[9].key=10
hs[10].key=23
hs[11].key=11
hs[13].key=79
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
using namespace std;

typedef struct
{
    int key;
} HashTable;

void InitHash(HashTable hs[], int m)
{
    for (int i = 0; i < m; i++)
    {
        hs[i].key = 0;
    }
}

void InsertHash(HashTable hs[], int n, int m, int key)
{
    int hash = key % n;
    if (hs[hash].key == 0)
    {
        hs[hash].key = key;
    }
    else
    {
        int i = 1, j = 1;
        int pos = hash;
        while (hs[pos].key != 0)
        {
            if (j % 2 == 0)
            {
                pos = (hash + -1 * i * i) % m; // 修正探测位置
                i++;
            }
            else
            {
                pos = (hash + i * i) % m; // 修正探测位置
            }
            j++;
            if (pos < 0)
                pos = pos + m;
        }
        hs[pos].key = key;
    }
}

void ShowHash(HashTable hs[], int m)
{
    for (int i = 0; i < m; i++)
    {
        if (hs[i].key != 0)
        {
            cout << "hs[" << i << "].key=" << hs[i].key << endl;
        }
    }
}

int main()
{
    int n, i; //
    int m;    // 表长为m
    cin >> n >> m;
    HashTable hs[m];
    InitHash(hs, m);            // 初始化散列表，表中元素的k值设为0（空值元素）
    for (i = 0; i < n - 1; i++) // 将n+1个整数添加到散列表中
    {
        int t;
        cin >> t;
        InsertHash(hs, n, m, t);
    }
    ShowHash(hs, m); // 显示散列表（不显示空值元素）
    return 0;
}