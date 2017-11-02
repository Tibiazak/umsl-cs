/*
 * Joshua Bearden
 * CS2750 PA3
 * 10/10/17
 */

float max(float a[], int n)
{
   int i;
   float max = a[0];
   for (i = 0; i < n; i++)
   {
      if (a[i] > max)
      {
         max = a[i];
      }
   }
   return max;
}
