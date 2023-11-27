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
    int m;    // 表长为m
    cin >> n >> m;
    HashTable hs[m];
    InitHash(hs, m);            // 初始化散列表，表中元素的k值设为0（空值元素）
    for (i = 0; i < n - 1; i++) // 将n+1个整数添加到散列表中
    {
        int t;
        cin >> t;
        InsertHash(hs, n, m, t);
    }
    ShowHash(hs, m); // 显示散列表（不显示空值元素）
    return 0;
}