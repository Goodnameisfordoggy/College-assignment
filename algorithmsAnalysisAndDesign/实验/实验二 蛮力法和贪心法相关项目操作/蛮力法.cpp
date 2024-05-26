/***
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2024-05-20 23:28:15
 * @FilePath: \c++\algorithmsAnalysisAndDesign\ʵ��\ʵ��� ��������̰�ķ������Ŀ����\������.cpp
 * @Description:
 * ����������������������
��������������n��n��1����������Ҫ�����n����ִ�У�ÿ������ֻ�ܷ����һ���ˣ�ÿ����ֻ��ִ��һ������
��i����ִ�е�j������ĳɱ���c[i][j]��1��i��j��n��������ܳɱ���С�ķ��䷽����
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
#include <vector>
#include <climits>

using namespace std;

// �������������ܳɱ�
int calculateTotalCost(const vector<vector<int>> &costMatrix, const vector<int> &permutation)
{
    int totalCost = 0;
    // ����ÿ�����񣬼����ܳɱ�
    for (size_t i = 0; i < permutation.size(); ++i)
    {
        totalCost += costMatrix[i][permutation[i]]; // ��i����ִ�е�permutation[i]������ĳɱ�
    }
    return totalCost;
}

// �������п��ܵ�����
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

// �����������ѷ��䷽��
pair<int, vector<int>> taskAssignmentBruteForce(const vector<vector<int>> &costMatrix)
{
    int n = costMatrix.size();
    vector<int> bestPermutation(n); // �洢��ѷ��䷽��������
    // ��ʼ����ѷ��䷽��Ϊ��ʼ����
    for (int i = 0; i < n; ++i)
    {
        bestPermutation[i] = i;
    }
    int minCost = INT_MAX; // ��С�ɱ���ʼ��Ϊһ���ϴ�ֵ

    // �������п��ܵ�����
    vector<int> currentPermutation(n);
    vector<int> visited(n, 0);
    vector<int> currentResult(n);
    vector<vector<int>> allPermutations;
    for (int i = 0; i < n; ++i)
    {
        currentPermutation[i] = i;
    }
    generatePermutations(currentPermutation, 0, visited, currentResult, allPermutations);

    // ������������
    for (const auto &permutation : allPermutations)
    {
        // ���㵱ǰ���е��ܳɱ�
        int totalCost = calculateTotalCost(costMatrix, permutation);
        // ������С�ɱ�����ѷ��䷽��
        if (totalCost < minCost)
        {
            minCost = totalCost;
            // ������ѷ��䷽��
            bestPermutation = permutation;
        }
    }

    return {minCost, bestPermutation}; // ������С�ɱ�����ѷ��䷽��
}

int main()
{
    // ����ɱ�����
    vector<vector<int>> costMatrix = {
        {9, 2, 7, 8},
        {6, 4, 3, 7},
        {5, 8, 1, 8},
        {7, 6, 9, 4}};

    // ��������������
    auto result = taskAssignmentBruteForce(costMatrix);

    // ������
    cout << "��С�ɱ�: " << result.first << endl;
    cout << "��ѷ��䷽��: ";
    for (int task : result.second)
    {
        cout << task + 1 << " "; // �����ѷ��䷽��
    }
    cout << endl;

    return 0;
}
