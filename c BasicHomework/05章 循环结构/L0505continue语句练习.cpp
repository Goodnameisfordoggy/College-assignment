#include <stdio.h>
main()
{
   int n = 100;
   for (; n <= 200; n++)
   {
      if (n % 2 == 0 || n % 3 == 0)
         continue;
      printf("%d ", n);
   }
}