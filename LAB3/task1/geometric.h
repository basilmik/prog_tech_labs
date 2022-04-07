// lab3 programming technology
#pragma once
#include <iostream>
#include "progression.h"

class geometric : public progression
{
	double a1; // first in progression
	double q; // Coefficient
public:
	
	double sum(int n) override
	{
		if (q == 1)
			return n * a1;
		else
			return (a1 * (1 - pow(q, n)) / (1 - q));
	}

	geometric(double _a1, double _q) {	a1 = _a1; q = _q; }

	~geometric() { a1 = 0; q = 0; }

	void print_one() override { printf("a1 = %f q = %f\n", a1, q); }

	void file_output(FILE* _fp) override { fprintf(_fp, "geometric: a1 = %f q = %f\n", a1, q); }
};

// EOF