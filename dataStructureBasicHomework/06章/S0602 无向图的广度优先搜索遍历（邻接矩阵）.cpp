/***
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2023-11-06 10:49:45
 * @FilePath: \c++\c++ BasicAlgorithmHomework\06章\S0602 无向图的广度优先搜索遍历（邻接矩阵）.cpp
 * @Description:
 * 在S0305与S0601的基础上修改程序，使用邻接矩阵完成无向图的广度优先搜索遍历。
// 例1（最后2行为输出，其他为输入）：
// 8 8
// ABCDEFGH
// AF 1
// BA 2
// BC 3
// CG 4
// BD 5
// BE 6
// GH 7
// DH 8
// ABFCDEGH
// BACDEFGH
// 例2（最后2行为输出）：
// 5 4
// BACDE
// AB 1
// BC 2
// BD 3
// DE 4
// BACDE
// ABCDE
// 例3（最后1行为输出）：
// 1 0
// A
// A
 * @
 * @				*		写字楼里写字间，写字间里程序员；
 * @				*		程序人员写程序，又拿程序换酒钱。
 * @				*		酒醒只在网上坐，酒醉还来网下眠；
 * @				*		酒醉酒醒日复日，网上网下年复年。
 * @				*		但愿老死电脑间，不愿鞠躬老板前；
 * @				*		奔驰宝马贵者趣，公交自行程序员。
 * @				*		别人笑我忒疯癫，我笑自己命太贱；
 * @				*		不见满街漂亮妹，哪个归得程序员？
 * @Copyright (c) ${2023} by ${HDJ}, All Rights Reserved.
 */
#include <iostream>
#include <queue>
using namespace std;

const int MAXV = 100; // 最大顶点数

typedef struct
{
    char vexs[MAXV];      // 顶点集合
    int arcs[MAXV][MAXV]; // 邻接矩阵
    int vexnum, arcnum;   // 顶点数和边数
} AMGraph;

int visited[MAXV]; // 访问标记数组

// 创建无向图的邻接矩阵
void CreateUDN(AMGraph &G)
{
    cin >> G.vexnum >> G.arcnum; // 输入顶点数和边数
    for (int i = 0; i < G.vexnum; i++)
    {
        cin >> G.vexs[i]; // 输入顶点集合
    }
    for (int i = 0; i < G.vexnum; i++)
    {
        for (int j = 0; j < G.vexnum; j++)
        {
            G.arcs[i][j] = 0; // 初始化邻接矩阵
        }
    }
    for (int k = 0; k < G.arcnum; k++)
    {
        char v1, v2;
        int w;
        cin >> v1 >> v2 >> w; // 输入边的顶点和权值
        int i = 0, j = 0;
        while (G.vexs[i] != v1)
            i++; // 查找顶点v1的位置
        while (G.vexs[j] != v2)
            j++;          // 查找顶点v2的位置
        G.arcs[i][j] = w; // 设置边的权值
        G.arcs[j][i] = w; // 因为是无向图，所以对称位置也要设置
    }
}

// 广度优先搜索遍历图
void BFS(AMGraph &G, int v)
{
    queue<int> Q;
    cout << G.vexs[v]; // 输出初始顶点
    visited[v] = 1;    // 标记顶点v为已访问
    Q.push(v);         // 将顶点v入队
    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop(); // 将顶点u出队
        for (int i = 0; i < G.vexnum; i++)
        {
            if (G.arcs[u][i] && !visited[i])
            {
                cout << G.vexs[i];
                visited[i] = 1;
                Q.push(i);
            }
        }
    }
}
int main()
{
    AMGraph G;
    CreateUDN(G); // 创建无向图的邻接矩阵
    BFS(G, 0);    // 广度优先搜索遍历图
    cout << endl;
    for (int i = 0; i < G.vexnum; i++)
        visited[i] = 0;
    if (G.vexnum > 1)
        BFS(G, 1);
    cout << endl;
    return 0;
}
