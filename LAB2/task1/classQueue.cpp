// lab 2 task 1 class Queue cpp
#pragma once
#include "classQueue.h"


void Queue::show_all()
{
	PNODE node = HEAD->next;
	while (node != NULL)
	{
		printf(" %d ", node->val);
		node = node->next;
	}

	printf("\n");
}

Queue::Queue()
{
	PNODE _head = new NODE;
	if (_head == NULL) exit(-1);

	_head->val = 0;
	_head->next = NULL;
	HEAD = _head;
	LAST = HEAD;
}

// PUSH
Queue& Queue::operator ++ (int)
{
	PNODE node = new NODE;
	if (node == NULL) exit(-1);
	int val;
	printf("PUSH: ");
	while (1)
	{
		if (scanf("%d", &val) != 0)
			break;
		printf("unvalid input, try again\n");
		if (getchar());
	}
	
	node->val = val;
	node->next = NULL;

	LAST->next = node;
	LAST = node;

	return *this;
}

// POP
Queue& Queue::operator -- (int)
{
	PNODE memo = HEAD->next;
	if (memo == NULL)
	{
		printf("Q is empty\n");
	}
	else
	{
		HEAD->next = memo->next;
		delete memo;
		printf("POP\n");
		if (HEAD->next == NULL)
			LAST = HEAD;
	}

	return *this;
}

// 1 if NULL
int Queue::operator ! ()
{
	if (HEAD->next == NULL)
		return 1;
	else
		return 0;
}


//  increase 1
int operator ++ (Queue& Q)
{
	PNODE node = Q.getHEAD()->next;//->next;
	while (node != NULL)
	{
		node->val += 1;
		node = node->next;
	}

	return 0;
}

// decrease 1
int operator -- (Queue& Q)
{
	PNODE node = Q.getHEAD()->next;
	while (node != NULL)
	{
		node->val -= 1;
		node = node->next;
	}

	return 0;
}

// EOF