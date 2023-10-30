/***
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2023-10-30 11:03:39
 * @FilePath: \c++\c++ BasicAlgorithmHomework\03��\S0303 ��ջ.cpp
 * @Description:
 * ��ջ����ջ���ջ��
// ���ִ�����ͼ��ʾ��
// ����ǰ3��Ϊ���룩��
// 3Hebei
// Tangshan fengrun
// Handan wuan
// Handan wuan
// Tangshan fengrun
// Hebei
 * @
 * @				*		д��¥��д�ּ䣬д�ּ������Ա��
 * @				*		������Աд�������ó��򻻾�Ǯ��
 * @				*		����ֻ���������������������ߣ�
 * @				*		��������ո��գ����������긴�ꡣ
 * @				*		��Ը�������Լ䣬��Ը�Ϲ��ϰ�ǰ��
 * @				*		���۱������Ȥ���������г���Ա��
 * @				*		����Ц��߯��񲣬��Ц�Լ���̫����
 * @				*		��������Ư���ã��ĸ���ó���Ա��
 * @Copyright (c) ${2023} by ${HDJ}, All Rights Reserved.
 */

#include <iostream>
#include <string>
using namespace std;

// ��ջ�Ľڵ�ṹ
struct StackNode
{
    string data;
    StackNode *next;
};

// ��ջ�ṹ
struct LinkStack
{
    StackNode *top; // ջ��ָ��
};

// ��ʼ����ջ
void InitStack(LinkStack &Ls)
{
    Ls.top = NULL; // ջ��ָ����Ϊ��
}

// �ж���ջ�Ƿ�Ϊ��
bool StackEmpty(LinkStack &Ls)
{
    return Ls.top == NULL;
}

// ��ջ����
void Push(LinkStack &Ls, string s)
{
    StackNode *newNode = new StackNode;
    newNode->data = s;
    newNode->next = Ls.top;
    Ls.top = newNode;
}

// ��ջ����
void Pop(LinkStack &Ls)
{
    if (StackEmpty(Ls))
    {
        return;
    }
    StackNode *temp = Ls.top;
    Ls.top = Ls.top->next;
    delete temp; // �ͷ��ڴ�
}

// ��ȡջ��Ԫ��
string GetTop(LinkStack &Ls)
{
    if (StackEmpty(Ls))
    {
        return ""; // ջΪ�գ����ؿ��ַ���
    }
    return Ls.top->data;
}

int main()
{
    LinkStack Ls;
    InitStack(Ls); // ��ʼ����ջ
    int n;
    string s;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        getline(cin, s);
        Push(Ls, s); // ��ջ
    }

    while (!StackEmpty(Ls))
    {
        cout << GetTop(Ls) << endl; // ȡջ��Ԫ��
        Pop(Ls);                    // ��ջ
    }
}