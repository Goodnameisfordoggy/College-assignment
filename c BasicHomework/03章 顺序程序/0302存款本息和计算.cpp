#include <stdio.h>
#include <math.h>
float f1(int n, float r, float b)
{
    return b * (1 + n * r);
}
float f2(int n, float r, float b)
{
    return b * pow((1 + r), n);
}
float f3(int n, float r, float b)
{
    return b * pow((1 + r / 4), 4 * n);
}
main()
{
    float b, r1, r2, r3, r4, r5, p1, p2, p3, p4, p5;
    scanf("%f%f%f%f%f%f", &b, &r1, &r2, &r3, &r4, &r5);
    p1 = f1(5, r4, b);
    p2 = f1(3, r3, f1(2, r2, b));
    p3 = f1(2, r2, f1(3, r2, b));
    p4 = f2(5, r1, b);
    p5 = f3(5, r5, b);
    printf("%.2f,%.2f,%.2f,%.2f,%.2f", p1, p2, p3, p4, p5);
    return 0;
}