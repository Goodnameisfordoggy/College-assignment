#include <stdio.h>
#include <math.h>
#define PI 3.1415926
int main()
{
    double r, h, s, ss, v, vv, c;
    scanf("%lf,%lf", &r, &h);
    c = 2 * PI * r;
    s = PI * r * r;
    ss = 4 * PI * r * r;
    v = 4.0 / 3.0 * PI * r * r * r;
    vv = s * h;
    printf("%.2lf,%.2lf\n%.2lf,%.2lf,%.2lf", c, s, ss, v, vv);
    return 0;
}
