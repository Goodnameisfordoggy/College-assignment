/***
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2023-10-30 11:21:25
 * @FilePath: \c++\c++ BasicAlgorithmHomework\03章\S0307 十进制转八进制.cpp
 * @Description:
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

// 链栈的节点结构
struct StackNode
{
    int data;
    StackNode *next;
};

// 链栈结构
struct LinkStack
{
    StackNode *top; // 栈顶指针
};

// 初始化链栈
void InitStack(LinkStack &Ls)
{
    Ls.top = NULL; // 栈顶指针置为空
}

// 判断链栈是否为空
bool StackEmpty(LinkStack &Ls)
{
    return Ls.top == NULL;
}

// 入栈操作
void Push(LinkStack &Ls, int x)
{
    StackNode *newNode = new StackNode;
    newNode->data = x;
    newNode->next = Ls.top;
    Ls.top = newNode;
}

// 出栈操作
bool Pop(LinkStack &Ls, int &x)
{
    if (StackEmpty(Ls))
    {
        return false; // 栈为空，无法出栈
    }
    StackNode *temp = Ls.top;
    x = temp->data;
    Ls.top = Ls.top->next;
    delete temp; // 释放内存
    return true;
}

// 十进制转八进制
void conversion(int n)
{
    LinkStack Ls;
    InitStack(Ls);

    while (n != 0)
    {
        int remainder = n % 8;
        Push(Ls, remainder);
        n = n / 8;
    }

    while (!StackEmpty(Ls))
    {
        int digit;
        Pop(Ls, digit);
        cout << digit;
    }
}

int main()
{
    int n;
    cin >> n;
    conversion(n); // 十进制n转换为八进制
    cout << endl;
    return 0;
}