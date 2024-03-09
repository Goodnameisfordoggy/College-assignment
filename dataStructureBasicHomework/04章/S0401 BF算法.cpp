/***
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2023-10-30 11:25:22
 * @FilePath: \c++\c++ BasicAlgorithmHomework\04��\S0401 BF�㷨.cpp
 * @Description:
 *
// ��Ŀ���ݣ�
// ��ϰBF�㷨��ͨ��ģʽƥ������Ӵ����ҡ�
// ��1(ǰ2��Ϊ����)��
// abcdef adf
// bcd
// 2
��2(ǰ2��Ϊ����)��
abcd efg
bcde
0
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
using namespace std;

#define MAXSIZE 100 // �����ַ�������󳤶�

// �����ַ����ṹ
struct SString
{
    char str[MAXSIZE];
    int length;
};

// ��ʼ���ַ���
void InitSString(SString &s)
{
    cin.getline(s.str, MAXSIZE);
    // �ֶ������ַ�������
    int i = 0;
    while (s.str[i] != '\0' && i < MAXSIZE)
    {
        i++;
    }
    s.length = i;
}

// BF�㷨��s2��Ϊs1���Ӵ�������ƥ��Ŀ�ʼλ�ã����򷵻�0
int Index_BF(SString &s1, SString &s2, int pos)
{
    int i = pos - 1; // iΪs1���±꣬��0��ʼ
    int j = 0;       // jΪs2���±꣬��0��ʼ

    while (i < s1.length && j < s2.length)
    {
        if (s1.str[i] == s2.str[j])
        {
            i++;
            j++;
        }
        else
        {
            i = i - j + 1; // ���ݵ���һ��ƥ�����һ��λ��
            j = 0;
        }
    }

    if (j == s2.length)
    {
        return i - j + 1; // ����ƥ��Ŀ�ʼλ�ã��±��1��ʼ��
    }
    else
    {
        return 0; // δ�ҵ�ƥ����Ӵ�
    }
}

int main()
{
    SString s1, s2;
    InitSString(s1);
    InitSString(s2);

    // BF�㷨��s2��Ϊs1���Ӵ�������ƥ��Ŀ�ʼλ�ã����򷵻�0
    cout << Index_BF(s1, s2, 1) << endl;

    return 0;
}