/*
empty!
Wang Li Gao Miao Long  //cin
1:Wang
2:Li
3:Gao
4:Miao
5:Long
*/

#include <iostream>

using namespace std;

// 单链表节点结构体
struct Node
{
    int data;
    Node *next;
};

// 单链表结构体
struct LinkList
{
    Node *head;
};

// 初始化带头结点的单链表
void InitList(LinkList &L)
{
    L.head = new Node;
    L.head->next = NULL;
}

// 创建递增单链表（去掉重复数据）
void CreateList_Up(LinkList &L, int n)
{
    Node *current = L.head;
    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;

        // 检查新节点的数据是否已经存在于链表中
        bool duplicate = false;
        Node *temp = current->next;
        while (temp != NULL)
        {
            if (temp->data == input)
            {
                duplicate = true;
                break;
            }
            temp = temp->next;
        }

        // 如果数据不重复，才创建并插入新节点
        if (!duplicate)
        {
            // 创建一个新节点
            Node *newNode = new Node;
            newNode->data = input;
            newNode->next = NULL;

            // 如果链表为空或者新节点的数据小于当前节点的数据
            if (current->next == NULL || input < current->next->data)
            {
                newNode->next = current->next;
                current->next = newNode;
            }
            else
            {
                // 寻找插入位置
                Node *temp = current->next;
                while (temp->next != NULL && input > temp->next->data)
                {
                    temp = temp->next;
                }
                newNode->next = temp->next;
                temp->next = newNode;
            }
        }
    }
}
// 合并两个递增有序链表（去除重复数据）
void MergeList(LinkList &La, LinkList &Lb, LinkList &Lc)
{
    Node *pa = La.head->next;
    Node *pb = Lb.head->next;
    Node *pc = Lc.head;

    while (pa != NULL && pb != NULL)
    {
        if (pa->data < pb->data)
        {
            pc->next = pa;
            pa = pa->next;
        }
        else if (pa->data > pb->data)
        {
            pc->next = pb;
            pb = pb->next;
        }
        else
        { // 数据相等，只取一个
            pc->next = pa;
            pa = pa->next;
            pb = pb->next;
        }
        pc = pc->next;
    }

    pc->next = (pa != NULL) ? pa : pb;
}

// 单链表遍历
void showList(LinkList &L)
{
    Node *current = L.head->next;
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
    LinkList La, Lb, Lc;
    InitList(La);
    InitList(Lb);
    InitList(Lc);
    CreateList_Up(La, 3); // 创建递增单链表（去掉重复数据）
    cout << "Show La:" << endl;
    showList(La);         // 单链表遍历
    CreateList_Up(Lb, 4); // 创建递增单链表（去掉重复数据）
    cout << "Show Lb:" << endl;
    showList(Lb); // 单链表遍历

    MergeList(La, Lb, Lc);
    cout << "Show Lc:" << endl;
    showList(Lc); // 单链表遍历
    return 0;
}