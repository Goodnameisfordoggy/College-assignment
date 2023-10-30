/***
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2023-10-30 12:25:13
 * @FilePath: \c++\c++ BasicAlgorithmHomework\05��\S0502 ���ƶ�����,���������.cpp
 * @Description:
 * ��S0501�Ļ������޸ĳ�����ɸ��ƶ������������������ȡ�����������н������Ĺ��ܡ�
// ������1��Ϊ���룩��
// AB#CD##E##F#GH###
// DECBHGFA
// 4
// 8
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

// ���ƶ�����
void Copy(BiTree &original, BiTree &copy)
{
    if (original == NULL)
    {
        copy = NULL;
    }
    else
    {
        copy = new BiTNode;
        copy->data = original->data;
        Copy(original->lchild, copy->lchild);
        Copy(original->rchild, copy->rchild);
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

// ������������
int Depth(BiTree T)
{
    if (T == NULL)
    {
        return 0;
    }
    else
    {
        int leftDepth = Depth(T->lchild);
        int rightDepth = Depth(T->rchild);
        return max(leftDepth, rightDepth) + 1;
    }
}

// ����������н�����
int NodeCount(BiTree T)
{
    if (T == NULL)
    {
        return 0;
    }
    else
    {
        return NodeCount(T->lchild) + NodeCount(T->rchild) + 1;
    }
}

int main()
{
    BiTree T, S;
    CreateBiTree(T); // �������˳������������
    Copy(T, S);
    PostOrderTraverse(S);
    cout << endl;                 // �������
    cout << Depth(S) << endl;     // ������������
    cout << NodeCount(S) << endl; // ����������н�����

    return 0;
}