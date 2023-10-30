/***
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2023-10-30 11:21:25
 * @FilePath: \c++\c++ BasicAlgorithmHomework\03��\S0307 ʮ����ת�˽���.cpp
 * @Description:
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
using namespace std;

// ��ջ�Ľڵ�ṹ
struct StackNode
{
    int data;
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
void Push(LinkStack &Ls, int x)
{
    StackNode *newNode = new StackNode;
    newNode->data = x;
    newNode->next = Ls.top;
    Ls.top = newNode;
}

// ��ջ����
bool Pop(LinkStack &Ls, int &x)
{
    if (StackEmpty(Ls))
    {
        return false; // ջΪ�գ��޷���ջ
    }
    StackNode *temp = Ls.top;
    x = temp->data;
    Ls.top = Ls.top->next;
    delete temp; // �ͷ��ڴ�
    return true;
}

// ʮ����ת�˽���
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
    conversion(n); // ʮ����nת��Ϊ�˽���
    cout << endl;
    return 0;
}