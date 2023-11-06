/***
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2023-11-06 10:44:01
 * @FilePath: \c++\c++ BasicAlgorithmHomework\06章\S0601 无向图的深度优先搜索遍历（邻接矩阵）.cpp
 * @Description:
 * 采用邻接矩阵表示无向图的深度优先搜索遍历。
// 例1（最后1行为输出，其他为输入）：
// 1 0
// A
// A

// 例2（最后2行为输出，其他为输入）：
// 4 4
// ABCD
// AB 1
// AC 2
// AD 3
// CD 5
// ABCD
// BACD
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
#include <cstring>
using namespace std;

const int MAXV = 100; // 最大顶点数

typedef struct
{
    char vexs[MAXV];      // 顶点集合
    int arcs[MAXV][MAXV]; // 邻接矩阵，用来表示边的关系
    int vexnum, arcnum;   // 顶点数和边数
} AMGraph;

int visited[MAXV]; // 标记顶点是否被访问

// 创建无向图的邻接矩阵
void CreateUDN(AMGraph &G)
{
    cin >> G.vexnum >> G.arcnum;

    for (int i = 0; i < G.vexnum; i++)
        cin >> G.vexs[i];

    memset(G.arcs, 0, sizeof(G.arcs)); // 初始化邻接矩阵

    for (int i = 0; i < G.arcnum; i++)
    {
        char v1, v2;
        int weight;
        cin >> v1 >> v2 >> weight;

        int index1, index2;
        for (int j = 0; j < G.vexnum; j++)
        {
            if (G.vexs[j] == v1)
                index1 = j;
            if (G.vexs[j] == v2)
                index2 = j;
        }

        G.arcs[index1][index2] = weight;
        G.arcs[index2][index1] = weight; // 无向图，所以要对称
    }
}

// 深度优先搜索遍历图
void DFS_AM(AMGraph &G, int v)
{
    cout << G.vexs[v]; // 输出当前顶点

    visited[v] = 1; // 标记当前顶点为已访问

    for (int i = 0; i < G.vexnum; i++)
    {
        if (G.arcs[v][i] != 0 && !visited[i]) // 有边且未访问
        {
            DFS_AM(G, i); // 递归访问相邻顶点
        }
    }
}

int main()
{
    AMGraph G;
    CreateUDN(G); // 创建无向图的邻接矩阵
    DFS_AM(G, 0); // 深度优先搜索遍历图
    cout << endl;
    for (int i = 0; i < G.vexnum; i++)
        visited[i] = 0;
    if (G.vexnum > 1)
        DFS_AM(G, 1);
    cout << endl;
    return 0;
}