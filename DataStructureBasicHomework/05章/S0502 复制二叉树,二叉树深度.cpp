/***
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2023-10-30 12:25:13
 * @FilePath: \c++\c++ BasicAlgorithmHomework\05章\S0502 复制二叉树,二叉树深度.cpp
 * @Description:
 * 在S0501的基础上修改程序，完成复制二叉树、计算二叉树深度、计算二叉树中结点个数的功能。
// 例（第1行为输入）：
// AB#CD##E##F#GH###
// DECBHGFA
// 4
// 8
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

// 复制二叉树
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

// 计算二叉树深度
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

// 计算二叉树中结点个数
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
    CreateBiTree(T); // 先序遍历顺序建立二叉链表
    Copy(T, S);
    PostOrderTraverse(S);
    cout << endl;                 // 后序遍历
    cout << Depth(S) << endl;     // 计算二叉树深度
    cout << NodeCount(S) << endl; // 计算二叉树中结点个数

    return 0;
}