/***
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2023-10-08 17:14:27
 * @FilePath: \c++\c++ BasicAlgorithmHomework\02章\B0201 用类实现顺序线性表.cpp
 * @Description:
 * 用类实现顺序线性表，给定代码如下图所示。
// 例1（第1、4行为输入）：
// 90 88 78
// 1:90
// 2:88
// 3:78
// 2
// delete success!
// 1:90
// 2:78

// 例2（第1、4行为输入）：
// 88 77 90
// 1:88
// 2:77
// 3:90
// 4
// Error!
// 1:88
// 2:77
// 3:90
 * @
 * @				/*		写字楼里写字间，写字间里程序员；
 * @				*		程序人员写程序，又拿程序换酒钱。
 * @				*		酒醒只在网上坐，酒醉还来网下眠；
 * @				*		酒醉酒醒日复日，网上网下年复年。
 * @				*		但愿老死电脑间，不愿鞠躬老板前；
 * @				*		奔驰宝马贵者趣，公交自行程序员。
 * @				*		别人笑我忒疯癫，我笑自己命太贱；
 * @				\*		不见满街漂亮妹，哪个归得程序员？
 * @Copyright (c) ${2023} by ${HDJ}, All Rights Reserved.
 */
#include <iostream>
using namespace std;

#define OK 1
#define ERROR -1
#define MAXSIZE 100

class Sqlist
{
    int length;
    int date[MAXSIZE];

public:
    Sqlist()
    {
        length = 0;
    };
    void show()
    {
        for (int i = 0; i < length; i++)
        {
            cout << i + 1 << ':' << date[i] << endl;
        }
    }
    int insert(int score)
    {
        if (length > MAXSIZE)
        {
            return ERROR;
        }
        date[length++] = score;
        return OK;
    }
    int deleteLoc(int local)
    {
        if (local < 0 || local > length)
        {
            return ERROR;
        }
        for (int i = local - 1; i < length - 1; i++)
        {
            date[i] = date[i + 1];
        }
        length--;
        return OK;
    }
};
int main()
{
    // 线性表的的初始化、插入、取值
    Sqlist Lscore; // 创建Sqlist对象并初始化，用来存储学生《数据结构》成绩（最多100人）

    for (int i = 1; i <= 3; i++) // 输入3个学生成绩，依次添加到线性表中
    {
        int s;
        cin >> s;
        Lscore.insert(s);
    }
    Lscore.show(); // 遍历线性表

    int loc;
    cin >> loc; // 输入要删除的位置
    if (Lscore.deleteLoc(loc) == OK)
        cout << "delete success!" << endl;
    else
        cout << "Error!" << endl;

    Lscore.show();

    return 0;
}