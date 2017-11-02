/*
 * Joshua Bearden
 * CS2750 PA3
 * 10/10/17
 */

#include <stdio.h>
#include "sum.h"

float avg(float a[], int n)
{
   float total = sum(a, n);
   float average = (total / n);
   return average;
}
