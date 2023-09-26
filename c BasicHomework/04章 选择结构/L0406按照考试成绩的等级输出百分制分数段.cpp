#include <stdio.h>

int main()
{
    char a;
    scanf("%c", &a);
    switch (a)
    {
    case 'A':
        printf("Your score:85~100");
        break;
    case 'B':
        printf("Your score:70~84");
        break;
    case 'C':
        printf("Your score:60~69");
        break;
    case 'D':
        printf("Your score:<60");
        break;
    }
}