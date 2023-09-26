#include <stdio.h>
#include <math.h>
int main()
{
    double a, b, c, x1, x2, d;
    scanf("%lf%lf%lf", &a, &b, &c);
    d = b * b - 4 * a * c;
    x1 = -b / (2 * a) + sqrt(d) / (2 * a);
    x2 = -b / (2 * a) - sqrt(d) / (2 * a);
    printf("x1=%8.3lf\nx2=%8.3lf", x1, x2);
    return 0;
}
