/***
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2023-11-06 10:56:26
 * @FilePath: \c++\c++ BasicAlgorithmHomework\06章\S0603 无向图的深度优先搜索遍历（邻接表）.cpp
 * @Description:
 * 在S0601的基础上修改程序，使用邻接表完成无向图的深度优先搜索遍历。
// 例1(只有最后2行为输出)：
// 3 2
// ABC
// AB
// AC
// ACB
// BAC

// 例2（只有最后2行为输出）：
// 8 8
// ABCDEFGH
// AF
// AB
// BC
// CG
// GH
// HD
// DB
// BE
// ABEDHGCF
// BEDHGCAF
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
#include <vector>
#include <list>
using namespace std;

const int MAXV = 100; // 最大顶点数

// 邻接表中的边结点
struct ArcNode
{
    int adjvex;           // 邻接点在顶点数组中的位置
    struct ArcNode *next; // 指向下一个邻接点的指针
};

// 邻接表中的顶点结点
struct VNode
{
    char data;             // 顶点数据
    struct ArcNode *first; // 指向第一个邻接点的指针
};

// 邻接表表示的图
struct ALGraph
{
    vector<VNode> vertices; // 顶点数组
    int vexnum, arcnum;     // 顶点数和边数
};

int visited[MAXV]; // 标记顶点是否被访问

// 创建无向图的邻接表
void CreateUDG(ALGraph &G)
{
    cin >> G.vexnum >> G.arcnum;

    for (int i = 0; i < G.vexnum; i++)
    {
        VNode v;
        cin >> v.data;
        v.first = NULL;
        G.vertices.push_back(v);
    }

    for (int i = 0; i < G.arcnum; i++)
    {
        char v1, v2;
        cin >> v1 >> v2;

        int index1, index2;
        for (int j = 0; j < G.vexnum; j++)
        {
            if (G.vertices[j].data == v1)
                index1 = j;
            if (G.vertices[j].data == v2)
                index2 = j;
        }

        // 头插法建立边链表
        ArcNode *arc1 = new ArcNode();
        arc1->adjvex = index2;
        arc1->next = G.vertices[index1].first;
        G.vertices[index1].first = arc1;

        ArcNode *arc2 = new ArcNode();
        arc2->adjvex = index1;
        arc2->next = G.vertices[index2].first;
        G.vertices[index2].first = arc2;
    }
}

// 深度优先搜索遍历邻接表表示的图
void DFS_AL(ALGraph &G, int v)
{
    cout << G.vertices[v].data; // 输出当前顶点
    visited[v] = 1;                    // 标记当前顶点为已访问

    ArcNode *p = G.vertices[v].first;
    while (p != NULL)
    {
        if (!visited[p->adjvex])
        {
            DFS_AL(G, p->adjvex); // 递归访问相邻顶点
        }
        p = p->next;
    }
}

int main()
{
    ALGraph G;
    CreateUDG(G); // 采用邻接表创建无向图
    DFS_AL(G, 0); // 深度优先搜索遍历无向图
    cout << endl;
    for (int i = 0; i < G.vexnum; i++)
        visited[i] = 0;
    if (G.vexnum > 1)
        DFS_AL(G, 1);
    cout << endl;
    return 0;
}
