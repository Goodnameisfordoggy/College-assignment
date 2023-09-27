// cout << "运行的是writing.cpp" << endl;
#include <iostream>
using namespace std;
class exe
{
private:
	int x;

public:
	void set_a(int a)
	{
		cin >> a;
		x = a;
	}
	void show_a()
	{
		cout << x << endl;
	}
};
int main()
{
	int m = 0;
	exe b;
	exe *p;
	b.set_a(m);
	b.show_a();
	p = &b;
	p->show_a();
	(*p).show_a();
}
