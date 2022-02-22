#include "child_pub.h"

#include <iostream>

void pubQ::pub_push()
{
	parentQ::push();
}

pubQ* pubQ::pub_pop()
{
	return (pubQ*) parentQ::pop();
}

void pubQ::pub_calc()
{
	PNODE parent = get_QHEAD()->next;
	int min = parent->val;
	while (parent != NULL)
	{
		if (parent->val < min) min = parent->val;
		parent = parent->next;
	}

	printf("min = %d\n", min);

}
