#include <stdio.h>
int main()
{
	float max1(float x, float y);
	float max2(float z, float m1);
	float a, b, c, m1, m2;
	scanf("%f%f%f", &a, &b, &c);
	m1 = max1(a, b);
	m2 = max2(c, m1);
	printf("max=%.2f", m2);
	return 0;
}
float max1(float x, float y)
{
	float t1;
	if (x > y)
	{
		t1 = x;
	}
	else
	{
		t1 = y;
	}
	return (t1);
}
float max2(float z, float m1)
{
	float t2;
	if (m1 > z)
	{
		t2 = m1;
	}
	else
	{
		t2 = z;
	}
	return (t2);
}