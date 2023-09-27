// cout << "运行的是writing.cpp" << endl;
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
class Complex
{
private:
	double real, image;

public:
	Complex(double real = 0.0, double image = 0.0);
	double abscomplex();
	void input();
};
Complex::Complex(double real, double image)
{
	this->real = real;
	this->image = image;
}
double Complex::abscomplex()
{
	double t;
	t = real * real + image * image;
	return sqrt(t);
}
void Complex::input()
{
	double real, image;
	cin >> real >> image;
	this->real = real;
	this->image = image;
}
int main()
{
	Complex s1;
	Complex s2(1.1);
	Complex s3;
	s3.input();
	cout << s1.abscomplex() << endl;
	cout << setprecision(4);
	cout.setf(ios::fixed);
	cout << s2.abscomplex() << endl;
	cout << s3.abscomplex() << endl;
	return 0;
}
