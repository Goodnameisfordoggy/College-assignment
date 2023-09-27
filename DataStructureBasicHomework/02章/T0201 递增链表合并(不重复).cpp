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

// ������ڵ�ṹ��
struct Node
{
    int data;
    Node *next;
};

// ������ṹ��
struct LinkList
{
    Node *head;
};

// ��ʼ����ͷ���ĵ�����
void InitList(LinkList &L)
{
    L.head = new Node;
    L.head->next = NULL;
}

// ��������������ȥ���ظ����ݣ�
void CreateList_Up(LinkList &L, int n)
{
    Node *current = L.head;
    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;

        // ����½ڵ�������Ƿ��Ѿ�������������
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

        // ������ݲ��ظ����Ŵ����������½ڵ�
        if (!duplicate)
        {
            // ����һ���½ڵ�
            Node *newNode = new Node;
            newNode->data = input;
            newNode->next = NULL;

            // �������Ϊ�ջ����½ڵ������С�ڵ�ǰ�ڵ������
            if (current->next == NULL || input < current->next->data)
            {
                newNode->next = current->next;
                current->next = newNode;
            }
            else
            {
                // Ѱ�Ҳ���λ��
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
// �ϲ�����������������ȥ���ظ����ݣ�
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
        { // ������ȣ�ֻȡһ��
            pc->next = pa;
            pa = pa->next;
            pb = pb->next;
        }
        pc = pc->next;
    }

    pc->next = (pa != NULL) ? pa : pb;
}

// ���������
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
    CreateList_Up(La, 3); // ��������������ȥ���ظ����ݣ�
    cout << "Show La:" << endl;
    showList(La);         // ���������
    CreateList_Up(Lb, 4); // ��������������ȥ���ظ����ݣ�
    cout << "Show Lb:" << endl;
    showList(Lb); // ���������

    MergeList(La, Lb, Lc);
    cout << "Show Lc:" << endl;
    showList(Lc); // ���������
    return 0;
}