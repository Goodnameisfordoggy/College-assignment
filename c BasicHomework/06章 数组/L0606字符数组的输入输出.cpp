#include <stdio.h>
int main()
{
    char a[100];
    int i;
    gets(a);
    for (i = 0; a[i] != '\0'; i++)
    {
        printf("%c", a[i]);
    }
    return 0;
}