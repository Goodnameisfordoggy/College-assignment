/*
给定一个有向图，利用迪杰斯特拉算法求某一顶点到其他顶点的最短路径。
例（最后6行为输出，其中-1表示其前面两个顶点之间没有路径）：
6 8
ABCDEF
AC 10
AF 100
AE 30
BC 5
CD 50
DF 10
ED 20
EF 60
AA:0
AB:-1
AC:10
AD:50
AE:30
AF:60
*/
#include <iostream>
using namespace std;
#define MAXINT 2147483647
#define MAX_VEX_NUM 100
typedef char VerTexType;
typedef int EdgeType;
bool S[MAX_VEX_NUM];
int Path[MAX_VEX_NUM];
int D[MAX_VEX_NUM];
typedef struct
{
    VerTexType vexs[MAX_VEX_NUM];
    EdgeType edges[MAX_VEX_NUM][MAX_VEX_NUM];
    int VexNum, EdgeNum;
} AMGraph;
int LocateVex(AMGraph G, VerTexType v)
{
    for (int i = 0; i < G.VexNum; i++)
    {
        if (G.vexs[i] == v)
            return i;
    }
    return -1;
}
void CreateUDN(AMGraph &G, int VexNum, int ArcNum)
{
    VerTexType v1, v2;
    int i, j, k, weight;
    G.VexNum = VexNum;
    G.EdgeNum = ArcNum;
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
    }
}
void ArrayStatus(AMGraph G)
{
    for (int i = 0; i < G.VexNum; i++)
    {
        cout << S[i] << "     ";
    }
    cout << endl;
    for (int i = 0; i < G.VexNum; i++)
    {
        cout << D[i] << "     ";
    }
    cout << endl
         << endl;
}
void ShortestPath_DIJ(AMGraph G, int v0)
{
    for (int i = 0; i < G.VexNum; i++)
    {
        S[i] = false;
        D[i] = G.edges[v0][i];
        if (D[i] < MAXINT)
            Path[i] = v0;
        else
            Path[i] = -1;
    }
    S[v0] = true;
    D[v0] = 0;
    Path[v0] = 0;
    for (int i = 1; i < G.VexNum; i++)
    {
        int minWight = MAXINT;
        int minVex = 0;
        for (int j = 0; j < G.VexNum; j++)
        {
            if (!S[j] && D[j] < minWight)
            {
                minVex = j;
                minWight = D[j];
            }
        }
        S[minVex] = true;
        for (int k = 0; k < G.VexNum; k++)
        {
            if (!S[k] && D[k] > (D[minVex] + G.edges[minVex][k]) && ((D[minVex] + G.edges[minVex][k]) > 0))
            {
                D[k] = D[minVex] + G.edges[minVex][k];
                Path[k] = minVex;
            }
        }
    }
    for (int i = 0; i < G.VexNum; i++)
    {
        if (D[i] == MAXINT)
            cout << G.vexs[v0] << G.vexs[i] << ':' << -1 << endl;
        else
            cout << G.vexs[v0] << G.vexs[i] << ':' << D[i] << endl;
    }
}

int main()
{
    int vnum, anum; // 顶点数与边数
    cin >> vnum >> anum;
    AMGraph G;
    CreateUDN(G, vnum, anum); // 创建无向图的邻接矩阵(至少两个顶点)
    ShortestPath_DIJ(G, 0);
    return 0;
}