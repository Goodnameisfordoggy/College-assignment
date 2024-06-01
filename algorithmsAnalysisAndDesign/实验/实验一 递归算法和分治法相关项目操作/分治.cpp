/***
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2024-05-20 09:56:36
 * @FilePath: \c++\algorithmsAnalysisAndDesign\ʵ��\ʵ��һ �ݹ��㷨�ͷ��η������Ŀ����\����.cpp
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
#include <vector>
#include <algorithm>
using namespace std;

// �����Խ�е��������������к�
int maxCrossingSum(vector<int> &nums, int left, int mid, int right)
{
    int leftSum = 0, maxLeftSum = 0;

    // ���е��������������������к�
    for (int i = mid; i >= left; i--)
    {
        leftSum += nums[i];
        maxLeftSum = max(maxLeftSum, leftSum);
    }

    int rightSum = 0, maxRightSum = 0;

    // ���е����Ҽ���������������к�
    for (int i = mid + 1; i <= right; i++)
    {
        rightSum += nums[i];
        maxRightSum = max(maxRightSum, rightSum);
    }

    // ���ؿ�Խ�е��������������к�
    return maxLeftSum + maxRightSum;
}

// �ݹ麯����ͨ�����η�����������������к�
int maxSubArraySum(vector<int> &nums, int left, int right)
{
    // ֻ��һ��Ԫ��ʱ����������к��Ǹ�Ԫ��ֵ��0֮������ֵ
    if (left == right)
        return max(0, nums[left]);

    // �����е�
    int mid = left + (right - left) / 2;

    // �ݹ������벿�ֵ�������������к�
    int leftSum = maxSubArraySum(nums, left, mid);

    // �ݹ�����Ұ벿�ֵ�������������к�
    int rightSum = maxSubArraySum(nums, mid + 1, right);

    // �����Խ�е��������������к�
    int crossSum = maxCrossingSum(nums, left, mid, right);

    // �����������ֵ����ֵ
    return max({leftSum, rightSum, crossSum});
}

// �����������������������������к�
int maxSubArray(vector<int> &nums)
{
    // �������Ϊ�գ�����0
    if (nums.empty())
        return 0;

    // ���õݹ麯������������������к�
    return maxSubArraySum(nums, 0, nums.size() - 1);
}

int main()
{
    // ʾ��1��
    vector<int> nums1 = {-2, 11, -4, 13, -5, -2};
    cout << "Maximum Subarray Sum: " << maxSubArray(nums1) << endl; // Ӧ���20

    // ʾ��2��
    vector<int> nums2 = {-6, 2, 4, -7, 5, 3, 2, -1, 6, -9, 10, -2};
    cout << "Maximum Subarray Sum: " << maxSubArray(nums2) << endl; // Ӧ���16

    return 0;
}
