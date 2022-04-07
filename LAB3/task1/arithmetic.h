// lab3 programming technology
#pragma once
#include <iostream>
#include "progression.h"

class arithmetic : public progression
{
	double a1; // first in progression
	double d; // difference

public:
	
		double sum(int n) override final { return (a1 + (a1 + (n - 1) * d)) * n / 2; }

	arithmetic(double _a1, double _d) { a1 = _a1; d = _d; }

	~arithmetic() { a1 = 0; d = 0; }

	void print_one() override { printf("a1 = %f d = %f\n", a1, d); }

	void file_output(FILE* _fp) override { fprintf(_fp, "arithmetic: a1 = %f d = %f\n", a1, d); }
};

// EOF