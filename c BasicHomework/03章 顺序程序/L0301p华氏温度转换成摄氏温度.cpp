#include <stdio.h>
int main()
{
    float h, s;
    scanf("%f", &h);
    s = 5.0 / 9.0 * (h - 32.0);
    printf("%.2f", s);
    return 0;
}