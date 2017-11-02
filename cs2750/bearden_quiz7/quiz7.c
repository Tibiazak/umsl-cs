#include <stdio.h>
#include <stdlib.h>

int main(int arc, char **argv)
{
	int num1;
	int num2;
	printf("Please enter a number: ");
	scanf("%d", &num1);
	printf("Please enter another number: ");
	scanf("%d", &num2);
	int result = num1 + num2;
	printf("Result %d + %d = %d \n", num1, num2, result);
	return 0;
}
