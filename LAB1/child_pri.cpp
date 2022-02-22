#include "child_pri.h"

#include <iostream>

void priQ::pub_push()
{
	parentQ::push();
}

priQ* priQ::pub_pop()
{
	return (priQ*)parentQ::pop();
}

void priQ::pub_calc()
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
