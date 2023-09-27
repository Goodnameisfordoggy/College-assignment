// cout << "运行的是writing.cpp" << endl;
#include <iostream>
using namespace std;
class Date
{
private:
	int year;
	int month;
	int day;

public:
	Date(int y, int m, int d);
	void show_Date();
	void show_Date() const;
};
Date::Date(int y, int m, int d) : year(y), month(m), day(d)
{
}
void Date::show_Date()
{
	cout << "showDate1:" << endl;
	cout << year << '.' << month << '.' << day << endl;
}
void Date::show_Date() const
{
	cout << "showDate2:" << endl;
	cout << year << '.' << month << '.' << day << endl;
}
int main()
{
	Date d1(1998, 4, 28);
	d1.show_Date();
	const Date d2(2002, 11, 14);
	d2.show_Date();
	return 0;
}