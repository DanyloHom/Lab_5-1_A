#pragma once
#include <iostream>
#include <string>

using namespace std;

class Bad_exception
{
	string message;
public:
	Bad_exception(string msg) : message(msg) {}
	string what() { return message; }
};

