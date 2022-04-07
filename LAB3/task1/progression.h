// lab3 programming technology
#pragma once
#include <iostream>

class progression
{
public:

	static int size;

	virtual double sum(int n) = 0;

	virtual void print_one() = 0;

	virtual void file_output(FILE*) = 0;

	progression() {};
};

int progression::size = 0;

// EOF