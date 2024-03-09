/***
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2023-11-27 10:39:05
 * @FilePath: \c++\c++ BasicAlgorithmHomework\07章\S0702 顺序查找2(设置监视哨) .cpp
 * @Description:
 * 例1（第1、3行为输入）：
66 89 78 90
Please input the score you want to find:
78
78 is found!

例2（第1、3行为输入）：
66 89 78 90
Please input the score you want to find:
79
79 is not found!
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
    int data[MAXSIZE + 1]; // 用数组存储数据，额外预留一个位置作为监视哨
    int length;            // 当前线性表的长度
} SSTable;

// 初始化线性表
void InitList(SSTable &L)
{
    L.length = 0; // 将线性表长度初始化为0
}

// 向线性表中插入数据
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
    L.length = n;   // 更新线性表长度
    L.data[0] = -1; // 设置监视哨为-1（假设成绩不会为负数）
}

// 在线性表中进行顺序查找（设置监视哨）
bool Search_Seq(const SSTable &L, int target)
{
    int i = L.length;       // 从线性表末尾开始向前查找
    SSTable tempL = L;      // 创建一个副本，避免修改原始数据
    tempL.data[0] = target; // 设置监视哨
    while (tempL.data[i] != target)
    {
        --i;
    }
    return i != 0; // 若i不等于0，表示找到了目标
}

int main()
{
    // 线性表的的初始化、插入、取值
    SSTable Lscore;        // 用来存储学生《数据结构》成绩
    InitList(Lscore);      // 初始化线性表
    InsertList(Lscore, 4); // 输入4个学生成绩到线性表
    cout << "Please input the score you want to find:" << endl;
    int s;
    cin >> s; // 输入要查找的成绩
    if (Search_Seq(Lscore, s))
        cout << s << " is found!" << endl;
    else
        cout << s << " is not found!" << endl;

    return 0;
}
