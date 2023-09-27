// cout << "运行的是writing.cpp" << endl;
#include <iostream>
#include <string>
using namespace std;
class Girl;
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
	void dis_b(Girl &);
	void dis_g(Girl &);
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
	friend Boy;
};
void Boy::dis_b(Girl &b)
{
	cout << "The boy's name is " << name << ", and his age is " << age << '.' << endl;
}
void Boy::dis_g(Girl &g)
{
	cout << "The girl's name is " << g.name << ", and her age is " << g.age << '.' << endl;
}
int main()
{
	Boy b("Tom", 19);
	Girl g("Mary", 18);
	b.dis_b(g);
	b.dis_g(g);
	return 0;
}