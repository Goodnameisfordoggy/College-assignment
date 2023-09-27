// cout << "运行的是writing.cpp" << endl;
#include <iostream>
using namespace std;

class Point
{
private:
	int x = 0, y = 0;

public:
	Point(int a, int b)
	{
		x = a;
		y = b;
		cout << "Point(" << a << ',' << b << ')' << endl;
	}
	~Point()
	{
		cout << "~Point():" << x << ',' << y << endl;
	}
	Point(const Point &p)
	{
		x = p.x;
		y = p.y;
		cout << "copy Point(" << x << ',' << y << ')' << endl;
	}
	friend void show(Point, Point);
};
void show(Point P1, Point P2)
{
	cout << "x=" << P1.x << ",y=" << P1.y << endl;
	cout << "x=" << P2.x << ",y=" << P2.y << endl;
}
int main()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	Point p1(a, b), p2(c, d);
	show(p1, p2); // 友元函数

	return 0;
}
