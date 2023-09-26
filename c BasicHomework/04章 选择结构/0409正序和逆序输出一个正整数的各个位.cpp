#include <stdio.h>
int main()
{
    int a, b, c, d, e, x;
    scanf("%d", &x);
    a = x / 10000;
    b = x % 10000 / 1000;
    c = x % 1000 / 100;
    d = x % 100 / 10;
    e = x % 10;
    if (a != 0)
    {
        printf("num=5,natural order:%2d%2d%2d%2d%2d,", a, b, c, d, e);
        printf("reverse order:%2d%2d%2d%2d%2d", e, d, c, b, a);
    }
    else if (b != 0)
    {
        printf("num=4,natural order:%2d%2d%2d%2d,", b, c, d, e);
        printf("reverse order:%2d%2d%2d%2d", e, d, c, b);
    }
    else if (c != 0)
    {
        printf("num=3,natural order:%2d%2d%2d,", c, d, e);
        printf("reverse order:%2d%2d%2d", e, d, c);
    }
    else if (d != 0)
    {
        printf("num=2,natural order:%2d%2d,", d, e);
        printf("reverse order:%2d%2d", e, d);
    }
    else
    {
        printf("num=1,natural order:%2d,", e);
        printf("reverse order:%2d", e);
    }
    return 0;
}