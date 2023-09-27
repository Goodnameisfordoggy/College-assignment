// cout << "���е���writing.cpp" << endl;
#include <iostream>
using namespace std;
class Three
{
private:
    int a, b, c;

public:
    Three(int a, int b, int c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
    void print();
    friend Three operator++(Three &t);      // ǰ׺++
    friend Three operator++(Three &t, int); // ��׺++
};
void Three::print()
{
    cout << "a=" << a << ",b=" << b << ",c=" << c << endl;
}
Three operator++(Three &t)
{
    ++t.a;
    ++t.b;
    ++t.c;
    return t;
}
Three operator++(Three &t, int)
{
    t.a++;
    t.b++;
    t.c++;
    return t;
}
int main()
{
    int a1, a2, a3, b1, b2, b3;
    cin >> a1 >> a2 >> a3 >> b1 >> b2 >> b3;
    Three t1(a1, a2, a3), t2(b1, b2, b3);

    t1.print();
    ++t1;
    t1.print();
    t1++;
    t1.print();
    cout << endl;
    t2.print();
    operator++(t2);
    t2.print();
    operator++(t2, 0);
    t2.print();

    return 0;
}