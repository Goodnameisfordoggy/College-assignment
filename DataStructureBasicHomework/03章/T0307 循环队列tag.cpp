/***
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2023-10-09 17:50:30
 * @FilePath: \c++\c++ BasicAlgorithmHomework\03章\T0.cpp
 * @Description:
 * 假设以 数组Q[m] 存放循环队列中的元素，同时设置一个标志tag, 以tag= 0 和tag= 1
 * 来区别在队头指针 (front) 和队尾指针 (rear) 相等时，队列状态为 “空” 还是 “满”。
 * 试编写与此结构相应的插入 (EnQueue) 和删除 (DeQueue) 算法。部分代码如图所示。
// 例1（第1行为输入）：
// 3 2.2 3.3 4.4
// EnQueue:2.2
// EnQueue:3.3
// EnQueue:4.4
// DeQueue:2.2
// DeQueue:3.3
// DeQueue:4.4

// 例2（第1行为输入）：
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
#define ERROR 0
#define OK 1
// #define OVERFLOW -2 // 题目给的,没用上
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
    Q.tag = 0; // 初始状态 empty
}

int EnQueue(SqQueue &Q, float x)
{
    if (Q.front == Q.rear && Q.tag == 1)
    {
        return ERROR; // 队列已满
    }

    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1) % MAXSIZE;

    if (Q.rear == Q.front)
    {
        Q.tag = 1; // 标记为满
    }

    return OK;
}

int DeQueue(SqQueue &Q, float &x)
{
    if (Q.front == Q.rear && Q.tag == 0)
    {
        return ERROR; // 队列已空
    }

    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % MAXSIZE;

    if (Q.front == Q.rear)
    {
        Q.tag = 0; // 标记为空
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