// cout << "运行的是writing.cpp" << endl;
#include <iostream>
using namespace std;
class Tr
{
private:
	int i;

public:
	Tr(int n)
	{
		i = n;
	}
	void set_i(int n)
	{
		i = n;
	}
	int get_i()
	{
		return i;
	}
};
void sqrt_it(Tr ob)
{
	ob.set_i(ob.get_i() * ob.get_i());
	cout << "In sqr_it, the value of i in the formal perameter object ob is:" << ob.get_i();
	cout << endl;
}
int main()
{
	Tr obj(10);
	cout << "Before running sqr_it,the value of i in the actual perameter object obj is:" << obj.get_i() << endl;
	sqrt_it(obj);
	cout << "After running sqr_it,the value of i in the actual perameter object obj is:" << obj.get_i() << endl; // 用对象作为函数参数,单向传递,形参不能传回给实参,所以对象obj中的i在此还是10
	return 0;
}