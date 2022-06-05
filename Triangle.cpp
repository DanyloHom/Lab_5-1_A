#include "Triangle.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

Triangle::Triangle()		//konstr bez argumenta
{
	first = 0;
	second = 0;
}

Triangle::Triangle(double l, double r)		//konstr inicializacii
{
	if (r > 0 && l > 0) {
		first = l;
		second = r;
	}
	else
	{
		throw Bad_exception("Bad_Exception - Error!(arguments cannot = 0)");
		first = 0;
		second = 0;
	}
}

Triangle::Triangle(const Triangle& r)		//konstr kopiyuvannya
{
	first = r.first;
	second = r.second;
}



Triangle::operator string() const
{
	stringstream ss;
	ss << " first = " << first << endl;
	ss << " second = " << second << endl;
	return ss.str();
}

Triangle& Triangle::operator=(const Triangle& t)
{
	first = t.first;
	second = t.second;

	return *this;
}

Triangle& Triangle::operator++()
{

	int x = second +1;
	if (x > hypotenuse())
		throw Bad_exception("Bad_Exception - Error!(leg cannot > hypotenuse)");
	else second++;

	return *this;
}

Triangle& Triangle::operator--()
{
	int x = second - 1;
	if ((x + first) < hypotenuse())
		throw Bad_exception("Bad_Exception - Error!(sum of legs cannot < hypotenuse)");
	else second++;
	return *this;
}

Triangle Triangle::operator++(int)
{
	Triangle t(*this);
	int x = first+1;
	if (x > hypotenuse())
		throw Bad_exception("Bad_Exception - Error!(leg cannot > hypotenuse)");
	else first++;
	return t;
}

Triangle Triangle::operator--(int)
{
	Triangle t(*this);
	int x = first-1;
	if ((x + second) < hypotenuse())
		throw Bad_exception("Bad_Exception - Error!(sum of legs cannot < hypotenuse)");
	else first++;
	return t;
}

double Triangle::hypotenuse()
{
	return sqrt(pow(first, 2) + pow(second, 2));
}

ostream& operator<<(ostream& out, const Triangle& t)
{
	out << string(t);
	return out;
}

istream& operator>>(istream& in, Triangle& t)
{
	cout << " First = "; in >> t.first;
	cout << " Second = "; in >> t.second;
	cout << endl;
	return in;
}
