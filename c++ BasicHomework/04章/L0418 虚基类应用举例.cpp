// cout << "运行的是writing.cpp" << endl;
#include <iostream>
using namespace std;
class Person
{
protected:
	string name;
	char sex;
	int age;

public:
	Person(string name, char sex, int age)
	{
		this->name = name;
		this->sex = sex;
		this->age = age;
	}
};
class Student : virtual public Person
{
protected:
	int score;
	string major;

public:
	Student(string name, char sex, int age, int score, string major) : Person(name, sex, age)
	{
		this->score = score;
		this->major = major;
	}
};
class Employee : virtual public Person
{
protected:
	string dept;
	double salary;

public:
	Employee(string name, char sex, int age, string dept, double salary) : Person(name, sex, age)
	{
		this->dept = dept;
		this->salary = salary;
	}
};
class E_Student : public Student, public Employee
{
public:
	E_Student(string name, char sex, int age, string major, int score, string dept, double salary) : Person(name, sex, age), Student(name, sex, age, score, major), Employee(name, sex, age, dept, salary)
	{
	}
	void print();
};
void E_Student::print()
{
	cout << "name:" << name << endl;
	cout << "sex:" << sex << endl;
	cout << "age:" << age << endl;
	cout << "score:" << score << endl;
	cout << "major:" << major << endl;
	cout << "dept:" << dept << endl;
	cout << "salary:" << salary << endl;
}
int main()
{
	E_Student my_E_Student("WangYue", 'f', 35, "Computer", 95, "Teaching Affaires Office", 3500);
	my_E_Student.print();

	return 0;
}