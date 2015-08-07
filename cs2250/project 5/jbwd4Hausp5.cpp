#include "delimStack.h"
#include <iostream>
#include <string>
using namespace std;

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

	delimStack stack;

	string str;
	int line = 0;
	while(str != "DONE")
	{
		getline(cin, str);
		line++;
		for (int i = 0; i < str.length(); i++)
		{
			if (isLdelim(str[i]))
			{
				stack.push(str[i], line, i);
			}
			else if (isRDelim(str[i]))
			{
				char delim;
				int lastLine;
				int lastCount;
				if(stack.isEmpty())
				{
					cout << "Right delimeter " << str[i] << "had not left delimeter found at line " << line <<
					"char " << i << endl;
				}
				else
				{
					stack.pop(delim, lastLine, lastCount);
				}
				if(!delimMatch(delim, str[i]))
				{
					cout << "Mismatched delimeter" << delim << "found at line " << lastLine <<
					"char " << lastCount << "does not match " << str[i] << "found at line " << line <<
					"char " << i << endl;
				}
			}
		}
	}
	if(!stack.isEmpty())
	{
		while(!stack.isEmpty())
		{
			char delim;
			int lastLine;
			int lastcount;
			stack.pop(delim, lastLine, lastcount);
			cout << "Left delimeter " << delim << "at line " << lastLine << ", char " << lastCount <<
			"had no right delimeter." << endl;
		}
	}
}