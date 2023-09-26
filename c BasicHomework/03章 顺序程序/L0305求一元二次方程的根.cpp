#include <stdio.h>
#include <math.h>
int main()
{
    double a, b, c, area, s;
    scanf("%lf%lf%lf", &a, &b, &c);
    s = (a + b + c) / 2;
    area = sqrt(s * (s - a) * (s - b) * (s - c));
    printf("%.3f", area);
    return 0;
}