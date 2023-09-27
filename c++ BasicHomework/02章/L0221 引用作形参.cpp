#include <iostream>
using namespace std;
int main()
{
    int a, b;
    cin >> a >> b;
    cout << "a=" << a << ",b=" << b << endl;
    swap(a, b);
    cout << "After swap:";
    cout << "a=" << a << ",b=" << b << endl;
    return 0;
}
void swap(int &m, int &n)
{
    int t = 0;
    t = m;
    m = n;
    n = t;
}