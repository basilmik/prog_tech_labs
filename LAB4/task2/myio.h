// lab 4 prog tech task 2

#include <iostream>
#include <istream>
#include <ostream>
#include "stdio.h"
#include "exep.h"

using namespace std;

template <typename T>
void myCin(T& _s)
{
	while (true)
	{
		std::cin >> _s;
		if (std::cin.good())
		{
			break;
		}
		std::cout << "wrong type, try again\n" << std::endl;
		std::cin.clear();
		std::cin.ignore();
	}
}

template <typename T>
void myCin(std::istream& is, T& _s)
{
	while (true)
	{
		is >> *_s;
		if (is.good())
		{
			break;
		}
		std::cout << "wrong type, try again\n" << std::endl;
		is.clear();
		is.ignore();
	}
}

void myCin(std::istream& is, char** _s)
{
	char buf[4096];
	while (true)
	{
		is >> buf;

		if (is.good())
		{
			*_s = new char[strlen(buf) + 1];
			strcpy(*_s, buf);
			break;
		}
		std::cout << "wrong type, try again\n" << std::endl;
		is.clear();
		is.ignore();
	}
}

template <typename T>
void myCout(ostream& os, T _s)
{
	os << *_s;
}

void myCout(ostream& os, char** _s)
{
	os << *_s;
}


template <typename T1, typename T2>
int compar(T1 _x, T2 _y)
{
	if (_x == _y)
		return 0;
	if (_x < _y)
		return 1;
	if (_x > _y)
		return -1;
}

int compar(char* _x, char* _y)
{
	return (strcmp(_x, _y));
}

//EOF