#include <stdio.h>
main()
{
	double l, s, b;
	scanf("%lf", &s);
	l = s * 10000;
	if (l <= 10)
	{
		b = s * 0.1;
		printf("profit=%.4lf,bonus=%.4lf", s, b);
	}
	if (l > 10 && l <= 20)
	{
		b = 1 + (s - 10) * 0.075;
		printf("profit=%.4lf,bonus=%.4lf", s, b);
	}
	if (l > 20 && l <= 40)
	{
		b = 1.75 + (s - 20) * 0.05;
		printf("profit=%.4lf,bonus=%.4lf", s, b);
	}
	if (l > 40 && l <= 60)
	{
		b = 2.75 + (s - 40) * 0.03;
		printf("profit=%.4lf,bonus=%.4lf", s, b);
	}
	if (l > 60 && l <= 100)
	{
		b = 3.35 + (s - 60) * 0.015;
		printf("profit=%.4lf,bonus=%.4lf", s, b);
	}
	if (l > 100)
	{
		b = 3.95 + (s - 100) * 0.01;
		printf("profit=%.4lf,bonus=%.4lf", s, b);
	}
}