/***
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2023-10-08 17:13:44
 * @FilePath: \c++\c++ BasicAlgorithmHomework\03章\S0309 括号匹配 .cpp
 * @Description:
 * 检查表达式中括号是否匹配。
// 例：
// （1）输入：a*{b*[c+d+e/(f-g)]} 输出：True
// （2）输入：a*{b*[c+d+e/(f-g)}] 输出：False
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
#include <stack>
using namespace std;

bool Matching(string s)
{
    stack<char> bracketsStack;

    for (size_t i = 0; i < s.length(); i++) // 使用size_t是因为s.length()d的返回值类型是size_t,如果使用int会有警告
    {
        char ch = s[i];
        // 如果是左半边,入栈
        if (ch == '(' || ch == '[' || ch == '{')
        {
            bracketsStack.push(ch);
        }
        // 如果是右半边,开始配对
        else if (ch == ')' || ch == ']' || ch == '}')
        {
            if (bracketsStack.empty())
            {
                return false;
            }
            //就近的左半边出栈比较
            char top = bracketsStack.top();
            bracketsStack.pop();
            if ((ch == ')' && top != '(') || (ch == ']' && top != '[') || (ch == '}' && top != '{'))
            {
                return false;
            }
        }
    }

    return bracketsStack.empty();
}

int main()
{
    string str;
    getline(cin, str);
    if (Matching(str))
        cout << "True" << endl;
    else
        cout << "False" << endl;
    return 0;
}