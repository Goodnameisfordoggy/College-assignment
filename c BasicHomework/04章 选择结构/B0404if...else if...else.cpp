#include <stdio.h>
#include <math.h>
int main()
{
    float x, y;
    scanf("%f,%f", &x, &y);
    if (x > 0 && y > 0)
    {
        printf("%.2f", sqrt(x + y));
    }
    else if (x > 0 && y <= 0)
    {
        printf("%.2f", sin(x) + cos(y));
    }
    else if (x <= 0 && y > 0)
    {
        printf("%.2f", exp(x - y));
    }
    else
    {
        printf("%.2f", fabs(pow(x, y)));
    }
}