// lab 4 prog tech task 1
#pragma once

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

void myCin(char** _s)
{
	char buf[4096];
	while (true)
	{
		std::cin >> buf;

		if (std::cin.good())
		{
			*_s = new char[strlen(buf) + 1];
			strcpy(*_s, buf);
			break;
		}
		std::cout << "wrong type, try again\n" << std::endl;
		std::cin.clear();
		std::cin.ignore();
	}
}


template <typename T>
void show(T& _arr, int _size)
{
	for (int i = 0; i < _size; i++)
	{
		std::cout << _arr[i] << "  ";
	}
	printf("\n");
}

void show(char** _arr, int _size)
{
	for (int i = 0; i < _size; i++)
	{
		std::cout << _arr[i] << "  ";
	}
	printf("\n");
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

template <>
int compar<char*>(char* _x, char* _y)
{
	return (strcmp(_x, _y));
}

// EOF