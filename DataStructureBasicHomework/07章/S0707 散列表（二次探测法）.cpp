#include <iostream>
using namespace std;

struct HashTable
{
    int key;
};

int Hash(int key, int i, int m)
{
    return (key % m + i * i) % m;
}

void InitHash(HashTable hs[], int m)
{
    for (int i = 0; i < m; i++)
    {
        hs[i].key = 0;
    }
}

void InsertHash(HashTable hs[], int n, int m, int key)
{
    int i = 0;
    int j;
    do
    {
        j = Hash(key, i, m);
        if (hs[j].key == 0)
        {
            hs[j].key = key;
            break;
        }
        i++;
    } while (i < m);
}

void ShowHash(HashTable hs[], int m)
{
    for (int i = 0; i < m; i++)
    {
        if (hs[i].key != 0)
        {
            cout << "hs[" << i << "].key=" << hs[i].key << endl;
        }
    }
}

int main()
{
    int n, i; //
    int m;    // ��Ϊm
    cin >> n >> m;
    HashTable hs[m];
    InitHash(hs, m);            // ��ʼ��ɢ�б�����Ԫ�ص�kֵ��Ϊ0����ֵԪ�أ�
    for (i = 0; i < n - 1; i++) // ��n+1��������ӵ�ɢ�б���
    {
        int t;
        cin >> t;
        InsertHash(hs, n, m, t);
    }
    ShowHash(hs, m); // ��ʾɢ�б�����ʾ��ֵԪ�أ�
    return 0;
}