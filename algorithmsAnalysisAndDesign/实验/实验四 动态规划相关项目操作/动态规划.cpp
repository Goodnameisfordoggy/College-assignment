/*** 
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2024-05-27 09:10:39
 * @FilePath: \c++\algorithmsAnalysisAndDesign\ʵ��\ʵ���� ��̬�滮�����Ŀ����\��̬�滮.cpp
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
#include <string>
#include <algorithm>
using namespace std;

// ��������ַ����������������
string longestCommonSubsequence(const string &A, const string &B)
{
    int m = A.size();
    int n = B.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0)); // �洢������Ľ�

    // ��� dp ����
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            // ��� A �ĵ� i-1 ���ַ��� B �ĵ� j-1 ���ַ����
            if (A[i - 1] == B[j - 1])
            {
                // dp[i][j] ���� dp[i-1][j-1] ����1
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                // ����dp[i][j] ���� dp[i-1][j] �� dp[i][j-1] �еĽϴ�ֵ
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // �� dp ���鹹�� LCS �ַ���
    string lcs;
    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        // ��� A �ĵ� i-1 ���ַ��� B �ĵ� j-1 ���ַ����
        if (A[i - 1] == B[j - 1])
        {
            // ���ַ� A[i-1] ��ӵ� lcs �ַ�����
            lcs.push_back(A[i - 1]);
            // �ƶ������Ͻǵĵ�Ԫ��
            --i;
            --j;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            // ��� dp[i-1][j] ���� dp[i][j-1]���ƶ�������ĵ�Ԫ��
            --i;
        }
        else
        {
            // �����ƶ�����ߵĵ�Ԫ��
            --j;
        }
    }

    // �����ǴӺ���ǰ����ַ�����Ҫ��ת�ַ���
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
