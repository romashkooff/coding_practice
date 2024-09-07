#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

typedef int Data;

struct Stack;

Stack* createStack(int size);

void destroyStack(Stack *&s);

void push(Stack* s, int d);

void pop(Stack* s);

Data top(Stack* s);

bool isEmpty(Stack* s);

bool isFull(Stack* s);

int getSize(Stack* s);
#endif