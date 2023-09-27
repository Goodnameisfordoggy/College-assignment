// cout << "运行的是writing.cpp" << endl;
#include <iostream>
#include <cstring>
using namespace std;
class STRING
{
private:
    char *str;

public:
    STRING(const char *s)
    {
        cout << "Constructor called." << endl;
        str = new char[(strlen(s) + 1)];
        strcpy(str, s);
    }
    ~STRING()
    {
        cout << "Destructor called.---" << str << endl;
    }
    STRING &operator=(const STRING &s);
};
STRING &STRING::operator=(const STRING &s)
{
    if (this == &s)
        return *this;
    delete str;
    str = new char[strlen(s.str) + 1];
    strcpy(str, s.str);
    return *this;
}
int main()
{
    STRING p1("book");
    STRING p2("jeep");
    p2 = p1;

    return 0;
}
