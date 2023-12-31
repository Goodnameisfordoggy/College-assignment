/***
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2023-10-08 17:18:20
 * @FilePath: \c++\c++ BasicAlgorithmHomework\02章\S0205 后插法创建单链表.cpp
 * @Description:
 *  利用后插法创建单链表。
// 例（只有第2行为输入）：
// empty!
// Wang Li Gao Miao Long
// 1:Wang
// 2:Li
// 3:Gao
// 4:Miao
// 5:Long
 * @
 * @				/*		写字楼里写字间，写字间里程序员；
 * @				*		程序人员写程序，又拿程序换酒钱。
 * @				*		酒醒只在网上坐，酒醉还来网下眠；
 * @				*		酒醉酒醒日复日，网上网下年复年。
 * @				*		但愿老死电脑间，不愿鞠躬老板前；
 * @				*		奔驰宝马贵者趣，公交自行程序员。
 * @				*		别人笑我忒疯癫，我笑自己命太贱；
 * @				\*		不见满街漂亮妹，哪个归得程序员？
 * @Copyright (c) ${2023} by ${HDJ}, All Rights Reserved.
 */
#include <iostream>
#include <string>

using namespace std;

// 单链表节点结构体
struct Node
{
    string data;
    Node *next;
};

// 单链表结构体
struct LinkList
{
    Node *head;
};

// 初始化单链表
void InitList(LinkList &L)
{
    L.head = NULL;
    cout << "empty!" << endl;
}

// 后插法创建单链表
void CreateList_R(LinkList &L, int n)
{
    Node *tail = NULL; // 尾指针，指向链表尾部
    for (int i = 0; i < n; i++)
    {
        string input;
        cin >> input;

        Node *newNode = new Node;
        newNode->data = input;
        newNode->next = NULL;

        if (L.head == NULL)
        {
            L.head = newNode; // 如果链表为空，新节点作为头节点
            tail = newNode;   // 尾指针指向新节点
        }
        else
        {
            tail->next = newNode; // 后插法，将新节点链接到尾节点后面
            tail = newNode;       // 更新尾指针
        }
    }
}

// 单链表遍历
void showList(LinkList &L)
{
    Node *current = L.head;
    int index = 1;
    while (current != NULL)
    {
        cout << index << ":" << current->data << endl;
        current = current->next;
        index++;
    }
}

int main()
{
    LinkList Lname;
    InitList(Lname);        // 初始化单链表
    showList(Lname);        // 单链表遍历
    CreateList_R(Lname, 5); // 后插法创建单链表
    showList(Lname);        // 单链表遍历
    return 0;
}
