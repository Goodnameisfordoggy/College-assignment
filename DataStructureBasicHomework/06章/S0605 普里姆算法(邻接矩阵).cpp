#include <iostream>
using namespace std;
#define MAXINT 2147483647
#define MAX_VEX_NUM 100
typedef char VerTexType;
typedef int EdgeType;
typedef struct
{
    VerTexType vexs[MAX_VEX_NUM];
    EdgeType edges[MAX_VEX_NUM][MAX_VEX_NUM];
    int VexNum, EdgeNum;
} AMGraph;
struct
{
    VerTexType adjvex;
    EdgeType lowCost;
} CloseEdge[MAX_VEX_NUM];
int LocateVex(AMGraph G, VerTexType v)
{
    for (int i = 0; i < G.VexNum; i++)
    {
        if (G.vexs[i] == v)
            return i;
    }
    return -1;
}
void CreateUDN(AMGraph &G)
{
    VerTexType v1, v2;
    int i, j, k, weight;
    cin >> G.VexNum >> G.EdgeNum;
    for (i = 0; i < G.VexNum; i++)
    {
        cin >> G.vexs[i];
    }
    for (i = 0; i < G.VexNum; i++)
        for (j = 0; j < G.VexNum; j++)
            G.edges[i][j] = MAXINT;
    for (k = 0; k < G.EdgeNum; k++)
    {
        cin >> v1 >> v2 >> weight;
        i = LocateVex(G, v1);
        j = LocateVex(G, v2);
        G.edges[i][j] = weight;
        G.edges[j][i] = weight;
    }
}
int Min_closeEdge(int VexNum)
{
    int start = -1;
    for (int i = 0; i < VexNum; i++)
    {
        if (CloseEdge[i].lowCost != 0)
        {
            start = i;
            break;
        }
    }
    for (int j = 0; j < VexNum; j++)
    {
        if ((CloseEdge[start].lowCost > CloseEdge[j].lowCost) && CloseEdge[j].lowCost != 0)
            start = j;
    }
    return start;
}
void MiniSpanTree_Prim(AMGraph &G, VerTexType v)
{
    int i, j, k;
    VerTexType u0, v0;
    k = LocateVex(G, v);
    CloseEdge[k].adjvex = v;
    CloseEdge[k].lowCost = 0;
    for (i = 0; i < G.VexNum; i++)
    {
        if (i != k)
            CloseEdge[i] = {v, G.edges[k][i]};
    }
    for (j = 1; j < G.VexNum; j++)
    {
        k = Min_closeEdge(G.VexNum);
        CloseEdge[k].lowCost = 0;
        u0 = CloseEdge[k].adjvex;
        v0 = G.vexs[k];
        cout << u0 << v0 << " ";
        for (i = 0; i < G.VexNum; i++)
        {
            if (G.edges[k][i] < CloseEdge[i].lowCost)
            {
                CloseEdge[i] = {G.vexs[k],
                                G.edges[k][i]};
            }
        }
    }
}

int main()
{
    AMGraph G;
    CreateUDN(G);                    // 创建无向图的邻接矩阵(至少两个顶点)
    MiniSpanTree_Prim(G, G.vexs[0]); // 普里姆算法
    cout << endl;
    MiniSpanTree_Prim(G, G.vexs[1]);
    return 0;
}