#include <stdio.h>
int main()
{
    int a, b, c, d, x;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    if (a > b)
    {
        x = a;
        a = b;
        b = x;
    }
    if (a > c)
    {
        x = a;
        a = c;
        c = x;
    }
    if (a > d)
    {
        x = a;
        a = d;
        d = x;
    }
    if (b > c)
    {
        x = b;
        b = c;
        c = x;
    }
    if (b > d)
    {
        x = b;
        b = d;
        d = x;
    }
    if (c > d)
    {
        x = c;
        c = d;
        d = x;
    }
    printf("%d %d %d %d", a, b, c, d);
    return 0;
}