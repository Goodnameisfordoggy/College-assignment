/***
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2023-10-30 12:32:50
 * @FilePath: \c++\c++ BasicAlgorithmHomework\05��\S0503 ��������������.cpp
 * @Description:
 * ��S0502�Ļ����޸ĳ���������������������������
// ������1��Ϊ���룩��
// ABC##D##G##
// CBDAG
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

// �������������Ķ���
struct BiThrNode
{
    char data;
    BiThrNode *lchild; // ������
    BiThrNode *rchild; // ������
    int ltag;          // ��������־��0��ʾָ����������1��ʾָ��ǰ��
    int rtag;          // ��������־��0��ʾָ����������1��ʾָ����
};

// �����������Ķ���
typedef BiThrNode *BiThrTree;

// ��������������ȫ�ֱ���
BiThrNode *pre; // ָ��ǰ���ʽ���ǰ��

// ������������
void CreateBiThrTree(BiThrTree &T)
{
    char ch;
    cin >> ch;
    if (ch == '#')
    {
        T = NULL;
    }

    else
    {
        T = new BiThrNode;
        T->data = ch;
        T->ltag = 0;
        T->rtag = 0;
        CreateBiThrTree(T->lchild);
        CreateBiThrTree(T->rchild);
    }
}

// ����������
void InThreading(BiThrTree &T)
{
    if (T != NULL)
    {
        InThreading(T->lchild); // �ݹ�������������

        // ����ǰ���
        if (T->lchild == NULL)
        {
            T->ltag = 1;
            T->lchild = pre;
        }
        if (pre != NULL && pre->rchild == NULL)
        {
            pre->rtag = 1;
            pre->rchild = T;
        }
        pre = T;

        InThreading(T->rchild); // �ݹ�������������
    }
}

// ������������������
void InOrderTraverse_Thr(BiThrTree T)
{
    BiThrNode *p = T;
    while (p != NULL)
    {
        // �ҵ������������ʼ���
        while (p->ltag == 0)
        {
            p = p->lchild;
        }

        // �����������
        cout << p->data;

        // �����̽��
        while (p->rtag == 1 && p->rchild != NULL)
        {
            p = p->rchild;
            cout << p->data;
        }

        // �ƶ�����һ�����
        p = p->rchild;
    }
}

int main()
{
    BiThrTree T;
    CreateBiThrTree(T);     // �������˳������������
    InThreading(T);         // ����ͷ��������������
    InOrderTraverse_Thr(T); // ������������������

    return 0;
}