// cout << "运行的是writing.cpp" << endl;
#include <iostream>
using namespace std;
class Coord
{
private:
    int i, j;

public:
    Coord(int i = 0, int j = 0)
    {
        this->i = i;
        this->j = j;
    }
    void print();
    Coord operator++();
};
void Coord::print()
{
    cout << "x=" << i << ",y=" << j << endl;
}
Coord Coord::operator++()
{
    ++i;
    ++j;
    Coord::print();
    return *this;
}
int main()
{
    int x, y;
    cin >> x >> y;
    Coord ob(x, y);

    ob.print();
    ++ob;
    ob.print();

    ob.operator++();
    ob.print();

    Coord ob2;
    ob2 = ++ob;
    ob2.print();
    ob.print();

    return 0;
}