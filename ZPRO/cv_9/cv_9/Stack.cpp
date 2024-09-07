#include "stack.h"

Stack* createStack(int size)
{
	Stack* s = new Stack;
	if (!s)
	{
		return s;
	}
	s->capacity;
	s->sp = -1;
	s->data = new Data(size);
	return s;
}

void destroyStack(Stack*& s)
{
	delete[] s->data;
	delete s;
	s = nullptr;
}

void push(Stack* s, int d)
{
	if (!isFull(s))
	{
		s->sp++;
		s->data[s->sp] = d;
	}
	else
	{
		//
	}
}

void pop(Stack* s)
{
	if (!isEmpty(s))
	{
		s->sp--;
	}
	else
	{
		//
	}
}

Data top(Stack* s)
{
	return s->data[s->sp];
}

bool isEmpty(Stack* s)
{
	return (s->sp == -1);
	if (s->sp == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool isFull(Stack* s)
{
	return(s->sp == s->capacity - 1);
}

int getSize(Stack* s)
{
	return s->capacity;
}