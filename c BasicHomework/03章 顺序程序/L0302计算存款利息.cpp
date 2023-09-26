#include <stdio.h>
int main()
{
    int b = 1000;
    double p1, p2, p3, r1, r2, r3;
    r1 = 0.0036;
    r2 = 0.0225;
    r3 = 0.0198;
    p1 = b * (1 + r1);
    p2 = b * (1 + r2);
    p3 = b * (1 + r3 / 2) * (1 + r3 / 2);
    printf("p1=%.4f", p1);
    printf("p2=%.4f", p2);
    printf("p3=%.4f", p3);
    return 0;
}
