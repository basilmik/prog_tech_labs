#include "parent.h"

#include <iostream>

parentQ* parentQ::LHEAD = NULL;
parentQ* parentQ::LLAST = NULL;
int parentQ::LSIZE = 0;


parentQ::parentQ()
{
	PNODE new_head = new NODE;
	if (new_head == NULL)
		exit(-1);

	QHEAD = new_head; // Q's HEAD

	QHEAD->val = 0;
	QHEAD->next = NULL;

	QLAST = QHEAD; // Q's LAST
	QSIZE = 0;

	LSIZE++;

	if (LHEAD == NULL)
		LHEAD = this;
	else
		LLAST->LNEXT = this;

	LLAST = this;
	LNEXT = NULL;
}

void parentQ::push() // add to q
{
	printf("push\n enter value: ");
	PNODE newNode = new NODE;
	if (newNode == NULL)
		exit(-1);

	int val = 0;
	while (1) {
	if (scanf("%d", &val) == 0)
		printf("invalid input, try again\n");
	else
		break;
	getchar();
	}

	newNode->val = val;
	newNode->next = NULL;

	QLAST->next = newNode;
	QLAST = newNode;

	QSIZE++;
}

parentQ* parentQ::pop() // take first from q
{
	PNODE memo = QHEAD->next;

	QHEAD->next = memo->next;
	delete memo;

	QSIZE--;
	if (QSIZE == 0)
	{
		parentQ* prev = LHEAD;
		if (prev == this)
		{
			if (LSIZE == 1)
			{
				printf("no q's left! exiting programm\n");
				delete this;
				return NULL;
			}

			parentQ* memo = LHEAD->LNEXT;
			delete this;
			LHEAD = memo;
		}
		else 
		{
			while (prev->LNEXT != this)
			{
				prev = prev->LNEXT;
			}
			parentQ* memo = this->LNEXT;
			delete this;
			prev->LNEXT = memo;
		}
		printf("this q was all poped, deleted from list of q's\n");
		LSIZE--;
		return LHEAD;
	}
	else
		printf("\tpoped! size = %d\n", QSIZE);
	
	return this;
}



void parentQ::printQ()
{
	PNODE parent = QHEAD->next;

	while (parent != NULL)
	{
		printf(" '%d' ", parent->val);
		parent = parent->next;
	}
	printf("\n");
}
 
void parentQ::show_list()
{
	parentQ* parent = LHEAD;
	int count = 1;
	printf("\tshow-list-of-q's\n");
	if (LSIZE == 1 && QSIZE == 0)
		printf("there's one empty q\n");
	else
	while (parent != NULL)
	{
		printf("\n%d) ", count);
		parent->printQ();
		
		count++;
		parent = parent->LNEXT;
	}
}


parentQ* parentQ::pickQ()
{
	printf("pick-a-q\nthere are %d q's\n", LSIZE);
	show_list();

	int val;
	printf("\nenter q's number: ");
	while (1)
	{
		if (scanf("%d", &val) == 0 || val <= 0 || val > LSIZE)
			printf("invalid input, try again\n");
		else
			break;
		getchar();
	}

	parentQ* cur = LHEAD;

	for (int i = 1; i < val; i++)
		cur = cur->LNEXT;
	
	return cur;
}

void parentQ::copyQ(parentQ* cpyQ)
{
	PNODE src = QHEAD->next;
	PNODE* cpy = cpyQ->get_QLAST();
	int* cpy_QSIZE = cpyQ->get_QSIZE_PTR();

	while (src != NULL)
	{
		PNODE new_node = new NODE;
		if (new_node == NULL)
			exit(-1);

		new_node->val = src->val;
		new_node->next = NULL;
		(*cpy)->next = new_node;
		(*cpy) = new_node;

		(*cpy_QSIZE)++;

		src = src->next;
	}
	printf("q is copied\n");
}

void parentQ::emergeQ(parentQ* emQ)
{
	printf("pick a q to emerge current with\nthere are %d q's\n", LSIZE-1);
	show_list();
	printf("is the new q\n");

	int val; printf("enter q's number: ");
	while (1) {
		if (scanf("%d", &val) == 0 || val <= 0 || val >= LSIZE)
			printf("invalid input, try again\n");
		else
			break;
		getchar();
	}
	parentQ* src2L = LHEAD;
	for (int i = 1; i < val; i++)
		src2L = src2L->LNEXT;


	PNODE src = QHEAD->next;

	PNODE* em = emQ->get_QLAST();
	int* em_QSIZE = emQ->get_QSIZE_PTR();

	while (src != NULL)
	{
		PNODE new_node = new NODE;
		if (new_node == NULL)
			exit(-1);

		new_node->val = src->val;
		new_node->next = NULL;
		(*em)->next = new_node;
		(*em) = new_node;

		(*em_QSIZE)++;

		src = src->next;
	}


	PNODE src2 = src2L->get_QHEAD()->next;
	while (src2 != NULL)
	{
		PNODE new_node = new NODE;
		if (new_node == NULL)
			exit(-1);

		new_node->val = src2->val;
		new_node->next = NULL;
		(*em)->next = new_node;
		(*em) = new_node;

		(*em_QSIZE)++;

		src2 = src2->next;
	}
	printf("emerged\n");
}

PNODE parentQ::get_QHEAD()
{
	return QHEAD;
}

PNODE* parentQ::get_QLAST()
{
	return &QLAST;
}

int* parentQ::get_QSIZE_PTR()
{
	return &QSIZE;
}


// EOF