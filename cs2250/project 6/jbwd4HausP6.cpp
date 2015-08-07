using namespace std;
#include <iostream>
#include <stack>
#include <string>
#include <time.h>
#include <stdlib.h>

int reverseInt(int n)
{
	int digit = n%10;
	cout << digit;
	if(n/10 == 0)
		return 0;
	else
	{
		reverseInt(n/10);
		return digit;
	}
}

string reverseString(string str)
{
	stack<char> strStack;

	for(int i = 0; i < str.length(); i++)
	{
		strStack.emplace(str[i]);
	}

	string reversed = str;
	for(int i = 0; i < str.length(); i++)
	{
		reversed[i] = strStack.top();
		strStack.pop();
	}

	return reversed;
}

void selecSort(int * arr, int size)
{
	if(size == 1)
	{
		return;
	}
	int largest = arr[0];
	int location = 0;
	for(int i = 1; i < size; i++)
	{
		if(arr[i] > largest)
		{
			largest = arr[i];
			location = i; 
		}
	}
	arr[location] = arr[size-1];
	arr[size-1] = largest;
	selecSort(arr, size-1);
}

void bubbleSort(int * arr, int size)
{
	if(size == 1)
	{
		return;
	}
	bool sorts = false;
	for(int i = 0; i < size-1; i++)
	{
		if(arr[i] > arr[i+1])
		{
			int temp = arr[i];
			arr[i] = arr[i+1];
			arr[i+1] = temp;
			sorts = true;
		}
	}
	if(!sorts)
	{
		return;
	}
	else
	{
		bubbleSort(arr, size-1);
	}
}

int main()
{
	srand(time(NULL));
	int n = 0;
	string str;

	cout << "Please enter an integer to be reversed: ";
	cin >> n;
	cin.ignore();
	reverseInt(n);
	cout << endl;

	cout << "Please enter a string to be reversed: ";
	getline(cin, str);
	str = reverseString(str);
	cout << str << endl;

	int arr [100];
	for (int i = 0; i < 100; i++)
	{
		arr[i] = rand() % 1000;
		cout << arr[i] << endl;
	}

	selecSort(arr, 100);
	for(int i = 0; i < 100; i++)
	{
		cout << arr[i] << endl;
	}

	for (int i = 0; i < 100; i++)
	{
		arr[i] = rand()%1000;
		cout << arr[i] << endl;
	}
	bubbleSort(arr, 100);
	for(int i = 0; i < 100; i++)
	{
		cout << arr[i] << endl;
	}

	return 0;
}