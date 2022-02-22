#include "parent.h"
#include <iostream>

class pubQ : public parentQ
{

public:
	void pub_push();
	pubQ* pub_pop();
	void pub_calc();

};
