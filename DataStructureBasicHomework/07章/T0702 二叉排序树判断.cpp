/***
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2023-12-04 12:07:47
 * @FilePath: \c++\c++ BasicAlgorithmHomework\07��\T0702 �����������ж�.cpp
 * @Description:
 * ��S0501�Ļ������޸ĳ�����дһ���б�����������Ƿ�Ϊ�������������㷨��
ע������ʱ0��ʾû�н�㣻���ÿ������ϵ�����ʱ��ռ5���ַ�λ�á�

��1����1��Ϊ���룩��
50 30 60 0 0 0 20 0 0
   50   30   60   20
   60   30   50   20
   60   30   20   50
No
 ��2����1��Ϊ���룩��
50 30 22 0 0 31 0 0 66 0 0
   50   30   22   31   66
   22   30   31   50   66
   22   31   30   66   50
Yes
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
#include <climits>
using namespace std;

typedef struct BiTNode
{
    int data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

// ����������
void CreateBiTree(BiTree &T)
{
    int data;
    cin >> data;
    if (data == 0)
    {
        T = NULL;
    }
    else
    {
        T = new BiTNode;
        T->data = data;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
}
// ǰ�����
void PreOrderTraverse(BiTree T)
{
    if (T)
    {
        cout.width(5);
        cout << T->data;
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}

// �������
void InOrderTraverse(BiTree T)
{
    if (T)
    {
        InOrderTraverse(T->lchild);
        cout.width(5);
        cout << T->data;
        InOrderTraverse(T->rchild);
    }
}

// �������
void PostOrderTraverse(BiTree T)
{
    if (T)
    {
        PostOrderTraverse(T->lchild);
        PostOrderTraverse(T->rchild);
        cout.width(5);
        cout << T->data;
    }
}

// ������������ڵ�ֵ�Ƿ���������
bool InOrderCheck(BiTree T, int &prev)
{
    if (T == NULL)
    {
        return true;
    }

    if (!InOrderCheck(T->lchild, prev))
    {
        return false;
    }

    if (T->data <= prev)
    {
        return false;
    }

    prev = T->data;

    return InOrderCheck(T->rchild, prev);
}

bool JudgeBST(BiTree T, int &flag)
{
    int prev = INT_MIN;
    flag = InOrderCheck(T, prev);
    return flag;
}

int main()
{
    BiTree T;
    CreateBiTree(T); // �������˳������������
    PreOrderTraverse(T);
    cout << endl; // �������
    InOrderTraverse(T);
    cout << endl; // �������
    PostOrderTraverse(T);
    cout << endl; // �������
    int flag = 1;
    JudgeBST(T, flag);
    if (flag)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}