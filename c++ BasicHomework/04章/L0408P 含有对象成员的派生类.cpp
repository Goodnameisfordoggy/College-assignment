// cout << "运行的是writing.cpp" << endl;
#include <iostream>
using namespace std;
class Base
{
private:
    int x;

public:
    Base(int t)
    {
        x = t;
        cout << "Constructing class Base." << endl;
    }
    ~Base()
    {
        cout << "Destructing class Base." << endl;
    }
    void show()
    {
        cout << "x=" << x << endl;
    }
};
class Derived : public Base
{
public:
    Base d;
    Derived(int t) : Base(t), d(t)
    {
        cout << "Constructing derived class." << endl;
    }
    ~Derived()
    {
        cout << "Destructing derived class." << endl;
    }
};
int main()
{
    Derived obj(5);
    obj.show();
    return 0;
}