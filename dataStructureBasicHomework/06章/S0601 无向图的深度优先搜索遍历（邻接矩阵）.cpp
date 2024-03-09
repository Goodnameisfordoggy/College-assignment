/***
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2023-11-06 10:44:01
 * @FilePath: \c++\c++ BasicAlgorithmHomework\06��\S0601 ����ͼ��������������������ڽӾ���.cpp
 * @Description:
 * �����ڽӾ����ʾ����ͼ�������������������
// ��1�����1��Ϊ���������Ϊ���룩��
// 1 0
// A
// A

// ��2�����2��Ϊ���������Ϊ���룩��
// 4 4
// ABCD
// AB 1
// AC 2
// AD 3
// CD 5
// ABCD
// BACD
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
#include <cstring>
using namespace std;

const int MAXV = 100; // ��󶥵���

typedef struct
{
    char vexs[MAXV];      // ���㼯��
    int arcs[MAXV][MAXV]; // �ڽӾ���������ʾ�ߵĹ�ϵ
    int vexnum, arcnum;   // �������ͱ���
} AMGraph;

int visited[MAXV]; // ��Ƕ����Ƿ񱻷���

// ��������ͼ���ڽӾ���
void CreateUDN(AMGraph &G)
{
    cin >> G.vexnum >> G.arcnum;

    for (int i = 0; i < G.vexnum; i++)
        cin >> G.vexs[i];

    memset(G.arcs, 0, sizeof(G.arcs)); // ��ʼ���ڽӾ���

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
        G.arcs[index2][index1] = weight; // ����ͼ������Ҫ�Գ�
    }
}

// ���������������ͼ
void DFS_AM(AMGraph &G, int v)
{
    cout << G.vexs[v]; // �����ǰ����

    visited[v] = 1; // ��ǵ�ǰ����Ϊ�ѷ���

    for (int i = 0; i < G.vexnum; i++)
    {
        if (G.arcs[v][i] != 0 && !visited[i]) // �б���δ����
        {
            DFS_AM(G, i); // �ݹ�������ڶ���
        }
    }
}

int main()
{
    AMGraph G;
    CreateUDN(G); // ��������ͼ���ڽӾ���
    DFS_AM(G, 0); // ���������������ͼ
    cout << endl;
    for (int i = 0; i < G.vexnum; i++)
        visited[i] = 0;
    if (G.vexnum > 1)
        DFS_AM(G, 1);
    cout << endl;
    return 0;
}