#include <iostream>
using namespace std;
class AA
{
public:
    AA(int x, int y, int z)
    {
        a = x;
        b = y;
        c = z;
    }

    friend int add(AA &aa);

private:
    int a, b, c;
};
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    AA a1(a, b, c);
    cout << add(a1) << endl;

    return 0;
}
int add(AA &aa)
{
    return aa.a + aa.b + aa.c;
}