// cout << "运行的是writing.cpp" << endl;
#include <iostream>
using namespace std;
class Circle
{
protected:
	int r;

public:
	void setr(int r)
	{
		this->r = r;
	}
	virtual void show() = 0;
};
class Area : public Circle
{
public:
	void show()
	{
		cout << "The circle's area is " << 3.14 * r * r << endl;
	}
};
class Perimeter : public Circle
{
public:
	void show()
	{
		cout << "The circle's circumference is " << 3.14 * 2 * r << endl;
	}
};
int main()
{
	Circle *ptr;
	Area ob1;
	Perimeter ob2;

	ob1.setr(10);
	ob2.setr(10);
	ptr = &ob1;
	ptr->show();
	ptr = &ob2;
	ptr->show();

	return 0;
}