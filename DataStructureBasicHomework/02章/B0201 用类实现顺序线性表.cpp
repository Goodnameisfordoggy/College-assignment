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
    // ���Ա�ĵĳ�ʼ�������롢ȡֵ
    Sqlist Lscore; // ����Sqlist���󲢳�ʼ���������洢ѧ�������ݽṹ���ɼ������100�ˣ�

    for (int i = 1; i <= 3; i++) // ����3��ѧ���ɼ���������ӵ����Ա���
    {
        int s;
        cin >> s;
        Lscore.insert(s);
    }
    Lscore.show(); // �������Ա�

    int loc;
    cin >> loc; // ����Ҫɾ����λ��
    if (Lscore.deleteLoc(loc) == OK)
        cout << "delete success!" << endl;
    else
        cout << "Error!" << endl;

    Lscore.show();

    return 0;
}