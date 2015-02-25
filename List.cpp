#include "List.h"
#include "Assignment.h"

List::List(Assignment data)
{
	node start;
	start.info = data;
	*head = start;
	*tail = start;

}