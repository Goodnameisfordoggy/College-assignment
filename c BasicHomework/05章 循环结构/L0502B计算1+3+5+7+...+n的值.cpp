#include <stdio.h>

int main()
{
  int n, i = 1, sum = 0;
  scanf("%d", &n);
  if ((n * 2) % 2 == 0)
  {
    while (i <= n)
    {
      sum += i;
      i += 2;
    }
  }
  printf("sum=%d", sum);
}
