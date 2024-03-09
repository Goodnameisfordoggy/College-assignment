/*
在S0610的基础上修改程序。
在AOE-网中，求解其关键路径。
例（最后一行为输出）：
9 11
ABCDEFGHI
AB 6
AC 4
AD 5
BE 1
CE 1
DF 2
EG 9
EH 7
FH 4
GI 2
HI 4
AB BE EH EG GI HI 
*/
#include <iostream>
#include <deque>
using namespace std;
#define MaxVexNum 20
#define MaxArcNum 400
#define OK 1
#define ERROR -1
typedef int Status;
typedef int OtherInfo;
typedef char VertexType;
typedef struct ArcNode
{
    int adjVex;
    OtherInfo info;
    ArcNode *nextArc;
} ArcNode;
typedef struct
{
    VertexType data;
    ArcNode *firstArc;
} VNode, AdjList[MaxVexNum];
typedef struct
{
    AdjList vertices;
    int vexnum, arcNum;
} ALGraph;
Status LocateVex(ALGraph G, char v)
{
    for (int i = 0; i < G.vexnum; i++)
    {
        if (G.vertices[i].data == v)
            return i;
    }
    return -1;
}
Status CreateUDG(ALGraph &G)
{
    char v1, v2;
    int i, j, k, w;
    // cout << "请输入图的顶点和边数量" << endl;
    cin >> G.vexnum >> G.arcNum;
    for (i = 0; i < G.vexnum; i++)
    {
        // cout << "请输入第" << i + 1 << "个顶点的数据" << endl;
        cin >> G.vertices[i].data;
        G.vertices[i].firstArc = NULL;
    }
    for (k = 0; k < G.arcNum; k++)
    {
        // cout << "请输入第" << k + 1 << "条边的两个顶点" << endl; //这此不考虑边的权值
        cin >> v1 >> v2 >> w;
        i = LocateVex(G, v1);
        j = LocateVex(G, v2);

        ArcNode *p = new ArcNode;
        if (p == NULL)
            exit(-1);
        p->adjVex = j;
        p->nextArc = G.vertices[i].firstArc;
        p->info = w;
        G.vertices[i].firstArc = p;
    }
    return 1;
}
void FindIndegree(ALGraph G, int *indegree)
{
    for (int i = 0; i < G.vexnum; i++)
    {
        indegree[i] = 0;
    }
    for (int i = 0; i < G.vexnum; i++)
    {
        ArcNode *p = G.vertices[i].firstArc;
        while (p != NULL)
        {
            indegree[p->adjVex]++;
            p = p->nextArc;
        }
    }
}
Status TopologicalSort(ALGraph G, int *topo)
{
    deque<int> Q;
    int *indegree = new int[G.vexnum];
    FindIndegree(G, indegree);
    for (int i = 0; i < G.vexnum; i++)
    {
        if (indegree[i] == 0)
            Q.push_back(i);
    }
    int count = 0;
    while (!Q.empty())
    {
        int v = Q.front();
        topo[count++] = v;
        Q.pop_front();
        ArcNode *p = G.vertices[v].firstArc;
        while (p != NULL)
        {
            indegree[p->adjVex]--;
            if (indegree[p->adjVex] == 0)
                Q.push_back(p->adjVex);
            p = p->nextArc;
        }
    }
    delete[] indegree;
    if (count != G.vexnum)
        return ERROR;
    else
        return OK;
}
Status CriticalPath(ALGraph G, int *topo)
{
    int i, j, k;
    int Ve[MaxVexNum], Vl[MaxVexNum];
    int Ee[MaxArcNum], El[MaxArcNum];
    ArcNode *p = NULL;
    if (TopologicalSort(G, topo) == ERROR)
        return ERROR;
    for (i = 0; i < G.vexnum; i++)
        Ve[i] = 0;
    for (i = 0; i < G.vexnum; i++)
    {
        k = topo[i];
        p = G.vertices[k].firstArc;
        while (p != NULL)
        {
            if (Ve[p->adjVex] < Ve[k] + p->info) // Ve[i] = Max{Ve[k] + p->weight} 弧为<k,i>
            {
                Ve[p->adjVex] = Ve[k] + p->info;
            }
            p = p->nextArc;
        }
    }
    for (i = 0; i < G.vexnum; i++)
        Vl[i] = Ve[G.vexnum - 1];
    for (i = G.vexnum - 1; i >= 0; i--)
    {
        k = topo[i];
        p = G.vertices[k].firstArc;
        while (p != NULL)
        {
            if (Vl[k] > Vl[p->adjVex] - p->info) // Vl[i] = Min{Vl[K] - p->weight}  弧为<i,k>)
            {
                Vl[k] = Vl[p->adjVex] - p->info;
            }
            p = p->nextArc;
        }
    }
    for (i = 0, j = 0; i < G.vexnum; i++)
    {
        p = G.vertices[i].firstArc;
        while (p != NULL)
        {
            Ee[j] = Ve[i];
            El[j] = Vl[p->adjVex] - p->info;
            if (Ee[j] == El[j])
            {
                cout << G.vertices[i].data << G.vertices[p->adjVex].data << " ";
            }
            p = p->nextArc;
            j++;
        }
    }
    return OK;
}

int main()
{
    ALGraph G;
    CreateUDG(G); // 采用邻接表创建无向图
    int topo[G.vexnum] = {0};

    // 若有关键路径，输出路径上的所有弧（再输出一空格用于间隔）
    if (CriticalPath(G, topo) != OK)
        cout << "Error!" << endl;

    return 0;
}
