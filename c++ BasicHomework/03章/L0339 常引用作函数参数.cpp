// cout << "运行的是writing.cpp" << endl;
#include <iostream>
using namespace std;
int sum(const int &i, const int &j);
int main()
{
    int i = 0, j = 0;
    cin >> i >> j;
    cout << i << '+' << j << '=' << sum(i, j) << endl;
    return 0;
}
int sum(const int &i, const int &j)
{
    return i + j;
}