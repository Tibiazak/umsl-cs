#ifndef DELIMSTACK_H
#define DELIMSTACK_H

using namespace std;

class delimStack
{
	private:
		struct delim
		{
			char c;
			int line;
			int charCount;
		};


		struct stackNode
		{
			delim value;
			stackNode *next;
		};
		stackNode *top;
	public:
		delimStack()
			{top = 0;}
		~delimStack();

		void push(char, int, int);
		void pop(char &, int&, int&);
		bool isEmpty();
};
#endif