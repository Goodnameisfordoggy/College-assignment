// cout << "运行的是writing.cpp" << endl;
#include <iostream>
using namespace std;
template <typename T>
T Max(T x, T y)
{
	cout << "Calling template function:";
	return (x > y) ? x : y;
}
int Max(int x, int y)
{
	cout << "Calling ordinary function:";
	return (x > y) ? x : y;
}
int main()
{
	int i1 = 10, i2 = 20;
	double d1 = 10.1, d2 = 20.2;
	char s1 = 'a', s2 = 'j';
	cout << "max(int):" << Max(i1, i2) << endl;
	cout << "max(double):" << Max(d1, d2) << endl;
	cout << "max(char):" << Max(s1, s2) << endl;
	return 0;
}