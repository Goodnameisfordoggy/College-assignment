/***
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2024-05-20 23:28:15
 * @FilePath: \c++\algorithmsAnalysisAndDesign\实验\实验二 蛮力法和贪心法相关项目操作\蛮力法.cpp
 * @Description:
 * 蛮力法：求解任务分配问题
【问题描述】有n（n≥1）个任务需要分配给n个人执行，每个任务只能分配给一个人，每个人只能执行一个任务。
第i个人执行第j个任务的成本是c[i][j]（1≤i，j≤n）。求出总成本最小的分配方案。
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
#include <vector>
#include <climits>

using namespace std;

// 计算任务分配的总成本
int calculateTotalCost(const vector<vector<int>> &costMatrix, const vector<int> &permutation)
{
    int totalCost = 0;
    // 遍历每个任务，计算总成本
    for (size_t i = 0; i < permutation.size(); ++i)
    {
        totalCost += costMatrix[i][permutation[i]]; // 第i个人执行第permutation[i]个任务的成本
    }
    return totalCost;
}

// 生成所有可能的排列
void generatePermutations(const vector<int> &currentPermutation, size_t index, vector<int> &visited, vector<int> &currentResult, vector<vector<int>> &allPermutations)
{
    if (index == currentPermutation.size())
    {
        allPermutations.push_back(currentResult);
        return;
    }

    for (size_t i = 0; i < currentPermutation.size(); ++i)
    {
        if (!visited[i])
        {
            visited[i] = 1;
            currentResult[index] = currentPermutation[i];
            generatePermutations(currentPermutation, index + 1, visited, currentResult, allPermutations);
            visited[i] = 0;
        }
    }
}

// 蛮力法求解最佳分配方案
pair<int, vector<int>> taskAssignmentBruteForce(const vector<vector<int>> &costMatrix)
{
    int n = costMatrix.size();
    vector<int> bestPermutation(n); // 存储最佳分配方案的排列
    // 初始化最佳分配方案为初始排列
    for (int i = 0; i < n; ++i)
    {
        bestPermutation[i] = i;
    }
    int minCost = INT_MAX; // 最小成本初始化为一个较大值

    // 生成所有可能的排列
    vector<int> currentPermutation(n);
    vector<int> visited(n, 0);
    vector<int> currentResult(n);
    vector<vector<int>> allPermutations;
    for (int i = 0; i < n; ++i)
    {
        currentPermutation[i] = i;
    }
    generatePermutations(currentPermutation, 0, visited, currentResult, allPermutations);

    // 遍历所有排列
    for (const auto &permutation : allPermutations)
    {
        // 计算当前排列的总成本
        int totalCost = calculateTotalCost(costMatrix, permutation);
        // 更新最小成本及最佳分配方案
        if (totalCost < minCost)
        {
            minCost = totalCost;
            // 更新最佳分配方案
            bestPermutation = permutation;
        }
    }

    return {minCost, bestPermutation}; // 返回最小成本和最佳分配方案
}

int main()
{
    // 定义成本矩阵
    vector<vector<int>> costMatrix = {
        {9, 2, 7, 8},
        {6, 4, 3, 7},
        {5, 8, 1, 8},
        {7, 6, 9, 4}};

    // 求解任务分配问题
    auto result = taskAssignmentBruteForce(costMatrix);

    // 输出结果
    cout << "最小成本: " << result.first << endl;
    cout << "最佳分配方案: ";
    for (int task : result.second)
    {
        cout << task + 1 << " "; // 输出最佳分配方案
    }
    cout << endl;

    return 0;
}
