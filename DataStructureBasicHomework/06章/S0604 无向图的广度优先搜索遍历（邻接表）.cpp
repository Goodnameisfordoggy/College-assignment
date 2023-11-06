/***
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2023-11-06 11:15:28
 * @FilePath: \c++\c++ BasicAlgorithmHomework\06章\S0604 无向图的广度优先搜索遍历（邻接表）.cpp
 * @Description:
 * 在S0603的基础上修改程序，使用邻接表完成无向图的深度优先搜索遍历。
// 例1（最后2行为输出）：
// 5 5
// ABCDE
// AB
// AD
// BC
// CE
// ED
// ADBEC
// BCAED
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

#define MAX_VERTEX_NUM 100

typedef struct ArcNode
{
    int adjvex;
    struct ArcNode *nextarc;
} ArcNode;

typedef struct VNode
{
    char data;
    ArcNode *firstarc;
} VNode, AdjList[MAX_VERTEX_NUM];

typedef struct
{
    AdjList vertices;
    int vexnum, arcnum;
} ALGraph;

void CreateUDG(ALGraph &G)
{
    cin >> G.vexnum >> G.arcnum;
    for (int i = 0; i < G.vexnum; i++)
    {
        cin >> G.vertices[i].data;
        G.vertices[i].firstarc = NULL;
    }
    for (int k = 0; k < G.arcnum; k++)
    {
        char v1, v2;
        cin >> v1 >> v2;
        int i, j;
        for (i = 0; i < G.vexnum; i++)
        {
            if (G.vertices[i].data == v1)
                break;
        }
        for (j = 0; j < G.vexnum; j++)
        {
            if (G.vertices[j].data == v2)
                break;
        }
        ArcNode *p = new ArcNode;
        p->adjvex = j;
        p->nextarc = G.vertices[i].firstarc;
        G.vertices[i].firstarc = p;

        ArcNode *q = new ArcNode;
        q->adjvex = i;
        q->nextarc = G.vertices[j].firstarc;
        G.vertices[j].firstarc = q;
    }
}

int visited[MAX_VERTEX_NUM];

void BFS(ALGraph G, int v0)
{
    queue<int> q;
    q.push(v0);
    visited[v0] = 1;

    while (!q.empty())
    {
        int v = q.front();
        q.pop();

        cout << G.vertices[v].data;

        ArcNode *p = G.vertices[v].firstarc;

        while (p)
        {
            int w = p->adjvex;
            if (!visited[w])
            {
                q.push(w);
                visited[w] = 1;
            }
            p = p->nextarc;
        }
    }
}

int main()
{
    ALGraph G;
    CreateUDG(G); // 采用邻接表创建无向图
    BFS(G, 0);    // 广度优先搜索遍历无向图
    cout << endl;
    for (int i = 0; i < G.vexnum; i++)
        visited[i] = 0;
    if (G.vexnum > 1)
        BFS(G, 1);
    cout << endl;
    return 0;
}