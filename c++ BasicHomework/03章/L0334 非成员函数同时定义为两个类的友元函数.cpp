// cout << "运行的是writing.cpp" << endl;
#include <iostream>
#include <string>
using namespace std;
class Girl; // 此处若没有提前声明class Girl,则class Boy的友元不知道class Girl的存在,故不能调用class Gril中private里的成员.
class Boy
{
private:
	string name;
	int age;

public:
	Boy(string name, int age)
	{
		this->name = name;
		this->age = age;
	}
	friend void disp(Girl &gg, Boy &bb);
};
class Girl
{
private:
	string name;
	int age;

public:
	Girl(string name, int age)
	{
		this->name = name;
		this->age = age;
	}
	friend void disp(Girl &gg, Boy &bb);
};
void disp(Girl &gg, Boy &bb)
{
	cout << "The girl's name is " << gg.name << ", age is " << gg.age << endl;
	cout << "The boy's name is " << bb.name << ", age is " << bb.age << endl;
}
int main()
{
	Girl g1("Li Mei", 18);
	Boy b1("Wang Qiang", 19);

	disp(g1, b1);

	return 0;
}