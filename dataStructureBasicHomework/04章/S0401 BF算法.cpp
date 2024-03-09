/***
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2023-10-30 11:25:22
 * @FilePath: \c++\c++ BasicAlgorithmHomework\04章\S0401 BF算法.cpp
 * @Description:
 *
// 题目内容：
// 练习BF算法，通过模式匹配进行子串查找。
// 例1(前2行为输入)：
// abcdef adf
// bcd
// 2
例2(前2行为输入)：
abcd efg
bcde
0
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

#define MAXSIZE 100 // 定义字符串的最大长度

// 定义字符串结构
struct SString
{
    char str[MAXSIZE];
    int length;
};

// 初始化字符串
void InitSString(SString &s)
{
    cin.getline(s.str, MAXSIZE);
    // 手动计算字符串长度
    int i = 0;
    while (s.str[i] != '\0' && i < MAXSIZE)
    {
        i++;
    }
    s.length = i;
}

// BF算法：s2若为s1的子串，返回匹配的开始位置，否则返回0
int Index_BF(SString &s1, SString &s2, int pos)
{
    int i = pos - 1; // i为s1的下标，从0开始
    int j = 0;       // j为s2的下标，从0开始

    while (i < s1.length && j < s2.length)
    {
        if (s1.str[i] == s2.str[j])
        {
            i++;
            j++;
        }
        else
        {
            i = i - j + 1; // 回溯到上一次匹配的下一个位置
            j = 0;
        }
    }

    if (j == s2.length)
    {
        return i - j + 1; // 返回匹配的开始位置（下标从1开始）
    }
    else
    {
        return 0; // 未找到匹配的子串
    }
}

int main()
{
    SString s1, s2;
    InitSString(s1);
    InitSString(s2);

    // BF算法：s2若为s1的子串，返回匹配的开始位置，否则返回0
    cout << Index_BF(s1, s2, 1) << endl;

    return 0;
}