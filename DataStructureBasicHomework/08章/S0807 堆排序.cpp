/***
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2023-12-04 11:33:21
 * @FilePath: \c++\c++ BasicAlgorithmHomework\08章\S0807 堆排序.cpp
 * @Description:
 * 练习书上算法8.9：堆排序。
例（最后1行为输出）：
5
234 3 5 34 -54
  -54    3    5   34  234
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

// 调整堆，使其满足堆的性质
void HeapAdjust(SqList &S, int s, int m)
{
    int temp = S.r[s];
    for (int j = 2 * s; j <= m; j *= 2)
    {
        if (j < m && S.r[j] < S.r[j + 1])
        {
            ++j; // 找到左右孩子节点中较大的一个
        }
        if (temp >= S.r[j])
        {
            break; // 如果根节点大于左右孩子节点，则退出循环
        }
        S.r[s] = S.r[j]; // 将较大的孩子节点调整到根节点位置
        s = j;
    }
    S.r[s] = temp; // 将原根节点值放到最终位置
}

// 堆排序
void HeapSort(SqList &S)
{
    for (int i = S.length / 2; i > 0; --i)
    {
        HeapAdjust(S, i, S.length); // 建立大顶堆
    }
    for (int i = S.length; i > 1; --i)
    {
        swap(S.r[1], S.r[i]);    // 将堆顶元素与末尾元素交换
        HeapAdjust(S, 1, i - 1); // 调整剩余元素，使其满足堆的性质
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
    int dt[3] = {5, 3, 1};
    int n;
    cin >> n;
    SqList S;
    InitSqList(S, n); // 初始化SqList，并输入n个整数
    HeapSort(S);      // 堆排序
    ShowList(S);      // 每个KEY值占5个字符位置

    return 0;
}
