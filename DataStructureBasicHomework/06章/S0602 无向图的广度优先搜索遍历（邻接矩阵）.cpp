/***
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2023-11-06 10:49:45
 * @FilePath: \c++\c++ BasicAlgorithmHomework\06��\S0602 ����ͼ�Ĺ�����������������ڽӾ���.cpp
 * @Description:
 * ��S0305��S0601�Ļ������޸ĳ���ʹ���ڽӾ����������ͼ�Ĺ����������������
// ��1�����2��Ϊ���������Ϊ���룩��
// 8 8
// ABCDEFGH
// AF 1
// BA 2
// BC 3
// CG 4
// BD 5
// BE 6
// GH 7
// DH 8
// ABFCDEGH
// BACDEFGH
// ��2�����2��Ϊ�������
// 5 4
// BACDE
// AB 1
// BC 2
// BD 3
// DE 4
// BACDE
// ABCDE
// ��3�����1��Ϊ�������
// 1 0
// A
// A
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

const int MAXV = 100; // ��󶥵���

typedef struct
{
    char vexs[MAXV];      // ���㼯��
    int arcs[MAXV][MAXV]; // �ڽӾ���
    int vexnum, arcnum;   // �������ͱ���
} AMGraph;

int visited[MAXV]; // ���ʱ������

// ��������ͼ���ڽӾ���
void CreateUDN(AMGraph &G)
{
    cin >> G.vexnum >> G.arcnum; // ���붥�����ͱ���
    for (int i = 0; i < G.vexnum; i++)
    {
        cin >> G.vexs[i]; // ���붥�㼯��
    }
    for (int i = 0; i < G.vexnum; i++)
    {
        for (int j = 0; j < G.vexnum; j++)
        {
            G.arcs[i][j] = 0; // ��ʼ���ڽӾ���
        }
    }
    for (int k = 0; k < G.arcnum; k++)
    {
        char v1, v2;
        int w;
        cin >> v1 >> v2 >> w; // ����ߵĶ����Ȩֵ
        int i = 0, j = 0;
        while (G.vexs[i] != v1)
            i++; // ���Ҷ���v1��λ��
        while (G.vexs[j] != v2)
            j++;          // ���Ҷ���v2��λ��
        G.arcs[i][j] = w; // ���ñߵ�Ȩֵ
        G.arcs[j][i] = w; // ��Ϊ������ͼ�����ԶԳ�λ��ҲҪ����
    }
}

// ���������������ͼ
void BFS(AMGraph &G, int v)
{
    queue<int> Q;
    cout << G.vexs[v]; // �����ʼ����
    visited[v] = 1;    // ��Ƕ���vΪ�ѷ���
    Q.push(v);         // ������v���
    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop(); // ������u����
        for (int i = 0; i < G.vexnum; i++)
        {
            if (G.arcs[u][i] && !visited[i])
            {
                cout << G.vexs[i];
                visited[i] = 1;
                Q.push(i);
            }
        }
    }
}
int main()
{
    AMGraph G;
    CreateUDN(G); // ��������ͼ���ڽӾ���
    BFS(G, 0);    // ���������������ͼ
    cout << endl;
    for (int i = 0; i < G.vexnum; i++)
        visited[i] = 0;
    if (G.vexnum > 1)
        BFS(G, 1);
    cout << endl;
    return 0;
}
