// lab 2 task 2 class Point methods defenition

#include "classPoint.h"

Point& Point:: operator + (Point& _p2)
{
	x += _p2.x;
	y += _p2.y;
	z += _p2.z;

	return *this;
}

Point& Point:: operator + (int _val)
{
	x += _val;
	y += _val;
	z += _val;

	return *this;
}

int operator - (Point& _p1, Point& _p2)
{
	_p1.x -= _p2.x;
	_p1.y -= _p2.y;
	_p1.z -= _p2.z;
	return 0;
}

int operator - (Point& _p1, int _val)
{
	_p1.x -= _val;
	_p1.y -= _val;
	_p1.z -= _val;
	return 0;
}

int operator - (int _val, Point& _p1)
{
	_p1.x = _val - _p1.x;
	_p1.y = _val - _p1.y;
	_p1.z = _val - _p1.z;
	return 0;
}


ostream& operator<<(ostream& os, Point& _p)
{
	return os << '(' << _p.x << ';' << _p.y << ';' << _p.z << ')' << endl;
}

istream& operator>>(istream& is, Point& _p)
{
	cout << "x: "; is >> _p.x;
	cout << "y: "; is >> _p.y;
	cout << "z: "; return is >> _p.z;
}

// EOF