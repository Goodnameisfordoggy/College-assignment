#include <stdio.h>

int main()
{
    int i = 1, sum = 0, n;
    while (i <= 100)
    {
        scanf("%d", &n);
        sum = sum + n;
        i++;
        if (sum > 20)
            break;
    }
    printf("%d", sum);
}
