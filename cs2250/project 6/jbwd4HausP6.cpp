using namespace std;
#include <iostream>
#include <stack>
#include <string>

int reverseInt(int n)
{
	int digit = n%10;
	cout << digit;
	reverseInt(n/10);
	if(n/10 == 0)
		return 0;
	else
		return digit;
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

int main()
{
	string str = "Hello";
	string rts = reverseString(str);
	cout << str << " " << rts << endl;

	int arr [6] = {10, 9, 8, 7, 6, 5};
	selecSort(arr, 6);
	for(int i = 0; i < 6; i++)
	{
		cout << arr[i] << endl;
	}

	reverseInt(2536);
	return 0;
}