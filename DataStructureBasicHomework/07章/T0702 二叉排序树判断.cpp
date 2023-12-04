/***
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2023-12-04 12:07:47
 * @FilePath: \c++\c++ BasicAlgorithmHomework\07章\T0702 二叉排序树判断.cpp
 * @Description:
 * 在S0501的基础上修改程序，试写一个判别给定二叉树是否为二叉排序树的算法。
注：输入时0表示没有结点；输出每个结点上的整数时，占5个字符位置。

例1（第1行为输入）：
50 30 60 0 0 0 20 0 0
   50   30   60   20
   60   30   50   20
   60   30   20   50
No
 例2（第1行为输入）：
50 30 22 0 0 31 0 0 66 0 0
   50   30   22   31   66
   22   30   31   50   66
   22   31   30   66   50
Yes
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
#include <climits>
using namespace std;

typedef struct BiTNode
{
    int data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

// 创建二叉树
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
// 前序遍历
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

// 中序遍历
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

// 后序遍历
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

// 中序遍历，检查节点值是否按升序排列
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
    CreateBiTree(T); // 先序遍历顺序建立二叉链表
    PreOrderTraverse(T);
    cout << endl; // 先序遍历
    InOrderTraverse(T);
    cout << endl; // 中序遍历
    PostOrderTraverse(T);
    cout << endl; // 后序遍历
    int flag = 1;
    JudgeBST(T, flag);
    if (flag)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}