/***
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2023-11-13 10:21:36
 * @FilePath: \c++\c++ BasicAlgorithmHomework\�ϻ���ϰ��\У԰����ͼ.cpp
 * @Description:
 * Ϊ��У���һ����ͨ��ѯϵͳ�����÷ÿ���ѯ����һ��У�ڵص㵽��һ���ص�֮������·����
// ��Ʒ��������֣�
// һ�ǽ���У԰��ͨ����ͼ���ڴ��ṹ��
// ���ǽ����Դ���·�����⣺
// �����ʵ�������ص�֮������·�����⡣
//����:
// 4
// School Library Park Home
// 5
// School Library 2
// School Park 4
// Library Park 1
// Library Home 7
// Park Home 3
// School
// Home
// ���:
// �� School �� Home �����·��Ϊ:
// ·��: School Library Park Home
// ·������: 6
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
#include <climits>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

const int MAX_VERTICES = 100;

class CampusMap
{
public:
    int vertices;
    vector<vector<int>> adjacencyMatrix;
    unordered_map<string, int> vertexIndices; // ���ڽ���������ӳ�䵽����
    unordered_map<int, string> vertexNames;   // ���ڽ�����ӳ�䵽��������

    CampusMap(int v) : vertices(v), adjacencyMatrix(v, vector<int>(v, INT_MAX)) {}

    void addEdge(const string &start, const string &end, int weight)
    {
        int startIndex = vertexIndices[start];
        int endIndex = vertexIndices[end];
        adjacencyMatrix[startIndex][endIndex] = weight;
        adjacencyMatrix[endIndex][startIndex] = weight; // ����ͼ����Ҫ�Գ�
    }

    void dijkstraShortestPath(const string &source, const string &destination)
    {
        set<pair<int, int>> pq; // Dijkstra's�㷨�����ȶ���
        vector<int> dist(vertices, INT_MAX);
        vector<int> prev(vertices, -1);

        int sourceIndex = vertexIndices[source];
        int destinationIndex = vertexIndices[destination];

        dist[sourceIndex] = 0;
        pq.insert({0, sourceIndex});

        while (!pq.empty())
        {
            int u = pq.begin()->second;
            pq.erase(pq.begin());

            for (int v = 0; v < vertices; ++v)
            {
                if (adjacencyMatrix[u][v] != INT_MAX)
                {
                    int newDist = dist[u] + adjacencyMatrix[u][v];
                    if (newDist < dist[v])
                    {
                        pq.erase({dist[v], v});
                        dist[v] = newDist;
                        prev[v] = u;
                        pq.insert({dist[v], v});
                    }
                }
            }
        }

        // �����Դ�㵽Ŀ�������·��
        stack<int> path;
        int current = destinationIndex;
        while (current != -1)
        {
            path.push(current);
            current = prev[current];
        }

        cout << "�� " << source << " �� " << destination << " �����·��Ϊ:\n";
        cout << "·��: ";
        while (!path.empty())
        {
            cout << vertexNames[path.top()] << " ";
            path.pop();
        }
        cout << "\n·������: " << dist[destinationIndex] << endl;
    }
};

int main()
{
    int vertices, edges;
    cout << "�����붥����: ";
    cin >> vertices;

    CampusMap campus(vertices);

    cout << "�����붥�������:" << endl;
    for (int i = 0; i < vertices; ++i)
    {
        string vertexName;
        cin >> vertexName;
        campus.vertexIndices[vertexName] = i;
        campus.vertexNames[i] = vertexName;
    }

    cout << "���������: ";
    cin >> edges;

    cout << "������ߵ���Ϣ���磺School Library 2 ��ʾ���� School �Ͷ��� Library ֮����һ����Ȩ��Ϊ2��:" << endl;
    for (int i = 0; i < edges; i++)
    {
        string v1, v2;
        int weight;
        cin >> v1 >> v2 >> weight;

        campus.addEdge(v1, v2, weight);
    }

    string source, destination;
    cout << "��������㶥��: ";
    cin >> source;

    cout << "�������յ㶥��: ";
    cin >> destination;

    campus.dijkstraShortestPath(source, destination);

    return 0;
}
