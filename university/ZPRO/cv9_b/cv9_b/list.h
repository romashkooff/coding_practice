#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

#include "item.h"

struct List;

struct List 
{
	Item* first;
	Item* last;
	int itemCounter;
};

List* createList();

#endif // !ITEM_H_INCLUDED