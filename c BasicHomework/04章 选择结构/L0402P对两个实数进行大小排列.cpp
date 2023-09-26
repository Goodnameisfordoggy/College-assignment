#include <stdio.h>
int main()
{
    float a, b, x;
    scanf("%f,%f", &a, &b);
    if (a < b)
    {
        x = a;
        a = b;
        b = x;
    }
    printf("%.1f,%.1f", a, b);
    return 0;
}