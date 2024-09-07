#include <iostream>
#include "stack.h"

using namespace std;

struct Stack
{
	int capacity;
	int sp;
	Data* data;
};

int main()
{
	Stack* st;
	int i = 1;
	int N;
	cout << "Prosim zadejte kapacitu zasobniku: ";
	cin >> N;
	st = createStack(N);
	if (!st)
	{
		cerr << "Vytvoreni zasobniku sselhalo" << endl;
		return -1;
	}

	/*
	st->capacity = 2;
	st->data[2] = 10;
	st->sp = 51;
	st->data = nullptr;
	*/

	while (!isFull(st))
	{
		push(st, i);
		i++;
	}
	while (!isEmpty(st))
	{
		cout << top(st) << " ";
	}
	destroyStack(st);
	// push(st, 5);
}