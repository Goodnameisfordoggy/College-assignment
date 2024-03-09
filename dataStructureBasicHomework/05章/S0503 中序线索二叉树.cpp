/***
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2023-10-30 12:32:50
 * @FilePath: \c++\c++ BasicAlgorithmHomework\05章\S0503 中序线索二叉树.cpp
 * @Description:
 * 在S0502的基础修改程序，中序线索化二叉树并遍历。
// 例（第1行为输入）：
// ABC##D##G##
// CBDAG
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

// 线索二叉树结点的定义
struct BiThrNode
{
    char data;
    BiThrNode *lchild; // 左子树
    BiThrNode *rchild; // 右子树
    int ltag;          // 左线索标志，0表示指向左子树，1表示指向前驱
    int rtag;          // 右线索标志，0表示指向右子树，1表示指向后继
};

// 线索二叉树的定义
typedef BiThrNode *BiThrTree;

// 中序线索二叉树全局变量
BiThrNode *pre; // 指向当前访问结点的前驱

// 创建二叉链表
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

// 中序线索化
void InThreading(BiThrTree &T)
{
    if (T != NULL)
    {
        InThreading(T->lchild); // 递归左子树线索化

        // 处理当前结点
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

        InThreading(T->rchild); // 递归右子树线索化
    }
}

// 遍历中序线索二叉树
void InOrderTraverse_Thr(BiThrTree T)
{
    BiThrNode *p = T;
    while (p != NULL)
    {
        // 找到中序遍历的起始结点
        while (p->ltag == 0)
        {
            p = p->lchild;
        }

        // 输出结点的数据
        cout << p->data;

        // 处理后继结点
        while (p->rtag == 1 && p->rchild != NULL)
        {
            p = p->rchild;
            cout << p->data;
        }

        // 移动到下一个结点
        p = p->rchild;
    }
}

int main()
{
    BiThrTree T;
    CreateBiThrTree(T);     // 先序遍历顺序建立二叉链表
    InThreading(T);         // 不带头结点的中序线索化
    InOrderTraverse_Thr(T); // 遍历中序线索二叉树

    return 0;
}