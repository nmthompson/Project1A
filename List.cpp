#include "List.h"
#include "Assignment.h"

List::List(Assignment data)
{
	node start;
	start.info = data;
	*head = start;
	*tail = start;

}

List::List()
{
	head = NULL;
	tail = NULL;
}

void List::push_on(Assignment data)
{
	node *temp = new node;
	temp->info = data;
	temp->next = tail;
	temp->prev = NULL;
	temp = tail;
}

Assignment List::push_off()
{
	node *temp = head;
	head->prev = head;
	head->next = NULL;
	return temp->info;
}

void List::pop_on(Assignment data)
{
	node *temp = new node;
	temp->info = data;
	head->next = temp;
	temp->prev = head;
	head = temp;

}

Assignment List::pop_off()
{
	node *temp = tail;
	tail = tail->next;
	tail->prev = NULL;
	return temp->info;

}

bool List::isEmpty()
{
	if (head == NULL&&tail == NULL)
		return true;
	else
		return false;
}

void List::sort()
{
	node *temp = head;
	while (temp->prev != NULL)
	{
		if (temp->info.getAssignedDate() < temp->prev->info.getAssignedDate())
		{
			//swap values
		}
		temp = temp->prev;

		// There is no way that it is this simple. -KD
	}
}