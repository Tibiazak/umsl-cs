/*
 * Joshua Bearden
 * CS2750 PA3
 * 10/10/2017
 */
float min(float a[], int n)
{
   float min = a[0];
   int i;
   for (i = 0; i < n; i++)
   {
      if (a[i] < min)
      {
         min = a[i];
      }
   }
   return min;
}
