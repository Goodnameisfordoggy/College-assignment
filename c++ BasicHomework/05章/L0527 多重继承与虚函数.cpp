// cout << "运行的是writing.cpp" << endl;
#include <iostream>
using namespace std;
class Base1
{
public:
	virtual void fun();
};
class Base2
{
public:
	void fun();
};
class Derived : public Base1, public Base2
{
public:
	void fun();
};
void Base1::fun()
{
	cout << "--Base1--" << endl;
}
void Base2::fun()
{
	cout << "--Base2--" << endl;
}
void Derived::fun()
{
	cout << "--Derived--" << endl;
}
int main()
{
	Base1 *Ba1;
	Base2 *Ba2;
	Derived de;
	Ba1 = &de;
	Ba1->fun();
	Ba2 = &de;
	Ba2->fun();
	return 0;
}