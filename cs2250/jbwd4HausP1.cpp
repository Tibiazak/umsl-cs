#include <cstdlib>
#include <iostream>
#include <new>
#include <time.h>
using namespace std;

void initialize_array(int * arr, int size)
{
	int * itr = arr;
	for(int i = 0; i < size; i++)
	{
		*itr = i;
		itr++;
	}
}


int * shuffle_array(int * arr, int size)
{
	srand (time(NULL));
	int * shuf_arr = new int[size];
	initialize_array(shuf_arr, size);
	int * itr1 = shuf_arr;
	int * itr2 = shuf_arr;
	int j = 0;
	int temp = 0;

	for (int i = size-1; i >= 1; i--)
	{
		j = rand() % i+1;

		for(int k = 0; k < i; k++)
		{
			itr1++;
		}
		for(int k = 0; k < j; k++)
		{
			itr2++;
		}
		temp = *itr1;
		*itr1 = *itr2;
		*itr2 = temp;
		itr1 = shuf_arr;
		itr2 = shuf_arr;
	}
	return shuf_arr;
}

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

int main()
{
	int size = 0;
	bool valid = false;
	while (!valid)
	{
		cout << "Please enter the size of the array: ";
		cin >> size;
		if (0 < size && size <= 52)
			valid = true;
	}
	//cout << "After while loop, size is: " << size << endl;
	int * arr = new int[size];
	//cout << "Before initialize_array" << endl;
	initialize_array(arr, size);
	//cout << "After initialize_array, before print_array" << endl;
	cout << "Original array is: ";
	print_array(arr, size);
	//cout << "After print_array" << endl;
	int * shuf_arr = shuffle_array(arr, size);
	cout << "Shuffled array is: ";
	print_array(shuf_arr, size);
	delete[] arr;
	delete[] shuf_arr;
	return 0;
}