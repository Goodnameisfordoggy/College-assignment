// cout << "���е���writing.cpp" << endl;
#include <iostream>
using namespace std;
class Cat
{
private:
	double weight;
	static double total_weight;
	static int total_number;

public:
	Cat(double weight);
	void display();				 // ���������ֻСè����Ϣ
	static void total_dispaly(); // �����������Сè������Ϣ
};
Cat::Cat(double weight)
{
	this->weight = weight;
	total_weight += weight;
	++total_number;
}
void Cat::display()
{
	cout << "This cat's weight is:" << weight << "kg" << endl;
}
void Cat::total_dispaly()
{
	cout << total_number << " cats' weights are:" << total_weight << "kg" << endl;
}
double Cat::total_weight = 0;
int Cat::total_number = 0;
int main()
{
	Cat c1(0.5);
	Cat c2(0.6);
	Cat c3(0.4);
	c1.display();
	c2.display();
	c3.display();
	Cat::total_dispaly();
	return 0;
}