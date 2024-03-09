/***
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2023-12-04 11:34:41
 * @FilePath: \c++\c++ BasicAlgorithmHomework\08章\S0808 归并排序.cpp
 * @Description:
 * 练习书上算法8.11:归并排序。
例（最后1行为输出）：
6
24 -9 66 55 88 77
   -9   24   55   66   77   88
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

const int MAXSIZE = 100;

typedef struct
{
    int r[MAXSIZE + 1]; // 从下标1开始存储数据，r[0]不使用
    int length;         // 顺序表的长度
} SqList;

// 初始化顺序表
void InitSqList(SqList &S, int n)
{
    S.length = n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> S.r[i];
    }
}

// 合并两个有序序列
void Merge(SqList &S, int low, int mid, int high)
{
    int i = low, j = mid + 1, k = 1;
    int *temp = new int[MAXSIZE]; // 临时数组
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
        S.r[m] = temp[l]; // 将排好序的元素放回原数组
    }
    delete[] temp; // 释放临时数组的内存
}

// 归并排序
void MSort(SqList &S, int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        MSort(S, low, mid);       // 对左半部分进行归并排序
        MSort(S, mid + 1, high);  // 对右半部分进行归并排序
        Merge(S, low, mid, high); // 合并两个有序序列
    }
}

void MergeSort(SqList &S)
{
    MSort(S, 1, S.length);
}

// 显示顺序表
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
    InitSqList(S, n); // 初始化SqList，并输入n个整数
    MergeSort(S);     // 归并排序
    ShowList(S);      // 每个KEY值占5个字符位置

    return 0;
}
