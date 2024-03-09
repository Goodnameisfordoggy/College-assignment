/***
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2023-11-27 11:03:24
 * @FilePath: \c++\c++ BasicAlgorithmHomework\07章\S0704 二叉排序树的查找 .cpp
 * @Description:
 * 创建二叉排序树，并进行关键值的查找。
例1（最后一行为输出）：
23 66 34 9 909 435 0
66
66 is in the Binary Sorting Tree.

例2（最后一行为输出）：
23 66 34 9 909 435 0
77
77 is not found!
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
    int key;
    struct BSTNode *left;
    struct BSTNode *right;
} *BSTree;

// 创建二叉排序树
void CreateBST(BSTree &T)
{
    T = NULL; // 初始化为空树
    int data;
    cin >> data;
    while (data != 0)
    {
        BSTNode *p = new BSTNode;
        p->key = data;
        p->left = NULL;
        p->right = NULL;

        if (T == NULL)
        {
            T = p; // 第一个节点作为根节点
        }
        else
        {
            BSTNode *current = T;
            BSTNode *parent = NULL;
            while (current != NULL)
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

// 在二叉排序树中进行查找
BSTNode *SearchBST(BSTree T, int key)
{
    BSTNode *current = T;
    while (current != NULL && current->key != key)
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

int main()
{
    BSTree T;
    CreateBST(T); // 创建二叉排序数，输入整数，以0表示结束
    int key;
    cin >> key;
    if (SearchBST(T, key) != NULL)
        cout << key << " is in the Binary Sorting Tree." << endl;
    else
        cout << key << " is not found!" << endl;
}
