// cout << "运行的是writing.cpp" << endl;
#include <iostream>
using namespace std;
template <typename T>
T Max(T x, T y)
{
	return (x > y) ? x : y;
}
template <typename T>
T Max(T x, T y, T z)
{
	T t;
	t = (x > y) ? x : y;
	return (t > z) ? t : z;
}
int main()
{
	int m = 10, n = 20;
	double a = 10.1, b = 20.2, c = 30.3;
	cout << "max(10,20)=" << Max(m, n) << endl;
	cout << "max(10.1,20.2,30.3)=" << Max(a, b, c) << endl;
}