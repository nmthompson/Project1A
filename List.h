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
	void add(Assignment data);
	Assignment remove(Assignment data);
	void sort();
private:
	node* head;
	node* tail;
};