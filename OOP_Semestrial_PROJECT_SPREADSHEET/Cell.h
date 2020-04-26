#pragma once

#include <iostream>
#include <fstream>

#include "String.h"

using namespace std;
class Cell
{
private:
	String f_type;
	String f_value;

	int f_intValue;
	double f_doubleValue;

public:
	Cell();
	Cell(String value);
	friend ostream& operator<<(ostream& out, const Cell& cell);

	const String getType() const;
	void setNewVal(String type, String value);

	void setNewVal(String type, String value, double doubleVal);
	void setNewVal(String type, String value, int intVal);

	const int getLength() const;



	const String getValue() const;

	void setValue(String newValue);
};


