using namespace std;
#include "delimStack.h"

delimStack::~delimStack()
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

void delimStack::push(delim d)
{
	stackNode *newNode = 0;
	newNode = new stackNode;
	newNode->value = d;

	if(isEmpty())
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

void delimStack::pop(delim &d)
{
	stackNode *temp = 0;

	if(isEmpty())
	{
		cout << "The stack is empty" << endl;
	}
	else
	{
		d = top->value;
		temp = top->next;
		delete top;
		top = temp;
	}
}

bool delimStack::isEmpty()
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