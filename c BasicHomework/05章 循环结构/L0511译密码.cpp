#include <stdio.h>
#include <string.h>
int main()
{
  char a[10];
  int i, n;
  gets(a);
  n = strlen(a);
  for (i = 0; i < n; i++)
  {
    if (a[i] >= 65 && a[i] <= 86 || a[i] >= 97 && a[i] <= 118)
    {
      printf("%c", a[i] + 4);
    }
    else if (a[i] >= 87 && a[i] <= 90 || a[i] >= 119 && a[i] <= 122)
    {
      printf("%c", a[i] - 22);
    }
    else
    {
      printf("%c", a[i]);
    }
  }
  return 0;
}
