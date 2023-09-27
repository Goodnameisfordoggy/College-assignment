// cout << "运行的是writing.cpp" << endl;
#include <iostream>
using namespace std;
class Date
{
private:
	const int year;
	const int month;
	const int day;

public:
	Date(int year, int month, int day);
	void show_Date();
};
Date::Date(int y, int m, int d) : year(y), month(m), day(d)
{
}
void Date::show_Date()
{
	cout << year << '.' << month << '.' << day << endl;
}
int main()
{
	int year, month, day;
	cin >> year >> month >> day;
	Date d1(year, month, day);
	d1.show_Date();
	return 0;
}