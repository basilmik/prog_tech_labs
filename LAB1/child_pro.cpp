#include "child_pro.h"

#include <iostream>

void proQ::pub_push()
{
	parentQ::push();
}

proQ* proQ::pub_pop()
{
	return (proQ*)parentQ::pop();
}

void proQ::pub_calc()
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
