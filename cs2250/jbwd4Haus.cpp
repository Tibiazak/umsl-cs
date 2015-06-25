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
	int * itr = arr; //array iterator
	srand (time(NULL));
	int * shuf_arr = new int[size];
	int * shuf_itr = shuf_arr;
	int j = 0;

	for (int i = size-1; i >= 1; i--)
	{
		j = rand() % i+1;
		cout << j << endl; //debugging
		
		//shuffled array gets arr[j] in the arr[i]th position
		//shuf_arr[i] = arr[j]
		for(int k = 0; k < j; k++)
		{
			itr++;
		}
		for(int k = 0; k < i; k++)
		{
			shuf_itr++;
		}
		*shuf_itr = *itr;

		//shuffled array gets arr[i] in the arr[j]th position
		//shuf_arr[j] = arr[i]
		shuf_itr = shuf_arr;
		itr = arr;
		for(int k = 0; k < i; k++)
		{
			itr++;
		}
		for(int k = 0; k < j; k++)
		{
			shuf_itr++;
		}
		*shuf_itr = *itr;
	}
	return shuf_arr;
}

void print_array(int * arr, int size)
{
	int * itr = arr;
	cout << "Original array is: [";
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
	print_array(arr, size);
	//cout << "After print_array" << endl;
	int * shuf_arr = shuffle_array(arr, size);
	print_array(shuf_arr, size);
	delete[] arr;
	delete[] shuf_arr;
	return 0;
}