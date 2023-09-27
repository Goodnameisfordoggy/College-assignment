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
    Complex operator+(Complex c);
    Complex operator-(Complex c);
    Complex operator*(Complex c);
    Complex operator/(Complex c);
};
Complex Complex::operator+(Complex c)
{
    Complex t;
    t.real = real + c.real;
    t.imag = imag + c.imag;
    return t;
}
Complex Complex::operator-(Complex c)
{
    Complex t;
    t.real = real - c.real;
    t.imag = imag - c.imag;
    return t;
}
Complex Complex::operator*(Complex c)
{
    Complex t;
    t.real = real * c.real - imag * c.imag;
    t.imag = real * c.imag + imag * c.real;
    return t;
}
Complex Complex::operator/(Complex c)
{
    Complex t;
    double x;
    x = 1 / (c.real * c.real + c.imag * c.imag);
    t.real = (real * c.real + imag * c.imag) * x;
    t.imag = (imag * c.real - real * c.imag) * x;
    return t;
}
void Complex::print()
{
    if (real != 0)
        cout << real;
    else
        cout << real << endl;
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