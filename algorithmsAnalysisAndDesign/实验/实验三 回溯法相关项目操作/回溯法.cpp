/*** 
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2024-05-27 09:02:51
 * @FilePath: \c++\algorithmsAnalysisAndDesign\ʵ��\ʵ���� ���ݷ������Ŀ����\���ݷ�.cpp
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
using namespace std;

const int N = 4; // ���̵Ĵ�С
vector<int> solution(N); // solution����洢ÿ�лʺ����ڵ���λ��
vector<bool> column(N, false); // column������ÿ���Ƿ��лʺ�
// �����������ĶԽ����Ƿ��лʺ�
vector<bool> diag1(2 * N - 1, false);
vector<bool> diag2(2 * N - 1, false);

// ��ӡ��ǰ��
void printSolution()
{
    cout << endl;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            // ����ʺ��ڵ�i�е�j�У���ӡQ�������ӡ.
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

// ���ݷ���⺯�����ӵ�row�п�ʼ���Է��ûʺ�
void solve(int row)
{
    // ����Ѿ��ɹ�������N���ʺ󣬴�ӡ��
    if (row == N)
    {
        printSolution();
        return;
    }
    // �����ڵ�ǰ�е�ÿһ�з��ûʺ�
    for (int col = 0; col < N; ++col)
    {
        // �����ǰ�л�Խ����Ѿ��лʺ�����
        if (column[col] || diag1[row - col + N - 1] || diag2[row + col])
            continue;
        // ��solution�����м�¼��ǰ�лʺ����λ��
        solution[row] = col;
        // ��ǵ�ǰ�кͶԽ����ѱ�ռ��
        column[col] = diag1[row - col + N - 1] = diag2[row + col] = true;
        // �ݹ���ã����Է�����һ�еĻʺ�
        solve(row + 1);
        // ���ݣ�ȡ����ǰ�кͶԽ��ߵı��
        column[col] = diag1[row - col + N - 1] = diag2[row + col] = false;
    }
}

int main()
{
    solve(0);
    return 0;
}
