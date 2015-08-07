using namespace std;
#include "delimStack.h"
#include <iostream>

delimStack::~delimStack() //destructor, deletes every node in the stack
{
	stackNode *nodePtr = 0, *nextNode = 0;
	nodePtr = top;
	while (nodePtr != 0)
	{
		nextNode = nodePtr->next;
		delete nodePtr;
		nodePtr = nextNode;
	}
}

void delimStack::push(char c, int line, int count) //adds a node to the stack
{
	stackNode *newNode = 0;
	newNode = new stackNode;
	newNode->value.c = c;
	newNode->value.line = line;
	newNode->value.charCount = count;

	if(isEmpty()) //if stack is empty, just make it the new top, else add it to the last node
	{
		top = newNode;
		newNode->next = 0;
	}
	else
	{
		newNode->next = top;
		top = newNode;
	}
}

void delimStack::pop(char & c, int & line, int & count) //pops a node from the stack, returns values
{
	stackNode *temp = 0;

	if(isEmpty())
	{
		cout << "The stack is empty" << endl;
	}
	else
	{
		c = top->value.c;
		line = top->value.line;
		count = top->value.charCount;
		temp = top->next;
		delete top;
		top = temp;
	}
}

bool delimStack::isEmpty() //checks if the stack is empty
{
	bool status;

	if(!top)
	{
		status = true;
	}
	else
	{
		status = false;
	}

	return status;
}