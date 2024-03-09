/***
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2023-11-27 10:56:11
 * @FilePath: \c++\c++ BasicAlgorithmHomework\07章\S0703 折半查找 .cpp
 * @Description:
 * 注意输入的5个数按从小到大输入。
例1（第1、3行为输入）：
55 66 77 88 99
Please input the score you want to find:
99
Location of 99 is 5

例2（第1、3行为输入）：
55 66 77 88 99
Please input the score you want to find:
90
90 is not found!
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

#define MAXSIZE 100 // 定义线性表的最大长度

typedef struct
{
    int data[MAXSIZE + 1]; // 用数组存储数据，额外预留一个位置
    int length;            // 当前线性表的长度
} SSTable;

// 初始化线性表
void InitList(SSTable &L)
{
    L.length = 0; // 将线性表长度初始化为0
}

// 向线性表中插入数据并保持有序
void InsertList(SSTable &L, int n)
{
    if (n > MAXSIZE)
    {
        cout << "Exceeds maximum size!" << endl;
        return;
    }
    for (int i = 1; i <= n; ++i)
    {
        cin >> L.data[i]; // 逐个读入成绩数据，从下标1开始
    }
    L.length = n; // 更新线性表长度
}

// 在有序线性表中进行折半查找
int Search_Seq(const SSTable &L, int target)
{
    int low = 1, high = L.length;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (L.data[mid] == target)
        {
            return mid; // 找到目标值
        }
        else if (L.data[mid] < target)
        {
            low = mid + 1; // 在右半部分继续查找
        }
        else
        {
            high = mid - 1; // 在左半部分继续查找
        }
    }
    return 0; // 未找到目标值
}

int main()
{
    // 线性表的的初始化、插入、取值
    SSTable Lscore;        // 用来存储学生《数据结构》成绩
    InitList(Lscore);      // 初始化线性表
    InsertList(Lscore, 5); // 输入5个学生成绩到线性表
    cout << "Please input the score you want to find:" << endl;
    int s;
    cin >> s; // 输入要查找的成绩
    int loc = Search_Seq(Lscore, s);
    if (loc != 0)
        cout << "Location of " << s << " is " << loc << endl;
    else
        cout << s << " is not found!" << endl;

    return 0;
}