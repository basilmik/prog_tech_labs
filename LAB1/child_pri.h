#include "parent.h"
#include <iostream>

class priQ : public parentQ
{

public:
	void pub_push();
	priQ* pub_pop();
	void pub_calc();

};
