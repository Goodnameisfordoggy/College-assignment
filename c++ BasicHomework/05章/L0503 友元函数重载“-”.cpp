// cout << "运行的是writing.cpp" << endl;
#include <iostream>
using namespace std;
class Coord
{
private:
    int x, y;

public:
    Coord(int x = 0, int y = 0)
    {
        this->x = x;
        this->y = y;
    }
    friend Coord operator-(Coord &coo);
    void print();
};
Coord operator-(Coord &coo)
{
    coo.x = -coo.x;
    coo.y = -coo.y;
    return coo;
}
void Coord::print()
{
    cout << "x=" << x << ",y=" << y << endl;
}
int main()
{
    int x, y;
    cin >> x >> y;
    Coord ob1(x, y), ob2;
    ob1.print();
    ob2 = -ob1;
    ob2.print();

    return 0;
}