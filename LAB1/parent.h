#pragma once
#define _CRT_SECURE_NO_WARNINGS
typedef struct t_node
{
	int val;
	struct t_node* next;

} NODE, * PNODE;

class parentQ
{
	// list of q's
	static class parentQ* LHEAD;
	static class parentQ* LLAST;
	static int LSIZE;

	class parentQ* LNEXT;

	// queue info
	int QSIZE;
	PNODE QHEAD;
	PNODE QLAST;

protected:
	parentQ* pop();
	void push();

public:
	parentQ();

	void printQ();
	void show_list();
	parentQ* pickQ();
	void copyQ(parentQ*);
	void emergeQ(parentQ*);

	PNODE get_QHEAD();
	PNODE* get_QLAST();
	int* get_QSIZE_PTR();

};


// EOF