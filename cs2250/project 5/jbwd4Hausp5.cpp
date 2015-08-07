/*
Joshua Bearden
CS2250
A program to test a program using a stack
*/

#include "delimStack.h"
#include <iostream>
#include <string>
using namespace std;

//checks to see if the char is a left delimeter
bool isLDelim(char c)
{
	if((c == '(') || (c == '[') || (c == '{'))
	{
		return true;
	}
	else
	{
		return false;
	}
}

//checks to see if the char is a right delimeter
bool isRDelim(char c)
{
	if((c == ')') || (c == ']') || (c == '}'))
	{
		return true;
	}
	else
	{
		return false;
	}
}

//checks to see if two delimeters match
bool delimMatch(char c, char d)
{
	if (((c == '(') && (d == ')')) || ((c == '{') && (d == '}')) || ((c == '[') && (d == ']')))
	{
		return true;
	}
	else
	{
		return false;
	}
}


int main()
{
	cout << "Please enter your text, type DONE when you are finished." << endl;

	delimStack stack; //initializes the stack

	string str;
	int line = 0;

	//loops until the signal "DONE"
	while(str != "DONE")
	{
		getline(cin, str); //gets the line
		line++;
		for (int i = 0; i < str.length(); i++) //checks all the chars in the string
		{
			if (isLDelim(str[i])) //checks if it is a left delimeter, and adds to the stack if it is
			{
				stack.push(str[i], line, i);
			}
			else if (isRDelim(str[i])) //checksif it is a right delimeter and pops the stack if it is
			{
				char delim;
				int lastLine;
				int lastCount;
				if(stack.isEmpty()) //makes sure the stack is not empty, errors if it is
				{
					cout << "Right delimeter " << str[i] << " had not left delimeter found at line " << line <<
					" char " << i << endl;
				}
				else
				{
					stack.pop(delim, lastLine, lastCount);
				}
				if(!delimMatch(delim, str[i])) //checks to see if the delimeters match, errors if not
				{
					cout << "Mismatched delimeter " << delim << " found at line " << lastLine <<
					" char " << lastCount << " does not match " << str[i] << " found at line " << line <<
					" char " << i << endl;
				}
			}
		}
	}
	if(!stack.isEmpty()) //after the input is finished, makes sure stack is empty, pops if not
	{
		while(!stack.isEmpty())
		{
			char delim;
			int lastLine;
			int lastcount;
			stack.pop(delim, lastLine, lastcount);
			cout << "Left delimeter " << delim << " at line " << lastLine << ", char " << lastcount <<
			" had no right delimeter." << endl;
		}
	}
}