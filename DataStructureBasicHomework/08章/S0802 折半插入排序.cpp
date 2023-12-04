/***
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2023-12-04 11:19:18
 * @FilePath: \c++\c++ BasicAlgorithmHomework\08章\S0802 折半插入排序.cpp
 * @Description:
 * 练习算法8.2：折半插入排序。
例（第3行为输出）：
6
96 -2 65 7 89 36
   96   89   65   36    7   -2
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

// 折半插入排序
void BInsertSort(SqList &S)
{
    for (int i = 2; i <= S.length; ++i)
    {
        S.r[0] = S.r[i]; // 设置哨兵
        int low = 1, high = i - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (S.r[0] > S.r[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        for (int j = i - 1; j >= high + 1; --j)
        {
            S.r[j + 1] = S.r[j]; // 记录后移
        }
        S.r[high + 1] = S.r[0]; // 插入到正确位置
    }
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
    int n;
    cin >> n;
    SqList S;
    InitSqList(S, n); // 初始化SqList，并输入n个整数
    BInsertSort(S);   // 折半插入排序
    ShowList(S);      // 每个KEY值占5个字符位置

    return 0;
}
