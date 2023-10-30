/***
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2023-10-30 10:51:13
 * @FilePath: \c++\c++ BasicAlgorithmHomework\03��\S0301 ��ջ���ջ.cpp
 * @Description:
 * ��ϰ˳��ջ����ջ���ջ�����ִ�����ͼ��ʾ��
// ������1��Ϊ���� ����
// 1 2 3 4
// 4
// 3
// 2
// 1
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

#define MAXSIZE 100 // ����ջ���������

typedef struct
{
    int data[MAXSIZE];
    int top; // ջ��ָ��
} SqStack;

// ��ʼ��ջ
void InitStack(SqStack &S)
{
    S.top = -1; // ջ��ָ����Ϊ-1����ʾ��ջ
}

// �ж�ջ�Ƿ�Ϊ��
bool isEmpty(SqStack &S)
{
    return S.top == -1;
}

// �ж�ջ�Ƿ�����
bool isFull(SqStack &S)
{
    return S.top == MAXSIZE - 1;
}

// ��ջ����
bool Push(SqStack &S, int x)
{
    if (isFull(S))
    {
        return false;
    }
    S.data[++S.top] = x;
    return true;
}

// ��ջ����
bool Pop(SqStack &S)
{
    if (isEmpty(S))
    {
        return false;
    }
    S.top--;
    return true;
}

// ��ȡջ��Ԫ��
int GetTop(SqStack &S)
{
    if (isEmpty(S))
    {
        return -1; // ��ʾջΪ��
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