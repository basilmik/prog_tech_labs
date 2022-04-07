// lab 2 task 1 class Queue header

#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;


typedef struct t_node
{
	int val;
	struct t_node* next;

} *PNODE, NODE;

class Queue
{
private:

	friend	int operator ++(Queue&);// prefix add 1 to each
	friend int operator --(Queue&);// prefix take 1 from each

	PNODE HEAD;
	PNODE LAST;

public:

	Queue();

	PNODE getHEAD() { return HEAD; };

	void show_all();

	Queue& operator ++(int);// postfix PUSH
	Queue& operator --(int);// postfix POP
	int operator !();// isEmpty

};

// EOF