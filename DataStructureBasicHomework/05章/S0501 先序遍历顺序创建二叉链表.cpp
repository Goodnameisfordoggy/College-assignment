/***
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2023-10-30 12:11:31
 * @FilePath: \c++\c++ BasicAlgorithmHomework\05章\S0501 先序遍历顺序创建二叉链表.cpp
 * @Description:
 * 用先序遍历顺序创建二叉链表，并先序、中序、后序遍历二叉链表。
// 部分代码如图所示。
// 例1（第1 行为输入）：
// ABC##DE#G##F###
// ABCDEGF
// CBEGDFA
// CGEFDBA
 * @
 * @				*		写字楼里写字间，写字间里程序员；
 * @				*		程序人员写程序，又拿程序换酒钱。
 * @				*		酒醒只在网上坐，酒醉还来网下眠；
 * @				*		酒醉酒醒日复日，网上网下年复年。
 * @				*		但愿老死电脑间，不愿鞠躬老板前；
 * @				*		奔驰宝马贵者趣，公交自行程序员。
 * @				*		别人笑我忒疯癫，我笑自己命太贱；
 * @				*		不见满街漂亮妹，哪个归得程序员？
 * @Copyright (c) ${2023} by ${HDJ}, All Rights Reserved.
 */

#include <iostream>
using namespace std;

// 二叉树结点的定义
struct BiTNode
{
    char data;
    BiTNode *lchild; // 左子树
    BiTNode *rchild; // 右子树
};

// 二叉树的定义
typedef BiTNode *BiTree;

// 创建二叉链表
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

// 先序遍历二叉树
void PreOrderTraverse(BiTree T)
{
    if (T != NULL)
    {
        cout << T->data;
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}

// 中序遍历二叉树
void InOrderTraverse(BiTree T)
{
    if (T != NULL)
    {
        InOrderTraverse(T->lchild);
        cout << T->data;
        InOrderTraverse(T->rchild);
    }
}

// 后序遍历二叉树
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
    CreateBiTree(T); // 先序遍历顺序建立二叉链表

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