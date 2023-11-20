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
    // cout << "������ͼ�Ķ���ͱ�����" << endl;
    cin >> G.vexnum >> G.arcNum;
    for (i = 0; i < G.vexnum; i++)
    {
        // cout << "�������" << i + 1 << "�����������" << endl;
        cin >> G.vertices[i].data;
        G.vertices[i].firstArc = NULL;
    }
    for (k = 0; k < G.arcNum; k++)
    {
        // cout << "�������" << k + 1 << "���ߵ���������" << endl; //��˲����Ǳߵ�Ȩֵ
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
            if (Ve[p->adjVex] < Ve[k] + p->info) // Ve[i] = Max{Ve[k] + p->weight} ��Ϊ<k,i>
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
            if (Vl[k] > Vl[p->adjVex] - p->info) // Vl[i] = Min{Vl[K] - p->weight}  ��Ϊ<i,k>)
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
    CreateUDG(G); // �����ڽӱ�������ͼ
    int topo[G.vexnum] = {0};

    // ���йؼ�·�������·���ϵ����л��������һ�ո����ڼ����
    if (CriticalPath(G, topo) != OK)
        cout << "Error!" << endl;

    return 0;
}
