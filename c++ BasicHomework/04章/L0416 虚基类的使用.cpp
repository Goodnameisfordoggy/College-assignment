// cout << "运行的是writing.cpp" << endl;
#include <iostream>
using namespace std;
class Base
{
protected:
	int a;

public:
	Base()
	{
		a = 5;
		cout << "Base a=" << a << endl;
	}
};
class Base1 : virtual public Base
{
public:
	Base1()
	{
		a = a + 10;
		cout << "Base1 a=" << a << endl;
	}
};
class Base2 : virtual public Base
{
public:
	Base2()
	{
		a = a + 20;
		cout << "Base2 a=" << a << endl;
	}
};
class Derived : public Base1, public Base2
{
public:
	Derived()
	{
		cout << "Derived a=" << a << endl;
	}
};
int main()
{
	Derived obj;

	return 0;
}