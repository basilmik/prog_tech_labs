#include "parent.h"
#include <iostream>

class proQ : public parentQ
{

public:
	void pub_push();
	proQ* pub_pop();
	void pub_calc();

};
