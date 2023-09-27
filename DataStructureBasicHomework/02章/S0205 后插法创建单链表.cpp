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
