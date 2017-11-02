#include <stdio.h>
#include <string.h>

int main()
{
   int i = 0;
   int total = 0;
   FILE * f;
   f = fopen("nums.txt", "r");
   
   if (f==NULL)
   {
      printf("Error: The file could not be opened!\n");
      return 1;
   }
   
   while(!feof(f)) 
   {
      int num;
      fscanf(f, "%i", &num);
      total += num;
      i++;
      printf("The running total is %i, the running count is %i, the current number is %i\n", total, i, num);
   }
   fclose(f);
   printf("The total is %i, the average is %f\n", total, (float)total/i);
   return 0;
}
