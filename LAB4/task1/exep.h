// lab 4 prog tech task 1

#pragma once
#include <iostream>

class Exeption
{
	char* exep;
public:

	Exeption() { exep = nullptr; };

	void setExep(char* _mes) { exep = _mes; };

	char* getExep() { return exep; };

	void outExep() { std::cout << exep << std::endl; };
};

Exeption e;

//EOF