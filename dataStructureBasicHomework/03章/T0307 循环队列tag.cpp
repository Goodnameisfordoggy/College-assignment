/***
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2023-10-09 17:50:30
 * @FilePath: \c++\c++ BasicAlgorithmHomework\03��\T0.cpp
 * @Description:
 * ������ ����Q[m] ���ѭ�������е�Ԫ�أ�ͬʱ����һ����־tag, ��tag= 0 ��tag= 1
 * �������ڶ�ͷָ�� (front) �Ͷ�βָ�� (rear) ���ʱ������״̬Ϊ ���ա� ���� ��������
 * �Ա�д��˽ṹ��Ӧ�Ĳ��� (EnQueue) ��ɾ�� (DeQueue) �㷨�����ִ�����ͼ��ʾ��
// ��1����1��Ϊ���룩��
// 3 2.2 3.3 4.4
// EnQueue:2.2
// EnQueue:3.3
// EnQueue:4.4
// DeQueue:2.2
// DeQueue:3.3
// DeQueue:4.4

// ��2����1��Ϊ���룩��
// 5 1.1 2.2 3.3 4.4 5.5
// EnQueue:1.1
// EnQueue:2.2
// EnQueue:3.3
// Full!
// Full!
// DeQueue:1.1
// DeQueue:2.2
// DeQueue:3.3
// Empty!
// Empty!
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
#define ERROR 0
#define OK 1
// #define OVERFLOW -2 // ��Ŀ����,û����
#define MAXSIZE 3

typedef struct
{
    float data[MAXSIZE];
    int front, rear;
    int tag; // 0: empty, 1: full
} SqQueue;

void InitQueue(SqQueue &Q)
{
    Q.front = Q.rear = 0;
    Q.tag = 0; // ��ʼ״̬ empty
}

int EnQueue(SqQueue &Q, float x)
{
    if (Q.front == Q.rear && Q.tag == 1)
    {
        return ERROR; // ��������
    }

    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1) % MAXSIZE;

    if (Q.rear == Q.front)
    {
        Q.tag = 1; // ���Ϊ��
    }

    return OK;
}

int DeQueue(SqQueue &Q, float &x)
{
    if (Q.front == Q.rear && Q.tag == 0)
    {
        return ERROR; // �����ѿ�
    }

    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % MAXSIZE;

    if (Q.front == Q.rear)
    {
        Q.tag = 0; // ���Ϊ��
    }

    return OK;
}

int main()
{
    SqQueue Q;
    InitQueue(Q);
    int i, n;
    float f;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> f;
        if (EnQueue(Q, f) == ERROR)
            cout << "Full!" << endl;
        else
            cout << "EnQueue:" << f << endl;
    }

    for (i = 0; i < n; i++)
    {
        if (DeQueue(Q, f) == ERROR)
            cout << "Empty!" << endl;
        else
            cout << "DeQueue:" << f << endl;
    }
    return 0;
}