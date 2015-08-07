/*
Joshua Bearden
CS2250
A program to show my understanding of recursion
and STL stacks
*/

using namespace std;
#include <iostream>
#include <stack>
#include <string>
#include <time.h>
#include <stdlib.h>


//A function to reverse an int
int reverseInt(int n)
{
	//Gets the last digit
	int digit = n%10;
	cout << digit;

	//If there are no more digits, return
	if(n/10 == 0)
		return 0;
	//Otherwise, call the function on the remaining digits
	else
	{
		reverseInt(n/10);
		return digit;
	}
}

//A function to reverse a string using a stack
string reverseString(string str)
{
	//Making a stack
	stack<char> strStack;

	//Adding each character in the string to the stack
	for(int i = 0; i < str.length(); i++)
	{
		strStack.emplace(str[i]);
	}

	//Making a string and initializing it to the original string
	//for simplicity
	string reversed = str;
	
	//Creating a new string by taking the top element of the stack
	//and adding it to the string in order, which reverses the
	//character order, because stacks are LIFO.
	for(int i = 0; i < str.length(); i++)
	{
		reversed[i] = strStack.top();
		strStack.pop();
	}

	return reversed;
}

//A recursive selection sort
void selecSort(int * arr, int size)
{
	//base case, if the size is 1, return, it's sorted
	if(size == 1)
	{
		return;
	}

	//an int to hold the largest value, as temp storage
	//and an int to hold the location of the largest value
	//for purposes of the swap
	int largest = arr[0];
	int location = 0;

	//getting the largest value in the array up to the given size
	//and its location
	for(int i = 1; i < size; i++)
	{
		if(arr[i] > largest)
		{
			largest = arr[i];
			location = i; 
		}
	}
	//now that location is the index of the largest value,
	//and largest is the largest value, swap the last element
	//in the array with the element stored in location.
	arr[location] = arr[size-1];
	arr[size-1] = largest;

	//because after the swap, the last element in the array is
	//sorted, call the function on the array minus the last element
	selecSort(arr, size-1);
}

//A recursive bubble sort
void bubbleSort(int * arr, int size)
{
	//base case, if the size is 1, return, it's sorted
	if(size == 1)
	{
		return;
	}

	//A boolean stating whether a swap has occurred,
	//initializes to false
	bool sorts = false;

	for(int i = 0; i < size-1; i++)
	{
		//Swap two adjoining elements if the one on the left
		//is larger than on the right
		if(arr[i] > arr[i+1])
		{
			int temp = arr[i];
			arr[i] = arr[i+1];
			arr[i+1] = temp;
			sorts = true; //set sorts to true, showing a swap occurred
		}
	}

	//if no swaps, array is sorted, return
	if(!sorts)
	{
		return;
	}
	//otherwise, call the function again minus the last element, which
	//is, by definition, in its final position because I am sorting from
	//left to right.
	else
	{
		bubbleSort(arr, size-1);
	}
}

int main()
{
	srand(time(NULL)); //initialize the random number generator

	int n = 0;
	string str;

	//Get an integer for reversal and call reverseInt on it
	cout << "Please enter an integer to be reversed: ";
	cin >> n;
	cin.ignore(); //clears the buffer so that getline will work properly
	reverseInt(n);
	cout << endl;

	//Get a string for reversal and call reverseString on it
	cout << "Please enter a string to be reversed: ";
	getline(cin, str);
	str = reverseString(str);
	cout << str << endl;

	//Creates an array of 100 ints and fills it with random numbers
	int arr [100];
	cout << "An unsorted array of 100 ints" << endl;
	for (int i = 0; i < 100; i++)
	{
		arr[i] = rand() % 1000;
		cout << arr[i] << endl;
	}

	//Sorts the array and outputs the resulting array
	selecSort(arr, 100);
	cout << "A sorted array of 100 ints" << endl;
	for(int i = 0; i < 100; i++)
	{
		cout << arr[i] << endl;
	}

	//Refills the array with 100 different random ints
	cout << "An unsorted array of 100 ints" << endl;
	for (int i = 0; i < 100; i++)
	{
		arr[i] = rand()%1000;
		cout << arr[i] << endl;
	}

	//Sorts the array and outputs the result
	bubbleSort(arr, 100);
	cout << "A sorted array of 100 ints" << endl;
	for(int i = 0; i < 100; i++)
	{
		cout << arr[i] << endl;
	}

	return 0;
}