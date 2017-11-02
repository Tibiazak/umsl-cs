#include <stdio.h>
#include "min.h"
#include "max.h"
#include "sum.h"
#include "avg.h"

int main()
{
   float a[3] = {1.1, 2.2, 3.3};
   printf("min: %.2f\n", min(a,3));
   printf("max: %.2f\n", max(a,3));
   printf("sum: %.2f\n", sum(a,3));
   printf("avg: %.2f\n", avg(a,3));
   return 0;
}
