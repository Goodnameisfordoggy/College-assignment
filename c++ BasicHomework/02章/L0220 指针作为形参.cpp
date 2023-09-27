#include <iostream>
using namespace std;
int main()
{
	void swap(int *x, int *y);
	int a, b;
	cin >> a >> b;
	cout << "a=" << a << ","
		 << "b=" << b << endl;
	swap(&a, &b);
	cout << "After swap:a=" << a << ",b=" << b << endl;
	return 0;
}
void swap(int *x, int *y)
{
	int t = 0;
	t = *x;
	*x = *y;
	*y = t;
}