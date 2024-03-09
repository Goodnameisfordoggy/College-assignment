/***
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2023-11-27 11:03:24
 * @FilePath: \c++\c++ BasicAlgorithmHomework\07��\S0704 �����������Ĳ��� .cpp
 * @Description:
 * ���������������������йؼ�ֵ�Ĳ��ҡ�
��1�����һ��Ϊ�������
23 66 34 9 909 435 0
66
66 is in the Binary Sorting Tree.

��2�����һ��Ϊ�������
23 66 34 9 909 435 0
77
77 is not found!
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

// ��������������Ľڵ�ṹ
typedef struct BSTNode
{
    int key;
    struct BSTNode *left;
    struct BSTNode *right;
} *BSTree;

// ��������������
void CreateBST(BSTree &T)
{
    T = NULL; // ��ʼ��Ϊ����
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
            T = p; // ��һ���ڵ���Ϊ���ڵ�
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

// �ڶ����������н��в���
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
    CreateBST(T); // ����������������������������0��ʾ����
    int key;
    cin >> key;
    if (SearchBST(T, key) != NULL)
        cout << key << " is in the Binary Sorting Tree." << endl;
    else
        cout << key << " is not found!" << endl;
}
