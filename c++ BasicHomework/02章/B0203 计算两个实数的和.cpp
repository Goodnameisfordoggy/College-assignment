#include <iostream>
using namespace std;
float a, b;
int main()
{
	float add(float x, float y);
	float r;
	cin >> a >> b;
	r = add(a, b);
	cout << a << "+" << b << "=" << r;
	return 0;
}
float add(float x, float y)
{
	float sum;
	sum = x + y;
	return sum;
}