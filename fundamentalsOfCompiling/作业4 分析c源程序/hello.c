#include <stdio.h>
int main(int argc, char *argv[])
{
    printf("hello,the world!\n");
    int a = 11;
    float f = 12.545;
    double d = 23.54;
    printf("%d\n,%g\n,%lg\n", a, f, d);

    return 0;
}