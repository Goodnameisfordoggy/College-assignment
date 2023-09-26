#include <stdio.h>

int main()
{
    float a, b, c, x;
    scanf("%f,%f,%f", &a, &b, &c);
    if (a < b)
    {
        x = a;
        a = b;
        b = x;
    }
    if (a < c)
    {
        x = a;
        a = c;
        c = x;
    }
    if (b < c)
    {
        x = b;
        b = c;
        c = x;
    }
    printf("%.1f,%.1f,%.1f", a, b, c);
}
