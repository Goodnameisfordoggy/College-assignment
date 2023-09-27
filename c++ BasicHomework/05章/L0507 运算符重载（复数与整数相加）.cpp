// cout << "运行的是writing.cpp" << endl;
#include <iostream>
using namespace std;
class Complex
{
private:
    int real, imag;

public:
    Complex(int real = 0, int imag = 0)
    {
        this->real = real;
        this->imag = imag;
    }
    friend Complex operator+(Complex c, int a);
    friend Complex operator+(int a, Complex &c);
    void print();
};
Complex operator+(Complex c, int a)
{
    return Complex(c.real + a, c.imag);
}
Complex operator+(int a, Complex &c)
{
    return Complex(c.real + a, c.imag);
}
void Complex::print()
{
    cout << "real=" << real << ",imag=" << imag << endl;
}
int main()
{
    double a, b;
    cin >> a >> b;
    Complex A1(a, b), A2;

    A2 = A1 + 30;
    A2.print();
    A2 = 50 + A1;
    A2.print();
}