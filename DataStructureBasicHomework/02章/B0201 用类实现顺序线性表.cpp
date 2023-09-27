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