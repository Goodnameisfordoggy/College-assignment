#include <iostream>
using namespace std;
class Cuboid
{
private:
    float length;
    float width;
    float height;

public:
    void set_value(float l, float w, float h)
    {
        length = l;
        width = w;
        height = h;
    }
    float count_area()
    {
        float area;
        area = 2 * (length * width) + 2 * (width * height) + 2 * (height * length);
        return area;
    }
    float count_volume()
    {
        float volume;
        volume = length * width * height;
        return volume;
    }
    void show()
    {
        cout << "area=" << count_area() << ",volume=" << count_volume() << endl;
    }
};
int main()
{
    Cuboid cc;
    float a, b, c;
    cin >> a >> b >> c;
    cc.set_value(a, b, c);
    cc.count_area();
    cc.count_volume();
    cc.show();
    return 0;
}