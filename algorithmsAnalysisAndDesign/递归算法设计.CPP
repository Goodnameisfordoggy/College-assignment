/*
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2024-03-09 21:27:25
 * @FilePath: \c++\algorithmsAnalysisAndDesign\递归算法设计.CPP
 * @Description:数列的首项a1 = 0 ，后续奇数项和偶数项的计算公式分别为 a2n =a2n-1 + 2，a2n+1 = a2n-1 + a2n - 1，
 * 写出计算数列第 n 项的递归算法。
 * // 0 2 1 3 3 5 7 9 15 17
 *
 * 				*		写字楼里写字间，写字间里程序员；
 * 				*		程序人员写程序，又拿程序换酒钱。
 * 				*		酒醒只在网上坐，酒醉还来网下眠；
 * 				*		酒醉酒醒日复日，网上网下年复年。
 * 				*		但愿老死电脑间，不愿鞠躬老板前；
 * 				*		奔驰宝马贵者趣，公交自行程序员。
 * 				*		别人笑我忒疯癫，我笑自己命太贱；
 * 				*		不见满街漂亮妹，哪个归得程序员？
 * Copyright (c) ${2024} by ${HDJ}, All Rights Reserved.
 */
#include <iostream>

long long int calculate(int n)
{
    // n=1时, 返回首项a1 = 0
    if (n == 1)
    {
        return 0;
    }
    // n=2时, a2 = a1 + 2 = 0 + 2
    if (n == 2)
    {
        return 0 + 2;
    }
    // 计算奇数项
    else if (n % 2 == 1)
    {
        return calculate(n - 2) + calculate(n - 1) - 1;
    }
    // 计算偶数项
    else
    {
        return calculate(n - 1) + 2;
    }
}

int main()
{
    int n;
    std::cout << "要求第几项: ";
    std::cin >> n;
    std::cout << calculate(n);
    return 0;
}