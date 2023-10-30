/***
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2023-10-30 11:08:58
 * @FilePath: \c++\c++ BasicAlgorithmHomework\03��\S0306 ����.cpp
 * @Description:
 * ��ϰ���ӵĳ���
// ������1��Ϊ���룩��
// 2.2 3.3 4.4 5.5 6.6
// 2.2
// Dequeue:2.2
// Dequeue:3.3
// Dequeue:4.4
// Dequeue:5.5
// Dequeue:6.6
// Queue empty!
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

typedef float QElemType; // ��������е�Ԫ������Ϊ������

// ���нڵ�ṹ
struct QNode
{
    QElemType data;
    QNode *next;
};

// ���нṹ
struct LinkQueue
{
    QNode *front; // ��ͷָ��
    QNode *rear;  // ��βָ��
};

// ��ʼ������
void InitQueue(LinkQueue &lq)
{
    lq.front = lq.rear = new QNode; // ����һ��ͷ��㣬���ö�ͷ�Ͷ�βָ��ָ����
    lq.front->next = NULL;       // ͷ����next����Ϊ��
}

// �ж϶����Ƿ�Ϊ��
bool QueueEmpty(LinkQueue &lq)
{
    return lq.front == lq.rear;
}

// ��Ӳ���
void EnQueue(LinkQueue &lq, QElemType s)
{
    QNode *newNode = new QNode;
    newNode->data = s;
    newNode->next = NULL;
    lq.rear->next = newNode;
    lq.rear = newNode;
}

// ���Ӳ���
bool DeQueue(LinkQueue &lq, QElemType &s)
{
    if (QueueEmpty(lq))
    {
        return false; // ����Ϊ�գ��޷�����
    }
    QNode *temp = lq.front->next;
    s = temp->data;
    lq.front->next = temp->next;
    if (lq.rear == temp)
    {
        lq.rear = lq.front; // �������ֻ��һ��Ԫ�أ����Ӻ�rearָ��front
    }
    delete temp; // �ͷų��ӵĽڵ�
    return true;
}

// ��ȡ��ͷԪ��
QElemType GetHead(LinkQueue &lq)
{
    if (!QueueEmpty(lq))
    {
        return lq.front->next->data;
    }
    return -1; // ����Ϊ�գ�����һ���ض���ֵ��ʾ����
}

int main()
{
    LinkQueue lq;
    InitQueue(lq); // ��ʼ������
    QElemType s;
    int i;
    for (i = 0; i < 5; i++)
    {
        cin >> s;
        EnQueue(lq, s); // ���
    }
    cout << GetHead(lq) << endl; // ȡ��ͷԪ��
    DeQueue(lq, s);              // ����
    cout << "Dequeue:" << s << endl;
    for (i = 0; i < 5; i++)
    {
        if (DeQueue(lq, s))
            cout << "Dequeue:" << s << endl;
        else
            cout << "Queue empty!" << endl;
    }

    return 0;
}