#include <stdio.h>
// #pragma warning  (disable:4996)
int main()
{
    float N5(float array[]);
    float score[5];
    int i;
    float aver;
    for (i = 0; i < 5; i++)
    {
        scanf("%f", &score[i]);
    }
    aver = N5(score);
    printf("average=%.2f", aver);
    return 0;
}
float N5(float array[])
{
    int i;
    float aver, sum = array[0];
    for (i = 1; i < 5; i++)
    {
        sum = sum + array[i];
    }
    aver = sum / 5;
    return (aver);
}
