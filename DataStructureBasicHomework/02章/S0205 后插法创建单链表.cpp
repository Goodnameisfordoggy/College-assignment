#include <iostream>
#include <string>

using namespace std;

// ������ڵ�ṹ��
struct Node
{
    string data;
    Node *next;
};

// ������ṹ��
struct LinkList
{
    Node *head;
};

// ��ʼ��������
void InitList(LinkList &L)
{
    L.head = NULL;
    cout << "empty!" << endl;
}

// ��巨����������
void CreateList_R(LinkList &L, int n)
{
    Node *tail = NULL; // βָ�룬ָ������β��
    for (int i = 0; i < n; i++)
    {
        string input;
        cin >> input;

        Node *newNode = new Node;
        newNode->data = input;
        newNode->next = NULL;

        if (L.head == NULL)
        {
            L.head = newNode; // �������Ϊ�գ��½ڵ���Ϊͷ�ڵ�
            tail = newNode;   // βָ��ָ���½ڵ�
        }
        else
        {
            tail->next = newNode; // ��巨�����½ڵ����ӵ�β�ڵ����
            tail = newNode;       // ����βָ��
        }
    }
}

// ���������
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
    InitList(Lname);        // ��ʼ��������
    showList(Lname);        // ���������
    CreateList_R(Lname, 5); // ��巨����������
    showList(Lname);        // ���������
    return 0;
}
