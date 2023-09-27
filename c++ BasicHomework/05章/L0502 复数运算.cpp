// cout << "运行的是writing.cpp" << endl;
#include <iostream>
using namespace std;
class Complex
{
private:
    double real;
    double imag;

public:
    Complex(double real = 0.0, double imag = 0.0)
    {
        this->real = real;
        this->imag = imag;
    }
    void print();
    friend Complex operator+(Complex &a, Complex &b);
    friend Complex operator-(Complex &a, Complex &b);
    friend Complex operator*(Complex &a, Complex &b);
    friend Complex operator/(Complex &a, Complex &b);
};
Complex operator+(Complex &a, Complex &b)
{
    Complex t;
    t.real = a.real + b.real;
    t.imag = a.imag + b.imag;
    return t;
}
Complex operator-(Complex &a, Complex &b)
{
    Complex t;
    t.real = a.real - b.real;
    t.imag = a.imag - b.imag;
    return t;
}
Complex operator*(Complex &a, Complex &b)
{
    Complex t;
    t.real = a.real * b.real - a.imag * b.imag;
    t.imag = a.real * b.imag + a.imag * b.real;
    return t;
}
Complex operator/(Complex &a, Complex &b)
{
    Complex t;
    double x;
    x = 1 / (b.real * b.real + b.imag * b.imag);
    t.real = (a.real * b.real + a.imag * b.imag) * x;
    t.imag = (a.imag * b.real - a.real * b.imag) * x;
    return t;
}
void Complex::print()
{
    cout << real;
    if (imag > 0)
        cout << '+';
    if (imag != 0)
        cout << imag << 'i' << endl;
}
int main()
{
    double a1, a2, b1, b2;
    cin >> a1 >> a2 >> b1 >> b2;
    Complex A1(a1, a2), A2(b1, b2), A3, A4, A5, A6;
    A3 = A1 + A2;
    A4 = A1 - A2;
    A5 = A1 * A2;
    A6 = A1 / A2;
    A1.print();
    A2.print();
    A3.print();
    A4.print();
    A5.print();
    A6.print();
    return 0;
}