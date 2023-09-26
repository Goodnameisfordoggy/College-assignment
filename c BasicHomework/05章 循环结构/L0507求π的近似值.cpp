#include <stdio.h>
#include <math.h>
int main()
{
    int sign = 1;
    double pi = 0.0, n = 1.0, term = 1.0;
    while (fabs(term) >= 1e-6)
    {
        pi += term;
        n += 2;
        sign = -sign;
        term = sign / n;
    }
    pi *= 4;
    printf("PI:%10.8f", pi);
}