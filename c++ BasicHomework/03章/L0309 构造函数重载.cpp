// cout << "运行的是writing.cpp" << endl;
#include <iostream>
using namespace std;
class Date
{
public:
	Date();
	Date(int y, int m, int d);
	void showDate();
	void input_reconstruction(int y, int m, int d);

private:
	int year, month, day;
};
Date::Date()
{
	year = 2016;
	month = 3;
	day = 8;
}
Date::Date(int y, int m, int d)
{
	year = y;
	month = m;
	day = d;
}
inline void Date::showDate()
{
	cout << year << '.' << month << '.' << day << endl;
}
inline void Date::input_reconstruction(int y, int m, int d)
{
	cin >> y >> m >> d;
	year = y;
	month = m;
	day = d;
}
int main()
{
	int y = 0, m = 0, d = 0;
	Date Date1;
	cout << "Date1 output:" << endl;
	Date1.showDate();
	Date Date2;
	Date2.input_reconstruction(y, m, d);
	cout << "Date2 output:" << endl;
	Date2.showDate();
	return 0;
}
