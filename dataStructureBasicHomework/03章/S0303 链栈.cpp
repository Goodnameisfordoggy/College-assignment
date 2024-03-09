/***
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2023-10-30 11:03:39
 * @FilePath: \c++\c++ BasicAlgorithmHomework\03章\S0303 链栈.cpp
 * @Description:
 * 链栈的入栈与出栈。
// 部分代码如图所示。
// 例（前3行为输入）：
// 3Hebei
// Tangshan fengrun
// Handan wuan
// Handan wuan
// Tangshan fengrun
// Hebei
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
#include <string>
using namespace std;

// 链栈的节点结构
struct StackNode
{
    string data;
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
void Push(LinkStack &Ls, string s)
{
    StackNode *newNode = new StackNode;
    newNode->data = s;
    newNode->next = Ls.top;
    Ls.top = newNode;
}

// 出栈操作
void Pop(LinkStack &Ls)
{
    if (StackEmpty(Ls))
    {
        return;
    }
    StackNode *temp = Ls.top;
    Ls.top = Ls.top->next;
    delete temp; // 释放内存
}

// 获取栈顶元素
string GetTop(LinkStack &Ls)
{
    if (StackEmpty(Ls))
    {
        return ""; // 栈为空，返回空字符串
    }
    return Ls.top->data;
}

int main()
{
    LinkStack Ls;
    InitStack(Ls); // 初始化链栈
    int n;
    string s;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        getline(cin, s);
        Push(Ls, s); // 入栈
    }

    while (!StackEmpty(Ls))
    {
        cout << GetTop(Ls) << endl; // 取栈顶元素
        Pop(Ls);                    // 出栈
    }
}