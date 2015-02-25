#include "List.h"
#include "Assignment.h"

List::List(Assignment data)
{
	node start;
	start.info = data;
	*head = start;
	*tail = start;

}

void List::push_on(Assignment data)
{
	node *temp = tail->next;
	tail->prev = new node;
	tail->prev->info = data;
	tail->prev = tail;

}