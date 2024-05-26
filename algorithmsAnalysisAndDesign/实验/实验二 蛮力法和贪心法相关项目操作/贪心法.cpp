/***
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2024-05-20 23:11:08
 * @FilePath: \c++\algorithmsAnalysisAndDesign\ʵ��\ʵ���\̰�ķ�.cpp
 * @Description:
 * ̰�ķ�����ⱳ������
���������������б��Ϊ1��2������n��n����Ʒ�����ǵ������ֱ�Ϊw1��w2������wn����ֵ�ֱ�Ϊv1��v2������vn��
����wi��vi��1��i��n����Ϊ��������һ����������Я�����������������W��
���Ŀ�꣺�ڲ������������ص�ǰ���£�ʹ����װ����ܼ�ֵ��󣨼�Ч����󻯣�����0/1��������������ǣ�
�����ÿ����Ʒ����ȡһ����װ�뱳����
 * @
 * @				*		д��¥��д�ּ䣬д�ּ������Ա��
 * @				*		������Աд�������ó��򻻾�Ǯ��
 * @				*		����ֻ���������������������ߣ�
 * @				*		��������ո��գ����������긴�ꡣ
 * @				*		��Ը�������Լ䣬��Ը�Ϲ��ϰ�ǰ��
 * @				*		���۱������Ȥ���������г���Ա��
 * @				*		����Ц��߯��񲣬��Ц�Լ���̫����
 * @				*		��������Ư���ã��ĸ���ó���Ա��
 * @Copyright (c) 2024 by HDJ, All Rights Reserved.
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item
{
    int number; // ��Ʒ���
    int weight; // ��Ʒ����
    int value;  //  ��Ʒ��ֵ
    double valuePerWeight; // ��ֵ�ܶ�
    double fraction; // ���ڼ�¼ÿ����Ʒ��ѡȡ�ı���
};

// �ȽϺ��������ڰ���λ������ֵ����
bool compareItems(const Item &a, const Item &b)
{
    return a.valuePerWeight > b.valuePerWeight;
}

// ̰���㷨��ⱳ������
double fractionalKnapsack(vector<Item> &items, double W)
{
    // ����ÿ����Ʒ�ĵ�λ������ֵ
    for (size_t i = 0; i < items.size(); ++i)
    {
        items[i].valuePerWeight = (double)items[i].value / items[i].weight;
    }

    // ����λ������ֵ�Ӵ�С����
    sort(items.begin(), items.end(), compareItems);

    double maxValue = 0.0;
    double currentWeight = 0.0;

    for (size_t i = 0; i < items.size(); ++i)
    {
        if (currentWeight + items[i].weight <= W)
        {
            currentWeight += items[i].weight;
            maxValue += items[i].value;
            items[i].fraction = 1.0; // ��Ʒ����ȫѡȡ
        }
        else
        {
            double remainingWeight = W - currentWeight;
            maxValue += items[i].valuePerWeight * remainingWeight;
            items[i].fraction = remainingWeight / items[i].weight; // ��Ʒ������ѡȡ
            break;
        }
    }

    return maxValue;
}

int main()
{
    int n = 4;     // 
    
    
    double W = 10; // �������������

    vector<Item> items = {
        {1, 2, 2, 0, 0.0},
        {2, 8, 19, 0, 0.0},
        {3, 3, 6, 0, 0.0},
        {4, 6, 3, 0, 0.0}};

    double maxValue = fractionalKnapsack(items, W);

    cout << "�����п���װ�������ֵ: " << maxValue << endl;
    cout << "������Ʒ��ѡȡ�ı���:" << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << "��Ʒ��ţ�" << items[i].number << " ��Ʒ����: " << items[i].weight << " ��Ʒ��ֵ: " << items[i].value << " ��ѡȡ�ı���: " << items[i].fraction << endl;
    }

    return 0;
}
