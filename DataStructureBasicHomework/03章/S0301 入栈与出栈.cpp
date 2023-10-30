/***
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2023-10-30 10:51:13
 * @FilePath: \c++\c++ BasicAlgorithmHomework\03章\S0301 入栈与出栈.cpp
 * @Description:
 * 练习顺序栈的入栈与出栈，部分代码如图所示。
// 例（第1行为输入 ）：
// 1 2 3 4
// 4
// 3
// 2
// 1
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

#define MAXSIZE 100 // 定义栈的最大容量

typedef struct
{
    int data[MAXSIZE];
    int top; // 栈顶指针
} SqStack;

// 初始化栈
void InitStack(SqStack &S)
{
    S.top = -1; // 栈顶指针置为-1，表示空栈
}

// 判断栈是否为空
bool isEmpty(SqStack &S)
{
    return S.top == -1;
}

// 判断栈是否已满
bool isFull(SqStack &S)
{
    return S.top == MAXSIZE - 1;
}

// 入栈操作
bool Push(SqStack &S, int x)
{
    if (isFull(S))
    {
        return false;
    }
    S.data[++S.top] = x;
    return true;
}

// 出栈操作
bool Pop(SqStack &S)
{
    if (isEmpty(S))
    {
        return false;
    }
    S.top--;
    return true;
}

// 获取栈顶元素
int GetTop(SqStack &S)
{
    if (isEmpty(S))
    {
        return -1; // 表示栈为空
    }
    return S.data[S.top];
}

int main()
{
    SqStack sint;
    InitStack(sint);

    int s;
    for (int i = 0; i < 4; i++)
    {
        cin >> s;
        Push(sint, s);
    }

    for (int i = 0; i < 4; i++)
    {
        int e = GetTop(sint);
        Pop(sint);
        cout << e << endl;
    }
    return 0;
}