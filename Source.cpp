#include <iostream>
#include <exception>;
#include <stdexcept>;
#include "Bad_exception.h"
#include "Triangle.h"

using namespace std;
int main()
{
	Triangle a(3, 4);
	Triangle b(4, 5);

	try {
		cout << "a++" << endl;
		cout << a++ << endl;
	}
	catch(bad_exception& e)
	{
		cerr << e.what() << endl;
	}

	try {
		cout << "a--" << endl;
		cout << a-- << endl;
	}
	catch (bad_exception& e)
	{
		cerr << e.what() << endl;
	}

	try {
		cout << "--a" << endl;
		cout << --a << endl;
	}
	catch (bad_exception& e)
	{
		cerr << e.what() << endl;
	}



	try {
		cout << "++a" << endl;
		cout << ++a << endl;
	}
	catch (bad_exception& e)
	{
		cerr << e.what() << endl;
	}


	cout << "a = b"<< endl;
	a = b;
	cout << a << endl;

	Triangle c;

	cout << "Enter legs ->" << endl << endl;
	cin >> c;

	cout << "hypotenuse = " << c.hypotenuse() << endl;

}