/***
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2023-10-30 12:11:31
 * @FilePath: \c++\c++ BasicAlgorithmHomework\05��\S0501 �������˳�򴴽���������.cpp
 * @Description:
 * ���������˳�򴴽������������������򡢺��������������
// ���ִ�����ͼ��ʾ��
// ��1����1 ��Ϊ���룩��
// ABC##DE#G##F###
// ABCDEGF
// CBEGDFA
// CGEFDBA
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

// ���������Ķ���
struct BiTNode
{
    char data;
    BiTNode *lchild; // ������
    BiTNode *rchild; // ������
};

// �������Ķ���
typedef BiTNode *BiTree;

// ������������
void CreateBiTree(BiTree &T)
{
    char ch;
    cin >> ch;
    if (ch == '#')
    {
        T = NULL;
    }
    else
    {
        T = new BiTNode;
        T->data = ch;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
}

// �������������
void PreOrderTraverse(BiTree T)
{
    if (T != NULL)
    {
        cout << T->data;
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}

// �������������
void InOrderTraverse(BiTree T)
{
    if (T != NULL)
    {
        InOrderTraverse(T->lchild);
        cout << T->data;
        InOrderTraverse(T->rchild);
    }
}

// �������������
void PostOrderTraverse(BiTree T)
{
    if (T != NULL)
    {
        PostOrderTraverse(T->lchild);
        PostOrderTraverse(T->rchild);
        cout << T->data;
    }
}

int main()
{
    BiTree T;
    CreateBiTree(T); // �������˳������������

    cout << "PreOrder: ";
    PreOrderTraverse(T);
    cout << endl;

    cout << "InOrder: ";
    InOrderTraverse(T);
    cout << endl;

    cout << "PostOrder: ";
    PostOrderTraverse(T);
    cout << endl;

    return 0;
}