/***
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2024-05-20 23:11:08
 * @FilePath: \c++\algorithmsAnalysisAndDesign\实验\实验二\贪心法.cpp
 * @Description:
 * 贪心法：求解背包问题
【问题描述】设有编号为1、2、…、n的n个物品，它们的重量分别为w1、w2、…、wn，价值分别为v1、v2、…、vn，
其中wi、vi（1≤i≤n）均为正数。有一个背包可以携带的最大重量不超过W。
求解目标：在不超过背包负重的前提下，使背包装入的总价值最大（即效益最大化），与0/1背包问题的区别是，
这里的每个物品可以取一部分装入背包。
 * @
 * @				*		写字楼里写字间，写字间里程序员；
 * @				*		程序人员写程序，又拿程序换酒钱。
 * @				*		酒醒只在网上坐，酒醉还来网下眠；
 * @				*		酒醉酒醒日复日，网上网下年复年。
 * @				*		但愿老死电脑间，不愿鞠躬老板前；
 * @				*		奔驰宝马贵者趣，公交自行程序员。
 * @				*		别人笑我忒疯癫，我笑自己命太贱；
 * @				*		不见满街漂亮妹，哪个归得程序员？
 * @Copyright (c) 2024 by HDJ, All Rights Reserved.
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item
{
    int number; // 物品编号
    int weight; // 物品重量
    int value;  //  物品价值
    double valuePerWeight; // 价值密度
    double fraction; // 用于记录每个物品被选取的比例
};

// 比较函数，用于按单位重量价值排序
bool compareItems(const Item &a, const Item &b)
{
    return a.valuePerWeight > b.valuePerWeight;
}

// 贪心算法求解背包问题
double fractionalKnapsack(vector<Item> &items, double W)
{
    // 计算每个物品的单位重量价值
    for (size_t i = 0; i < items.size(); ++i)
    {
        items[i].valuePerWeight = (double)items[i].value / items[i].weight;
    }

    // 按单位重量价值从大到小排序
    sort(items.begin(), items.end(), compareItems);

    double maxValue = 0.0;
    double currentWeight = 0.0;

    for (size_t i = 0; i < items.size(); ++i)
    {
        if (currentWeight + items[i].weight <= W)
        {
            currentWeight += items[i].weight;
            maxValue += items[i].value;
            items[i].fraction = 1.0; // 物品被完全选取
        }
        else
        {
            double remainingWeight = W - currentWeight;
            maxValue += items[i].valuePerWeight * remainingWeight;
            items[i].fraction = remainingWeight / items[i].weight; // 物品被部分选取
            break;
        }
    }

    return maxValue;
}

int main()
{
    int n = 4;     // 
    
    
    double W = 10; // 背包的最大重量

    vector<Item> items = {
        {1, 2, 2, 0, 0.0},
        {2, 8, 19, 0, 0.0},
        {3, 3, 6, 0, 0.0},
        {4, 6, 3, 0, 0.0}};

    double maxValue = fractionalKnapsack(items, W);

    cout << "背包中可以装入的最大价值: " << maxValue << endl;
    cout << "各个物品被选取的比例:" << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << "物品编号：" << items[i].number << " 物品重量: " << items[i].weight << " 物品价值: " << items[i].value << " 被选取的比例: " << items[i].fraction << endl;
    }

    return 0;
}
