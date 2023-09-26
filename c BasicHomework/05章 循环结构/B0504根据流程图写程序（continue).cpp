#include <stdio.h>

int main()
{
  int i = 1, sum = 0, n;
  scanf("%d", &n);
  while (i <= n)
  {
    if (i % 3 == 0)
    {
      i++;
    }
    else
    {
      sum = sum + i;
      i++;
    }
  }
  printf("%d", sum);
}
