/***
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2023-11-06 10:56:26
 * @FilePath: \c++\c++ BasicAlgorithmHomework\06��\S0603 ����ͼ��������������������ڽӱ�.cpp
 * @Description:
 * ��S0601�Ļ������޸ĳ���ʹ���ڽӱ��������ͼ�������������������
// ��1(ֻ�����2��Ϊ���)��
// 3 2
// ABC
// AB
// AC
// ACB
// BAC

// ��2��ֻ�����2��Ϊ�������
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
#include <vector>
#include <list>
using namespace std;

const int MAXV = 100; // ��󶥵���

// �ڽӱ��еı߽��
struct ArcNode
{
    int adjvex;           // �ڽӵ��ڶ��������е�λ��
    struct ArcNode *next; // ָ����һ���ڽӵ��ָ��
};

// �ڽӱ��еĶ�����
struct VNode
{
    char data;             // ��������
    struct ArcNode *first; // ָ���һ���ڽӵ��ָ��
};

// �ڽӱ��ʾ��ͼ
struct ALGraph
{
    vector<VNode> vertices; // ��������
    int vexnum, arcnum;     // �������ͱ���
};

int visited[MAXV]; // ��Ƕ����Ƿ񱻷���

// ��������ͼ���ڽӱ�
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

        // ͷ�巨����������
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

// ����������������ڽӱ��ʾ��ͼ
void DFS_AL(ALGraph &G, int v)
{
    cout << G.vertices[v].data; // �����ǰ����
    visited[v] = 1;                    // ��ǵ�ǰ����Ϊ�ѷ���

    ArcNode *p = G.vertices[v].first;
    while (p != NULL)
    {
        if (!visited[p->adjvex])
        {
            DFS_AL(G, p->adjvex); // �ݹ�������ڶ���
        }
        p = p->next;
    }
}

int main()
{
    ALGraph G;
    CreateUDG(G); // �����ڽӱ�������ͼ
    DFS_AL(G, 0); // �������������������ͼ
    cout << endl;
    for (int i = 0; i < G.vexnum; i++)
        visited[i] = 0;
    if (G.vexnum > 1)
        DFS_AL(G, 1);
    cout << endl;
    return 0;
}
