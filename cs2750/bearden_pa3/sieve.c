/*
 * Joshua Bearden
 * 10/10/2017
 * CS2750 PA3
 */
#include <stdio.h>

int main()
{
   int sieve[100001];
   int i;
   sieve[0] = 0;
   sieve[1] = 0;
   for (i = 2; i < 100001; i++)
      sieve[i] = 1;
   for (i = 2; i < 316; i++)
   {
      int n = i+i;
      while (n < 100001)
      {
         sieve[n] = 0;
         n += i;
      }
   }
   for (i = 2; i < 100001; i++)
   {
      if (sieve[i] == 1)
      {
         printf("%d \n", i);
      }
   }
   return 0;
}
