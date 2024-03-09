/***
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2023-12-04 10:44:39
 * @FilePath: \c++\c++ BasicAlgorithmHomework\07章\1.cpp
 * @Description:
 * 在S0703的基础上修改程序，使用递归方法进行折半查找。
例1（第1、2、5行为输入）：
5
88 90 78 66 89
   66   78   88   89   90
Please input the score you want to find:
88
Location of 88 is 3

例2（第1、2、5行为输入）：
5
88 90 78 66 89
   66   78   88   89   90
Please input the score you want to find:
83
83 is not found!
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

// 线性表的结构体定义
const int MAXSIZE = 100;
typedef struct
{
    int r[MAXSIZE]; // 用于存储数据的数组
    int length;     // 线性表的长度
} SSTable;

// 初始化线性表
void InitList(SSTable &L)
{
    L.length = 0;
}

// 将成绩插入线性表
void InsertList(SSTable &L, int n)
{
    for (int i = 1; i <= n; ++i)
    {
        cin >> L.r[i];
        L.length++;
    }
}

// 成绩从小到大排序
void SortList(SSTable &L, int n)
{
    for (int i = 1; i <= n - 1; ++i)
    {
        for (int j = i + 1; j <= n; ++j)
        {
            if (L.r[i] > L.r[j])
            {
                int temp = L.r[i];
                L.r[i] = L.r[j];
                L.r[j] = temp;
            }
        }
    }
}

// 输出线性表
void ShowList(SSTable L, int n)
{
    for (int i = 1; i <= n; ++i)
    {
        cout.width(5);
        cout << L.r[i];
    }
    cout << endl;
}

// 折半查找（递归实现）
int Search_Seq(SSTable L, int key, int low, int high)
{
    if (low > high)
    {
        return 0; // 未找到
    }

    int mid = (low + high) / 2;

    if (L.r[mid] == key)
    {
        return mid; // 找到了
    }
    else if (L.r[mid] > key)
    {
        return Search_Seq(L, key, low, mid - 1); // 在左半部分查找
    }
    else
    {
        return Search_Seq(L, key, mid + 1, high); // 在右半部分查找
    }
}

int main()
{
    // 线性表的的初始化、插入、取值
    SSTable Lscore;   // 用来存储学生《数据结构》成绩
    InitList(Lscore); // 初始化线性表

    int n;
    cin >> n;
    InsertList(Lscore, n); // 输入n个学生成绩到线性表
    SortList(Lscore, n);   // 成绩从小到大排序
    ShowList(Lscore, n);   // 输出成绩，每个成绩占5个字符位置

    cout << "Please input the score you want to find:" << endl;
    int s;
    cin >> s; // 输入要查找的成绩
    int low = 1, high = n;
    int loc = Search_Seq(Lscore, s, low, high);
    if (loc != 0)
        cout << "Location of " << s << " is " << loc << endl;
    else
        cout << s << " is not found!" << endl;

    return 0;
}
