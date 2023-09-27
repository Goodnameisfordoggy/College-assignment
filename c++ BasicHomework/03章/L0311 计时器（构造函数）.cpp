// cout << "运行的是writing.cpp" << endl;
#include <cstdlib> //atoi 的头文件
#include <iostream>
using namespace std;
class Timer
{
private:
	int seconds;

public:
	Timer();
	Timer(const char *t);
	Timer(int t);
	Timer(int m, int s);
	int getTimer()
	{
		return seconds;
	}
};
Timer::Timer()
{
	seconds = 0;
}
Timer::Timer(const char *t)
{
	seconds = atoi(t);
}
Timer::Timer(int t)
{
	seconds = t;
}
Timer::Timer(int m, int s)
{
	cin >> m >> s;
	seconds = 60 * m + s;
}
int main()
{
	int m = 0, s = 0;
	Timer a;
	Timer b(10);
	Timer c("20");
	Timer d(m, s);
	cout << "seconds1=" << a.getTimer() << endl;
	cout << "seconds2=" << b.getTimer() << endl;
	cout << "seconds3=" << c.getTimer() << endl;
	cout << "seconds4=" << d.getTimer() << endl;
	return 0;
}