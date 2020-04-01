#pragma once
#pragma warning(disable:4996)
#include <iostream>
#include <cstring>
using namespace std;

class Cell
{
private:
	char* f_type;//"double"

	long f_intVal;
	double f_doubleVal;
	char* f_stringVal;

public:
	Cell(const char* type = "string", long intVal = 0, double doubleVal = 0.00, const char* stringVal = "");

	Cell(const Cell& other);


	Cell& operator=(const Cell& other);

	~Cell();

};

