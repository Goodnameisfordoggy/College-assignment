/***
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2024-05-20 10:15:47
 * @FilePath: \c++\algorithmsAnalysisAndDesign\实验\实验一 递归算法和分治法相关项目操作\递归.cpp
 * @Description:
 * @
 * @				*		写字楼里写字间，写字间里程序员；
 * @				*		程序人员写程序，又拿程序换酒钱。
 * @				*		酒醒只在网上坐，酒醉还来网下眠；
 * @				*		酒醉酒醒日复日，网上网下年复年。
 * @				*		但愿老死电脑间，不愿鞠躬老板前；
 * @				*		奔驰宝马贵者趣，公交自行程序员。
 * @				*		别人笑我忒疯癫，我笑自己命太贱；
 * @				*		不见满街漂亮妹，哪个归得程序员？
 * @Copyright (c) 2024 by HDJ, All Rights Reserved.
 */
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// 定义二叉树节点结构
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    // 构造函数，初始化节点值和左右子节点
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 辅助函数，通过先序和中序序列递归构建二叉树
TreeNode *buildTreeHelper(vector<int> &preorder, int preStart, int preEnd,
                          vector<int> &inorder, int inStart, int inEnd,
                          unordered_map<int, int> &inMap)
{
    // 如果索引越界，返回NULL
    if (preStart > preEnd || inStart > inEnd)
        return NULL;

    // 创建根节点，其值为先序序列的第一个元素
    TreeNode *root = new TreeNode(preorder[preStart]);
    // 在中序序列中找到根节点的位置
    int inRoot = inMap[root->val];
    // 计算左子树节点的数量
    int numsLeft = inRoot - inStart;

    // 递归构建左子树
    root->left = buildTreeHelper(preorder, preStart + 1, preStart + numsLeft,
                                 inorder, inStart, inRoot - 1, inMap);
    // 递归构建右子树
    root->right = buildTreeHelper(preorder, preStart + numsLeft + 1, preEnd,
                                  inorder, inRoot + 1, inEnd, inMap);

    // 返回构建的树的根节点
    return root;
}

// 主函数，通过先序和中序序列构建二叉树
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    unordered_map<int, int> inMap;
    // 用哈希表存储中序序列的值和索引，便于快速查找
    for (size_t i = 0; i < inorder.size(); i++)
    {
        inMap[inorder[i]] = i;
    }
    // 调用辅助函数构建二叉树
    return buildTreeHelper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inMap);
}

// 中序遍历打印二叉树
void printInOrder(TreeNode *root)
{
    if (root == NULL)
        return;
    // 递归打印左子树
    printInOrder(root->left);
    // 打印根节点的值
    cout << root->val << " ";
    // 递归打印右子树
    printInOrder(root->right);
}

int main()
{
    // 先序序列和中序序列
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    // 构建二叉树
    TreeNode *root = buildTree(preorder, inorder);
    // 中序遍历并打印二叉树
    cout << "霍东君 228212118" << endl;
    cout << "二叉链结构：";
    printInOrder(root);
    return 0;
}
