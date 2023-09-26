#include <stdio.h>

int main()
{
    float x, y;
    scanf("%f%f", &x, &y);
    if (x < 1)
    {
        y = x;
    }
    else if (x >= 1 && x < 10)
    {
        y = 2 * x - 1;
    }
    else
    {
        y = 3 * x - 11;
    }
    printf("x=%.3f,y=%.3f", x, y);
}
