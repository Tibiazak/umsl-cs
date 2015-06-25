#include <cstdlib>
#include <iostream>
#include <new>
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

/* 
int * shuffle_array(int * a, int b)
{
	
}
*/
void print_array(int * arr, int size)
{
	int * itr = arr;
	cout << "[" << endl;
	for(int i = 0; i < size; i++)
	{
		cout << *itr << endl;
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
		cout << endl;
		if (0 < size && size <= 52)
			valid = true;
	}
	cout << "After while loop, size is: " << size << endl;
	int * arr = new int[size];
	cout << "Before initialize_array" << endl;
	initialize_array(arr, size);
	cout << "After initialize_array, before print_array" << endl;
	print_array(arr, size);
	cout << "After print_array" << endl;
	//int * shuf_arr = shuffle_array(arr, size);
	delete[] arr;
	//delete shuf_arr;
	return 0;
}