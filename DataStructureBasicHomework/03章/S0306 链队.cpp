/***
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2023-10-30 11:08:58
 * @FilePath: \c++\c++ BasicAlgorithmHomework\03章\S0306 链队.cpp
 * @Description:
 * 练习链队的程序。
// 例（第1行为输入）：
// 2.2 3.3 4.4 5.5 6.6
// 2.2
// Dequeue:2.2
// Dequeue:3.3
// Dequeue:4.4
// Dequeue:5.5
// Dequeue:6.6
// Queue empty!
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

typedef float QElemType; // 假设队列中的元素类型为浮点数

// 队列节点结构
struct QNode
{
    QElemType data;
    QNode *next;
};

// 队列结构
struct LinkQueue
{
    QNode *front; // 队头指针
    QNode *rear;  // 队尾指针
};

// 初始化队列
void InitQueue(LinkQueue &lq)
{
    lq.front = lq.rear = new QNode; // 创建一个头结点，并让队头和队尾指针指向它
    lq.front->next = NULL;       // 头结点的next域置为空
}

// 判断队列是否为空
bool QueueEmpty(LinkQueue &lq)
{
    return lq.front == lq.rear;
}

// 入队操作
void EnQueue(LinkQueue &lq, QElemType s)
{
    QNode *newNode = new QNode;
    newNode->data = s;
    newNode->next = NULL;
    lq.rear->next = newNode;
    lq.rear = newNode;
}

// 出队操作
bool DeQueue(LinkQueue &lq, QElemType &s)
{
    if (QueueEmpty(lq))
    {
        return false; // 队列为空，无法出队
    }
    QNode *temp = lq.front->next;
    s = temp->data;
    lq.front->next = temp->next;
    if (lq.rear == temp)
    {
        lq.rear = lq.front; // 如果队列只有一个元素，出队后将rear指向front
    }
    delete temp; // 释放出队的节点
    return true;
}

// 获取队头元素
QElemType GetHead(LinkQueue &lq)
{
    if (!QueueEmpty(lq))
    {
        return lq.front->next->data;
    }
    return -1; // 队列为空，返回一个特定的值表示错误
}

int main()
{
    LinkQueue lq;
    InitQueue(lq); // 初始化链队
    QElemType s;
    int i;
    for (i = 0; i < 5; i++)
    {
        cin >> s;
        EnQueue(lq, s); // 入队
    }
    cout << GetHead(lq) << endl; // 取队头元素
    DeQueue(lq, s);              // 出队
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