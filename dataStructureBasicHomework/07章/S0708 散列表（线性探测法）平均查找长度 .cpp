/***
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2023-11-27 11:43:51
 * @FilePath: \c++\c++ BasicAlgorithmHomework\07章\S0708 散列表（线性探测法）平均查找长度 .cpp
 * @Description:
 * 在S0706的基础上修改程序，计算散列表在查找成功时的平均查找长度。
例（第1、2行为输入）：
13 16
19 14 23 1 68 20 84 27 55 11 10 79
hs[1].key=14
hs[2].key=1
hs[3].key=68
hs[4].key=27
hs[5].key=55
hs[6].key=19
hs[7].key=20
hs[8].key=84
hs[9].key=79
hs[10].key=23
hs[11].key=11
hs[12].key=10
2.5
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
using namespace std;

struct HashTable
{
    int key;
};

void InitHash(HashTable hs[], int m)
{
    for (int i = 0; i < m; ++i)
    {
        hs[i].key = 0; // 将表中元素的key值设为0（表示空值）
    }
}

int Hash(int key, int m, int i)
{
    return (key + i) % m; // 线性探测法 H(key, i) = (key + i) % m
}

int InsertHash(HashTable hs[], int m, int key)
{
    int i = 0;
    int index;
    do
    {
        index = Hash(key, m, i);
        if (hs[index].key == 0)
        {
            hs[index].key = key;
            return i + 1; // 返回成功查找时的比较次数
        }
        ++i;
    } while (i < m);
    return i; // 返回查找失败时的比较次数
}

void ShowHash(HashTable hs[], int m)
{
    for (int i = 0; i < m; ++i)
    {
        if (hs[i].key != 0)
        {
            cout << "hs[" << i + 1 << "].key=" << hs[i].key << endl;
        }
    }
}

int main()
{
    int n, m, sum = 0;
    cin >> n >> m;
    HashTable hs[m];
    InitHash(hs, m);

    for (int i = 0; i < n - 1; ++i)
    {
        int t;
        cin >> t;
        sum += InsertHash(hs, m, t);
    }

    ShowHash(hs, m);
    cout << sum * 1.0 / (n - 1) << endl; // 查找成功时的平均长度
    return 0;
}
