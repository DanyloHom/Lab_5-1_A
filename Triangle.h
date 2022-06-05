#pragma once
#include <string>
#include <sstream>
#include "Bad_exception.h"

using namespace std;

class Triangle
{
private:
	double first;
	double second;
public:

	Triangle();
	Triangle(double l, double r);
	Triangle(const Triangle&);

	double getFirst() const { return first; }
	double getSecond() const { return second; }
	void setFirst(double value) { first = value; }
	void setSecond(double value) { second = value; }

	operator string() const;
	friend ostream& operator << (ostream&, const Triangle&);
	friend istream& operator >> (istream&, Triangle&);

	Triangle& operator = (const Triangle& t);
	Triangle& operator ++();
	Triangle& operator --();
	Triangle operator ++(int);
	Triangle operator --(int);

	double hypotenuse();

};




