// cout << "运行的是writing.cpp" << endl;
#include <iostream>
using namespace std;
class Base
{
protected:
	int x;

public:
	Base(int t)
	{
		x = t;
		cout << "Base()..." << endl;
	}
	void print();
};
void Base::print()
{
	cout << "x=" << x << endl;
}
class Base1 : virtual public Base
{
public:
	Base1(int t) : Base(t)
	{
		x = t;
		cout << "Base1()..." << endl;
	}
};
class Base2 : virtual public Base
{
public:
	Base2(int t) : Base(t)
	{
		x = t;
		cout << "Base2()..." << endl;
	}
};
class Derive : public Base1, public Base2
{
public:
	Derive(int t) : Base(t), Base1(t), Base2(t)
	{
		x = t;
		cout << "Derive()..." << endl;
	}
};
int main()
{
	Base1 b1(1);
	b1.print();
	Base2 b2(2);
	b2.print();
	Derive d(3);
	d.print();
	return 0;
}