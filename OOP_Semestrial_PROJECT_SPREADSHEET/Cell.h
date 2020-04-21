#pragma once

#include <iostream>
#include <fstream>

#include "String.h"

using namespace std;
class Cell
{
private:
	String f_type;

	long f_intVal;
	double f_doubleVal;
	String f_stringVal;

public:
	Cell(String type = "string", long intVal = 0, double doubleVal = 0.00, String stringVal = "unknown");

	friend ostream& operator<<(ostream& out, const Cell& cell);

	String getType();

	long getIntVal();

	double getDoubleVal();

	String getStringVal();
};


