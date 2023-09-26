#include <stdio.h>

int main()
{
    char x, y, z;
    x = getchar();
    y = getchar();
    z = getchar();
    printf("%c%c%c\n%d %d %d", x, y, z, x, y, z);
    return 0;
}
