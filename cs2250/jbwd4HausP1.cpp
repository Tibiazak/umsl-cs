#include <cstdlib>
#include <iostream>
#include <new>
#include <time.h>
using namespace std;

/*
Joshua Bearden
6/29/15
CS2250
Program 1
*/

//Method to initialize an array with sequential ints
void initialize_array(int * arr, int size)
{
	int * itr = arr;
	for(int i = 0; i < size; i++)
	{
		*itr = i;
		itr++;
	}
}

//Method to shuffle an array
int * shuffle_array(int * arr, int size)
{
	srand (time(NULL)); //seed the random number generator
	
	//allocate memory for the new shuffled array
	//and initialize it with sequential numbers
	int * shuf_arr = new int[size];
	initialize_array(shuf_arr, size);
	
	//iterators for the swap
	int * itr1 = shuf_arr;
	int * itr2 = shuf_arr;
	
	//some helper integers
	int j = 0;
	int temp = 0;


	for (int i = size-1; i >= 1; i--)
	{
		j = rand() % i+1; //get a random number between 0 and i

		//set itr1 = shuf_arr[i]
		for(int k = 0; k < i; k++)
		{
			itr1++;
		}
		//set itr2 = shuf_arr[j]
		for(int k = 0; k < j; k++)
		{
			itr2++;
		}
		//swap shuf_arr[i] and shuf_arr[j]
		temp = *itr1;
		*itr1 = *itr2;
		*itr2 = temp;
		//reset itr1 and itr2 for the next time through the loop
		itr1 = shuf_arr;
		itr2 = shuf_arr;
	}
	return shuf_arr;
}

//a method to loop through an array printing its elements
void print_array(int * arr, int size)
{
	int * itr = arr;
	cout << "[";
	for(int i = 0; i < size; i++)
	{
		cout << *itr << " ";
		itr++;
	}
	cout << "]" << endl;
}

//a method to split an array down the middle into two different arrays
//and return their sizes
void split_up_array(int * arr, int size, int *& split1, int *& split2, int & size1, int & size2)
{
	//split the array into part A and part B
	size1 = size/2;
	size2 = size - size1;
	split1 = new int[size1];
	split2 = new int[size2];

	int * arr_itr = arr;
	int * split_itr = split1;

	//fill part A
	for (int i = 0; i < size1; i++)
	{
		*split_itr = *arr_itr;
		arr_itr++;
		split_itr++;
	}

	//fill part B
	split_itr = split2;
	for (int i = size1; i < size; i++)
	{
		*split_itr = *arr_itr;
		arr_itr++;
		split_itr++;
	}
}

void array_war(int * arr1, int size, int * arr2, int size2)
{
	int winSize = ((size > size2) ? size : size2);
	int * arrWin = new int[winSize];

	int * arr1_itr = arr1;
	int * arr2_itr = arr2;
	int * arrWin_itr = arrWin;

	if(size == size2)
	{
		for(int i = 0; i < winSize; i++)
		{
			*arrWin_itr = ((*arr1_itr > *arr2_itr) ? *arr1_itr : *arr2_itr);
			arrWin_itr++;
			arr1_itr++;
			arr2_itr++;
		}
	}
	else if(size > size2)
	{
		for(int i = 0; i < size2; i++)
		{
			*arrWin_itr =((*arr1_itr > *arr2_itr) ? *arr1_itr : *arr2_itr);
			arrWin_itr++;
			arr1_itr++;
			arr2_itr++;
		}
		*arrWin_itr = *arr1_itr;
	}
	else
	{
		for(int i = 0; i < size; i++)
		{
			*arrWin_itr =((*arr1_itr > *arr2_itr) ? *arr1_itr : *arr2_itr);
			arrWin_itr++;
			arr1_itr++;
			arr2_itr++;
		}
		*arrWin_itr = *arr2_itr;
	}

	cout << "ArrayFight winners were: ";
	print_array(arrWin, winSize);

	sort_array(arrWin, winSize);
	cout << "Sorted ArrayFight winners were: ";
}

void sort_array(int * arr, int size)
{
	int * leftBound = arr;
	int * itr = arr;
	int * smallest = arr;
	int temp = 0;

	for (int i = 0; i < size-1; i++)
	{
		for(int j = i; j < size; j++)
		{
			itr++;
			if(*itr < *smallest)
			{
				smallest = itr;
			}
		}

		temp = *leftBound;
		*leftBound = *smallest;
		*smallest = temp;
		leftBound++;
		itr = leftBound;
		smallest = leftBound;
	}
}

int main()
{
	int size = 0;
	bool valid = false;
	//a loop for input validation, if the size is negative or greater
	//than 52, the loop will simply prompt the user to enter another size.
	while (!valid)
	{
		cout << "Please enter the size of the array: ";
		cin >> size;
		if (0 < size && size <= 52)
			valid = true;
		else
			cout << "Invalid size, must be between 1 and 52" << endl;
	}

	//dynamically allocate memory for the array and initialize it
	int * arr = new int[size];
	initialize_array(arr, size);

	//print the original array
	cout << "Original array is: ";
	print_array(arr, size);

	//shuffle the original array and print the shuffled array
	int * shuf_arr = shuffle_array(arr, size);
	cout << "Shuffled array is: ";
	print_array(shuf_arr, size);
	
	//split the shuffled array
	//create variables
	int split_array_size1 = 0;
	int split_array_size2 = 0;
	int * split_array1 = 0;
	int * split_array2 = 0;

	split_up_array(shuf_arr, size, split_array1, split_array2, split_array_size1, split_array_size2);
	cout << "After call to split_array, shuffled array is: ";
	print_array(shuf_arr, size);
	cout << "After call to split_array, part A is: ";
	print_array(split_array1, split_array_size1);
	cout << "After call to split_array, part B is: ";
	print_array(split_array2, split_array_size2);

	//call array_war
	array_war(split_array1, split_array_size1, split_array2, split_array_size2);

	//free up the memory and return from the main method
	delete[] arr;
	delete[] shuf_arr;
	delete[] split_array1;
	delete[] split_array2;
	return 0;
}