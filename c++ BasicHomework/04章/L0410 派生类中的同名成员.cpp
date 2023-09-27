// cout << "运行的是writing.cpp" << endl;
#include <iostream>
using namespace std;
class Student
{
private:
	int number;
	string name;
	int score;

public:
	Student(int number, string name, int score)
	{
		this->number = number;
		this->name = name;
		this->score = score;
	}
	void print();
};
void Student::print()
{
	cout << "number:" << number << endl;
	cout << "name:" << name << endl;
	cout << "score:" << score << endl;
}
class UStudent : private Student
{
private:
	string major;

public:
	UStudent(int number, string name, int score, string major) : Student(number, name, score)
	{
		this->major = major;
	}
	void print();
};
void UStudent::print()
{
	Student::print();
	cout << "major:" << major << endl;
}
int main()
{
	UStudent stu(22116, "Zhang Zhi", 95, "Computer Science");
	stu.print();

	return 0;
}