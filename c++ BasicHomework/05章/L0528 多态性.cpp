// cout << "运行的是writing.cpp" << endl;
#include <iostream>
using namespace std;
class XingZhuang
{
protected:
	double x, y;

public:
	XingZhuang(double x, double y)
	{
		this->x = x;
		this->y = y;
	}
	virtual void mianji() {}
};
class Sanjiaoxing : public XingZhuang
{
public:
	Sanjiaoxing(double x, double y) : XingZhuang(x, y)
	{
	}
	void mianji()
	{
		cout << "Triangle height:" << x << ",base:" << y << ",area:" << 0.5 * x * y << endl;
	}
};
class Juxing : public XingZhuang
{
public:
	Juxing(double x, double y) : XingZhuang(x, y)
	{
	}
	void mianji()
	{
		cout << "Rectangle length:" << x << ",width:" << y << ",area:" << x * y << endl;
	}
};
class Yuan : public XingZhuang
{
public:
	Yuan(double x) : XingZhuang(x, x)
	{
	}
	void mianji()
	{
		cout << "Circle ridius:" << x << ",area:" << x * x * 3.1416 << endl;
	}
};
int main()
{
	XingZhuang *xz;
	Juxing j(10.0, 6.0);
	Sanjiaoxing s(10.0, 6.0);
	Yuan y(10.0);
	xz = &s;
	xz->mianji();
	xz = &j;
	xz->mianji();
	xz = &y;
	xz->mianji();
	return 0;
}