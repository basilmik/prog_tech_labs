// lab 2 task 2 class Point header
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ostream>
#include <istream>

using namespace std;

class Point
{
	friend int operator -(Point&, Point&);
	friend int operator -(Point&, int);
	friend int operator -(int, Point&);

	friend bool operator ==(Point& _p1, Point& _p2) { return (_p1.x == _p2.x && _p1.y == _p2.y && _p1.z == _p2.z); };
	friend bool operator !=(Point& _p1, Point& _p2) { return (_p1.x != _p2.x && _p1.y != _p2.y && _p1.z != _p2.z); };
	friend bool operator >(Point& _p1, Point& _p2) { return (_p1.x > _p2.x && _p1.y > _p2.y && _p1.z > _p2.z); };
	friend bool operator >=(Point& _p1, Point& _p2) { return (_p1.x >= _p2.x && _p1.y >= _p2.y && _p1.z >= _p2.z); };
	friend bool operator <(Point& _p1, Point& _p2) { return (_p1.x < _p2.x && _p1.y < _p2.y && _p1.z < _p2.z); };
	friend bool operator <=(Point& _p1, Point& _p2) { return (_p1.x <= _p2.x && _p1.y <= _p2.y && _p1.z <= _p2.z); };

	friend ostream& operator<<(ostream& os, Point& _p);
	friend istream& operator>>(istream& is, Point& _p);

	int x, y, z;

public:

	Point() { x = y = z = 0; };

	Point& operator +(Point& _p2);
	Point& operator +(int _val);

	int getX() { return x; };
	int getY() { return y; };
	int getZ() { return z; };
};


// EOF