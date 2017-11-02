//main.c
/*
 * Edited by Joshua Bearden
 * CS2750 PA3
 * 12/10/2017
 */
#include <stdio.h>
#include <stdlib.h>

#include "avg.h"
#include "sum.h"
#include "min.h"
#include "max.h"

#define N 10

int main()
{
   int i;
   float a[N];
   srand(123);
   for (i = 0; i < N; i++) 
   {
      a[i] = ((double) rand())/ RAND_MAX;
      printf("%.2f ",a[i]);
   }
   printf("\n\n");
   printf("average: %.2f\n", avg(a,N));
   printf("sum: %.2f\n", sum(a,N));
   printf("min: %.2f\n", min(a,N));
   printf("max: %.2f\n", max(a,N));
   return 0;
}

