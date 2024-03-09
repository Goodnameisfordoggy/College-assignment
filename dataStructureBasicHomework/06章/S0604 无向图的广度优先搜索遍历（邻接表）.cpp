/***
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2023-11-06 11:15:28
 * @FilePath: \c++\c++ BasicAlgorithmHomework\06��\S0604 ����ͼ�Ĺ�����������������ڽӱ�.cpp
 * @Description:
 * ��S0603�Ļ������޸ĳ���ʹ���ڽӱ��������ͼ�������������������
// ��1�����2��Ϊ�������
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
 * @				*		д��¥��д�ּ䣬д�ּ������Ա��
 * @				*		������Աд�������ó��򻻾�Ǯ��
 * @				*		����ֻ���������������������ߣ�
 * @				*		��������ո��գ����������긴�ꡣ
 * @				*		��Ը�������Լ䣬��Ը�Ϲ��ϰ�ǰ��
 * @				*		���۱������Ȥ���������г���Ա��
 * @				*		����Ц��߯��񲣬��Ц�Լ���̫����
 * @				*		��������Ư���ã��ĸ���ó���Ա��
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
    CreateUDG(G); // �����ڽӱ�������ͼ
    BFS(G, 0);    // �������������������ͼ
    cout << endl;
    for (int i = 0; i < G.vexnum; i++)
        visited[i] = 0;
    if (G.vexnum > 1)
        BFS(G, 1);
    cout << endl;
    return 0;
}