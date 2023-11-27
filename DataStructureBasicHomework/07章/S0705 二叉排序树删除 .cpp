/***
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2023-11-27 11:08:49
 * @FilePath: \c++\c++ BasicAlgorithmHomework\07��\S0705 ����������ɾ�� .cpp
 * @Description:
 * ��ϰ�����㷨7.7����ɶ����������н���ɾ����
��1����1��4��Ϊ���룩��
HEBEI#
BEHI
HEBI
E
BHI
HBI

��2����1��4��Ϊ���룩��
HEBEI#
BEHI
HEBI
E
BHI
HBI

��3����1��4��Ϊ���룩��
HEBEI#
BEHI
HEBI
I
BEH
HEB
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

// ��������������Ľڵ�ṹ
typedef struct BSTNode
{
    char key;
    struct BSTNode *left;
    struct BSTNode *right;
} *BSTree;

// ��������������
void CreateBST(BSTree &T)
{
    T = nullptr; // ��ʼ��Ϊ����
    char data;
    cin >> data;
    while (data != '#')
    {
        BSTNode *p = new BSTNode;
        p->key = data;
        p->left = nullptr;
        p->right = nullptr;

        if (T == nullptr)
        {
            T = p; // ��һ���ڵ���Ϊ���ڵ�
        }
        else
        {
            BSTNode *current = T;
            BSTNode *parent = nullptr;
            while (current != nullptr)
            {
                parent = current;
                if (data < current->key)
                {
                    current = current->left;
                }
                else
                {
                    current = current->right;
                }
            }
            if (data < parent->key)
            {
                parent->left = p;
            }
            else
            {
                parent->right = p;
            }
        }
        cin >> data;
    }
}

// �����������������
void InOrderTraverse(BSTree T)
{
    if (T != nullptr)
    {
        InOrderTraverse(T->left);
        cout << T->key;
        InOrderTraverse(T->right);
    }
}

// �����������������
void PreOrderTraverse(BSTree T)
{
    if (T != nullptr)
    {
        cout << T->key;
        PreOrderTraverse(T->left);
        PreOrderTraverse(T->right);
    }
}

// ���Ҷ�����������ָ���ڵ�
BSTNode *SearchBST(BSTree T, char key)
{
    BSTNode *current = T;
    while (current != nullptr && current->key != key)
    {
        if (key < current->key)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }
    return current;
}

// ɾ��������������ָ���ڵ�
bool DeleteBST(BSTree &T, char key)
{
    if (T == nullptr)
    {
        return false; // ��Ϊ�գ��޷�ɾ��
    }
    if (T->key == key)
    {
        BSTNode *p = T;
        if (T->left == nullptr)
        {
            T = T->right;
        }
        else if (T->right == nullptr)
        {
            T = T->left;
        }
        else
        {
            BSTNode *s = T->right;
            BSTNode *prev = T; // ���ڼ�¼����ڵ�ĸ��ڵ�
            while (s->left != nullptr)
            {
                prev = s;
                s = s->left;
            }
            if (prev == T)
            {
                s->left = T->left;
                T = s;
            }
            else
            {
                prev->left = s->right;
                s->left = T->left;
                s->right = T->right;
                T = s;
            }
        }
        delete p;
        return true;
    }
    BSTNode *parent = nullptr;
    BSTNode *current = T;
    while (current != nullptr && current->key != key)
    {
        parent = current;
        if (key < current->key)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }
    if (current == nullptr)
    {
        return false; // û���ҵ�Ҫɾ���Ľڵ�
    }
    BSTNode *p = current;
    if (current->left == nullptr)
    {
        if (parent->left == current)
        {
            parent->left = current->right;
        }
        else
        {
            parent->right = current->right;
        }
        delete p;
    }
    else if (current->right == nullptr)
    {
        if (parent->left == current)
        {
            parent->left = current->left;
        }
        else
        {
            parent->right = current->left;
        }
        delete p;
    }
    else
    {
        BSTNode *s = current->right;
        BSTNode *prev = current; // ���ڼ�¼����ڵ�ĸ��ڵ�
        while (s->left != nullptr)
        {
            prev = s;
            s = s->left;
        }
        if (prev == current)
        {
            s->left = current->left;
            if (parent->left == current)
            {
                parent->left = s;
            }
            else
            {
                parent->right = s;
            }
            delete p;
        }
        else
        {
            prev->left = s->right;
            s->left = current->left;
            s->right = current->right;
            if (parent->left == current)
            {
                parent->left = s;
            }
            else
            {
                parent->right = s;
            }
            delete p;
        }
    }
    return true;
}

int main()
{
    BSTree T;
    CreateBST(T); // ���������������������ַ�����#��ʾ����
    InOrderTraverse(T);
    cout << endl; // �������
    PreOrderTraverse(T);
    cout << endl; // �������

    char key;
    cin >> key;
    DeleteBST(T, key); // ɾ���ؼ�ֵΪkey�Ľ��
    InOrderTraverse(T);
    cout << endl; // �������
    PreOrderTraverse(T);
    cout << endl; // �������

    return 0;
}
