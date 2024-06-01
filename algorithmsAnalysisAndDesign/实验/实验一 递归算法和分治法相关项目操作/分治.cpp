/***
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2024-05-20 09:56:36
 * @FilePath: \c++\algorithmsAnalysisAndDesign\实验\实验一 递归算法和分治法相关项目操作\分治.cpp
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
#include <vector>
#include <algorithm>
using namespace std;

// 计算跨越中点的最大连续子序列和
int maxCrossingSum(vector<int> &nums, int left, int mid, int right)
{
    int leftSum = 0, maxLeftSum = 0;

    // 从中点向左计算最大连续子序列和
    for (int i = mid; i >= left; i--)
    {
        leftSum += nums[i];
        maxLeftSum = max(maxLeftSum, leftSum);
    }

    int rightSum = 0, maxRightSum = 0;

    // 从中点向右计算最大连续子序列和
    for (int i = mid + 1; i <= right; i++)
    {
        rightSum += nums[i];
        maxRightSum = max(maxRightSum, rightSum);
    }

    // 返回跨越中点的最大连续子序列和
    return maxLeftSum + maxRightSum;
}

// 递归函数，通过分治法计算最大连续子序列和
int maxSubArraySum(vector<int> &nums, int left, int right)
{
    // 只有一个元素时，最大子序列和是该元素值与0之间的最大值
    if (left == right)
        return max(0, nums[left]);

    // 计算中点
    int mid = left + (right - left) / 2;

    // 递归计算左半部分的最大连续子序列和
    int leftSum = maxSubArraySum(nums, left, mid);

    // 递归计算右半部分的最大连续子序列和
    int rightSum = maxSubArraySum(nums, mid + 1, right);

    // 计算跨越中点的最大连续子序列和
    int crossSum = maxCrossingSum(nums, left, mid, right);

    // 返回三个部分的最大值
    return max({leftSum, rightSum, crossSum});
}

// 主函数，计算数组的最大连续子序列和
int maxSubArray(vector<int> &nums)
{
    // 如果数组为空，返回0
    if (nums.empty())
        return 0;

    // 调用递归函数计算最大连续子序列和
    return maxSubArraySum(nums, 0, nums.size() - 1);
}

int main()
{
    // 示例1：
    vector<int> nums1 = {-2, 11, -4, 13, -5, -2};
    cout << "Maximum Subarray Sum: " << maxSubArray(nums1) << endl; // 应输出20

    // 示例2：
    vector<int> nums2 = {-6, 2, 4, -7, 5, 3, 2, -1, 6, -9, 10, -2};
    cout << "Maximum Subarray Sum: " << maxSubArray(nums2) << endl; // 应输出16

    return 0;
}
