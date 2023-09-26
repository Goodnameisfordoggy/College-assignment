#include <stdio.h>

int main()
{
    int m, n, i = 0, sum = 0;
    scanf("%d,%d", &m, &n);
    if (m <= n)
    {
        while (i <= n - m)
        {
            sum = sum + i + m;
            i++;
        }
    }
    printf("sum=%d", sum);
}
