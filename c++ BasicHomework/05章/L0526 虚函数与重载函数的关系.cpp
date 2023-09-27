// cout << "运行的是writing.cpp" << endl;
#include <iostream>
using namespace std;
class Base
{
public:
	virtual void func1();
	virtual void func2();
	virtual void func3();
	void func4();
};
class Derived : public Base
{
public:
	virtual void func1();
	void func2(int);
	void func4();
};
void Base::func1()
{
	cout << "--Base func1--" << endl;
}
void Base::func2()
{
	cout << "--Base func2--" << endl;
}
void Base::func3()
{
	cout << "--Base func3--" << endl;
}
void Base::func4()
{
	cout << "--Base func4--" << endl;
}
void Derived::func1()
{
	cout << "--Derived func1--" << endl;
}
void Derived::func2(int)
{
	cout << "--Derived func2--" << endl;
}
void Derived::func4()
{
	cout << "--Derived func4--" << endl;
}
int main()
{
	Base d1, *bp;
	Derived d2;
	bp = &d2;
	bp->func1();
	bp->func2();
	bp->func4();
	return 0;
}