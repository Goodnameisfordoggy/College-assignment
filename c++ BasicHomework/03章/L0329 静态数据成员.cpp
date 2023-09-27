// cout << "运行的是writing.cpp" << endl;
#include <iostream>
#include <string>
using namespace std;
class Student
{
public:
	Student(string name, string stu_no, float score);
	~Student();
	void show_all();

private:
	string name;
	string stu_no;
	float score;
	static int count;
	static float sum;
	static float ave;
};
Student::Student(string name, string stu_no, float score)
{
	this->name = name;
	this->stu_no = stu_no;
	this->score = score;
	++count;
	sum += score;
	ave = sum / count;
}
Student::~Student()
{
}
void Student::show_all()
{
	cout << "\nName:" << name << endl;
	cout << "No:" << stu_no << endl;
	cout << "Score:" << score << endl;
	cout << "Number:" << count << endl;
	cout << "Aver:" << ave << endl;
}
int Student::count = 0;
float Student::sum = 0;
float Student::ave = 0;

int main()
{
	Student stu1("Li Ming", "08150201", 90);
	stu1.show_all();
	Student stu2("Zhang Wei", "08150202", 89);
	stu2.show_all();
	return 0;
}