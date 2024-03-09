/***
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2023-10-08 17:13:44
 * @FilePath: \c++\c++ BasicAlgorithmHomework\03��\S0309 ����ƥ�� .cpp
 * @Description:
 * �����ʽ�������Ƿ�ƥ�䡣
// ����
// ��1�����룺a*{b*[c+d+e/(f-g)]} �����True
// ��2�����룺a*{b*[c+d+e/(f-g)}] �����False
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
#include <stack>
using namespace std;

bool Matching(string s)
{
    stack<char> bracketsStack;

    for (size_t i = 0; i < s.length(); i++) // ʹ��size_t����Ϊs.length()d�ķ���ֵ������size_t,���ʹ��int���о���
    {
        char ch = s[i];
        // ���������,��ջ
        if (ch == '(' || ch == '[' || ch == '{')
        {
            bracketsStack.push(ch);
        }
        // ������Ұ��,��ʼ���
        else if (ch == ')' || ch == ']' || ch == '}')
        {
            if (bracketsStack.empty())
            {
                return false;
            }
            //�ͽ������߳�ջ�Ƚ�
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