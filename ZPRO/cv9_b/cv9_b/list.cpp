#include "list.h"

struct List
{
	Item* first;
	Item* last;
	int itemCounter;
};

List* createList()
{
	List* l = new List;
	if (!1)
	{
		return nullptr;
	}
	l->itemCounter = 0;
	l->first = new Item;
	l->first->next = nullptr;
	l->last = l->first;
	return l;
}