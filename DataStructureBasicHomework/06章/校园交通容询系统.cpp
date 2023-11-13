/***
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2023-11-13 10:21:36
 * @FilePath: \c++\c++ BasicAlgorithmHomework\上机练习题\校园导航图.cpp
 * @Description:
 * 为我校设计一个交通容询系统，能让访客咨询从任一个校内地点到另一个地点之向的最短路径。
// 设计分三个部分，
// 一是建立校园交通网络图的在储结构：
// 二是解决单源最短路径问题：
// 最后再实现两个地点之向的最短路径问题。
//输入:
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
// 输出:
// 从 School 到 Home 的最短路径为:
// 路径: School Library Park Home
// 路径长度: 6
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
    unordered_map<string, int> vertexIndices; // 用于将顶点名称映射到索引
    unordered_map<int, string> vertexNames;   // 用于将索引映射到顶点名称

    CampusMap(int v) : vertices(v), adjacencyMatrix(v, vector<int>(v, INT_MAX)) {}

    void addEdge(const string &start, const string &end, int weight)
    {
        int startIndex = vertexIndices[start];
        int endIndex = vertexIndices[end];
        adjacencyMatrix[startIndex][endIndex] = weight;
        adjacencyMatrix[endIndex][startIndex] = weight; // 无向图，需要对称
    }

    void dijkstraShortestPath(const string &source, const string &destination)
    {
        set<pair<int, int>> pq; // Dijkstra's算法的优先队列
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

        // 输出从源点到目标点的最短路径
        stack<int> path;
        int current = destinationIndex;
        while (current != -1)
        {
            path.push(current);
            current = prev[current];
        }

        cout << "从 " << source << " 到 " << destination << " 的最短路径为:\n";
        cout << "路径: ";
        while (!path.empty())
        {
            cout << vertexNames[path.top()] << " ";
            path.pop();
        }
        cout << "\n路径长度: " << dist[destinationIndex] << endl;
    }
};

int main()
{
    int vertices, edges;
    cout << "请输入顶点数: ";
    cin >> vertices;

    CampusMap campus(vertices);

    cout << "请输入顶点的名称:" << endl;
    for (int i = 0; i < vertices; ++i)
    {
        string vertexName;
        cin >> vertexName;
        campus.vertexIndices[vertexName] = i;
        campus.vertexNames[i] = vertexName;
    }

    cout << "请输入边数: ";
    cin >> edges;

    cout << "请输入边的信息（如：School Library 2 表示顶点 School 和顶点 Library 之间有一条边权重为2）:" << endl;
    for (int i = 0; i < edges; i++)
    {
        string v1, v2;
        int weight;
        cin >> v1 >> v2 >> weight;

        campus.addEdge(v1, v2, weight);
    }

    string source, destination;
    cout << "请输入起点顶点: ";
    cin >> source;

    cout << "请输入终点顶点: ";
    cin >> destination;

    campus.dijkstraShortestPath(source, destination);

    return 0;
}
