#include <stdio.h>

int main()
{
    char a;
    a = getchar();
    if (a >= 65 && a <= 90)
    {
        printf("%c", a + 32);
    }
    else
        printf("%c", a);
}
