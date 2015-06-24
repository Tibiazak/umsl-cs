#include <cstdlib>
#include <iostream>
using namespace std;

void initialize_array(int * arr, int size)
{
	for(int i = 0; i < size; i++)
	{
		arr[i] = i;
	}
}

int * shuffle_array(int * a, int b)
{
	
}

void print_array(int * arr, int size)
{
	cout << "[";
	for(int i = 0; i < size; i++)
	{
		cout << arr[i];
	}
	cout << "]" << endl;
}

int main()
{
	int size = 0;
	cout << "Please enter the size of the array: ";
	//cin
	cout << endl;
	int arr[size];
	initialize_array(arr, size);
	print_array(arr, size);
	int * shuf_arr = shuffle_array(arr, size);
	delete arr;
	delete shuf_arr;
	return 0;
}