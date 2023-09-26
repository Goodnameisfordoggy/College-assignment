#include <stdio.h>
#include <math.h>
int main()
{
    float a, b;
    int n;
    scanf("%f%d", &a, &n);
    b = pow((1 + a), n);
    printf("%.2f", b);
}