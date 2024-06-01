/*** 
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2024-05-27 09:10:39
 * @FilePath: \c++\algorithmsAnalysisAndDesign\实验\实验四 动态规划相关项目操作\动态规划.cpp
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
#include <string>
#include <algorithm>
using namespace std;

// 求解两个字符串的最长公共子序列
string longestCommonSubsequence(const string &A, const string &B)
{
    int m = A.size();
    int n = B.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0)); // 存储子问题的解

    // 填充 dp 数组
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            // 如果 A 的第 i-1 个字符和 B 的第 j-1 个字符相等
            if (A[i - 1] == B[j - 1])
            {
                // dp[i][j] 等于 dp[i-1][j-1] 加上1
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                // 否则，dp[i][j] 等于 dp[i-1][j] 和 dp[i][j-1] 中的较大值
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // 从 dp 数组构造 LCS 字符串
    string lcs;
    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        // 如果 A 的第 i-1 个字符和 B 的第 j-1 个字符相等
        if (A[i - 1] == B[j - 1])
        {
            // 将字符 A[i-1] 添加到 lcs 字符串中
            lcs.push_back(A[i - 1]);
            // 移动到左上角的单元格
            --i;
            --j;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            // 如果 dp[i-1][j] 大于 dp[i][j-1]，移动到上面的单元格
            --i;
        }
        else
        {
            // 否则，移动到左边的单元格
            --j;
        }
    }

    // 由于是从后往前添加字符，需要反转字符串
    reverse(lcs.begin(), lcs.end());
    return lcs;
}

int main()
{
    const string X = "abcbdb";
    const string Y = "acbbabdbb";
    string lcs = longestCommonSubsequence(X, Y);
    cout << "LCS=" << '"' << lcs << '"' << endl;
    return 0;
}
