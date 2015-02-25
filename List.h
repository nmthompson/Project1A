#pragma once
#include "Assignment.h"

struct node
{
	node* next;
	node* prev;
	Assignment info;
};

class List
{
public:
	List(Assignment data);
	List();
	void push_on(Assignment data); // add to back
	Assignment push_off(); // remove from front, return what was removed
	void pop_on(Assignment data); // add to front
	Assignment pop_off(); // remove from back, return what was removed
	void sort(); // Sorts the list by accending order, using the assigned date value from the assignment class
	bool isEmpty(); // Checks if the list is empty;
private:
	node* head;
	node* tail;
};