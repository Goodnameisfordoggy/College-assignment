/*** 
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2024-05-27 09:02:51
 * @FilePath: \c++\algorithmsAnalysisAndDesign\实验\实验三 回溯法相关项目操作\回溯法.cpp
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
using namespace std;

const int N = 4; // 棋盘的大小
vector<int> solution(N); // solution数组存储每行皇后所在的列位置
vector<bool> column(N, false); // column数组标记每列是否有皇后
// 标记两个方向的对角线是否有皇后
vector<bool> diag1(2 * N - 1, false);
vector<bool> diag2(2 * N - 1, false);

// 打印当前解
void printSolution()
{
    cout << endl;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            // 如果皇后在第i行第j列，打印Q，否则打印.
            if (solution[i] == j)
                cout << "Q ";
            else
                cout << ". ";
        }
        cout << endl;
    }
    cout << endl;
    cout << "q[1.." << N << "]=";
    for (size_t i = 0; i < solution.size();i++)
    {
        cout << solution[i] << ' ';
    }
    cout << ']'<< endl;
}

// 回溯法求解函数，从第row行开始尝试放置皇后
void solve(int row)
{
    // 如果已经成功放置了N个皇后，打印解
    if (row == N)
    {
        printSolution();
        return;
    }
    // 尝试在当前行的每一列放置皇后
    for (int col = 0; col < N; ++col)
    {
        // 如果当前列或对角线已经有皇后，跳过
        if (column[col] || diag1[row - col + N - 1] || diag2[row + col])
            continue;
        // 在solution数组中记录当前行皇后的列位置
        solution[row] = col;
        // 标记当前列和对角线已被占用
        column[col] = diag1[row - col + N - 1] = diag2[row + col] = true;
        // 递归调用，尝试放置下一行的皇后
        solve(row + 1);
        // 回溯，取消当前列和对角线的标记
        column[col] = diag1[row - col + N - 1] = diag2[row + col] = false;
    }
}

int main()
{
    solve(0);
    return 0;
}
