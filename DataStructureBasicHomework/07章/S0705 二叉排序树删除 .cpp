/***
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2023-11-27 11:08:49
 * @FilePath: \c++\c++ BasicAlgorithmHomework\07章\S0705 二叉排序树删除 .cpp
 * @Description:
 * 练习书上算法7.7，完成二叉排序树中结点的删除。
例1（第1、4行为输入）：
HEBEI#
BEHI
HEBI
E
BHI
HBI

例2（第1、4行为输入）：
HEBEI#
BEHI
HEBI
E
BHI
HBI

例3（第1、4行为输入）：
HEBEI#
BEHI
HEBI
I
BEH
HEB
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

// 定义二叉排序树的节点结构
typedef struct BSTNode
{
    char key;
    struct BSTNode *left;
    struct BSTNode *right;
} *BSTree;

// 创建二叉排序树
void CreateBST(BSTree &T)
{
    T = nullptr; // 初始化为空树
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
            T = p; // 第一个节点作为根节点
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

// 中序遍历二叉排序树
void InOrderTraverse(BSTree T)
{
    if (T != nullptr)
    {
        InOrderTraverse(T->left);
        cout << T->key;
        InOrderTraverse(T->right);
    }
}

// 先序遍历二叉排序树
void PreOrderTraverse(BSTree T)
{
    if (T != nullptr)
    {
        cout << T->key;
        PreOrderTraverse(T->left);
        PreOrderTraverse(T->right);
    }
}

// 查找二叉排序树中指定节点
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

// 删除二叉排序树中指定节点
bool DeleteBST(BSTree &T, char key)
{
    if (T == nullptr)
    {
        return false; // 树为空，无法删除
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
            BSTNode *prev = T; // 用于记录替代节点的父节点
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
        return false; // 没有找到要删除的节点
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
        BSTNode *prev = current; // 用于记录替代节点的父节点
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
    CreateBST(T); // 创建二叉排序数，输入字符，以#表示结束
    InOrderTraverse(T);
    cout << endl; // 中序遍历
    PreOrderTraverse(T);
    cout << endl; // 先序遍历

    char key;
    cin >> key;
    DeleteBST(T, key); // 删除关键值为key的结点
    InOrderTraverse(T);
    cout << endl; // 中序遍历
    PreOrderTraverse(T);
    cout << endl; // 先序遍历

    return 0;
}
