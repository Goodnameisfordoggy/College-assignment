// cout << "���е���writing.cpp" << endl;
#include <iostream>
#include <string>
using namespace std;
class Girl; // �˴���û����ǰ����class Girl,��class Boy����Ԫ��֪��class Girl�Ĵ���,�ʲ��ܵ���class Gril��private��ĳ�Ա.
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