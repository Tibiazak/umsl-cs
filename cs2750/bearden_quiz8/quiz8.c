/*
 * Joshua Bearden
 * CS2750 Quiz 8
 * 05/10/17
 */
#include <stdio.h>
#include <string.h>

int main( int argc, char **argv )
{
   int i;
   if (argc == 2)
   {
      int num = atoi(argv[1]);
      printf("%d! = ", num);
      for(i = num; i > 1; i--)
      {
         num = num * (i-1);
      }
      printf("%d \n", num);
      return 0;
   }
   else
   {
      printf("Please enter a single number as a command line argument.\n");
      return 1;
   }
}
