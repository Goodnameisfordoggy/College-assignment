/***
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2024-05-20 10:15:47
 * @FilePath: \c++\algorithmsAnalysisAndDesign\ʵ��\ʵ��һ �ݹ��㷨�ͷ��η������Ŀ����\�ݹ�.cpp
 * @Description:
 * @
 * @				*		д��¥��д�ּ䣬д�ּ������Ա��
 * @				*		������Աд�������ó��򻻾�Ǯ��
 * @				*		����ֻ���������������������ߣ�
 * @				*		��������ո��գ����������긴�ꡣ
 * @				*		��Ը�������Լ䣬��Ը�Ϲ��ϰ�ǰ��
 * @				*		���۱������Ȥ���������г���Ա��
 * @				*		����Ц��߯��񲣬��Ц�Լ���̫����
 * @				*		��������Ư���ã��ĸ���ó���Ա��
 * @Copyright (c) 2024 by HDJ, All Rights Reserved.
 */
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// ����������ڵ�ṹ
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    // ���캯������ʼ���ڵ�ֵ�������ӽڵ�
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// ����������ͨ��������������еݹ鹹��������
TreeNode *buildTreeHelper(vector<int> &preorder, int preStart, int preEnd,
                          vector<int> &inorder, int inStart, int inEnd,
                          unordered_map<int, int> &inMap)
{
    // �������Խ�磬����NULL
    if (preStart > preEnd || inStart > inEnd)
        return NULL;

    // �������ڵ㣬��ֵΪ�������еĵ�һ��Ԫ��
    TreeNode *root = new TreeNode(preorder[preStart]);
    // �������������ҵ����ڵ��λ��
    int inRoot = inMap[root->val];
    // �����������ڵ������
    int numsLeft = inRoot - inStart;

    // �ݹ鹹��������
    root->left = buildTreeHelper(preorder, preStart + 1, preStart + numsLeft,
                                 inorder, inStart, inRoot - 1, inMap);
    // �ݹ鹹��������
    root->right = buildTreeHelper(preorder, preStart + numsLeft + 1, preEnd,
                                  inorder, inRoot + 1, inEnd, inMap);

    // ���ع��������ĸ��ڵ�
    return root;
}

// ��������ͨ��������������й���������
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    unordered_map<int, int> inMap;
    // �ù�ϣ��洢�������е�ֵ�����������ڿ��ٲ���
    for (size_t i = 0; i < inorder.size(); i++)
    {
        inMap[inorder[i]] = i;
    }
    // ���ø�����������������
    return buildTreeHelper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inMap);
}

// ���������ӡ������
void printInOrder(TreeNode *root)
{
    if (root == NULL)
        return;
    // �ݹ��ӡ������
    printInOrder(root->left);
    // ��ӡ���ڵ��ֵ
    cout << root->val << " ";
    // �ݹ��ӡ������
    printInOrder(root->right);
}

int main()
{
    // �������к���������
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    // ����������
    TreeNode *root = buildTree(preorder, inorder);
    // �����������ӡ������
    cout << "������ 228212118" << endl;
    cout << "�������ṹ��";
    printInOrder(root);
    return 0;
}
