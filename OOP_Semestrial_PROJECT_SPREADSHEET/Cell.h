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

public:
	Cell();

	friend ostream& operator<<(ostream& out, const Cell& cell);

	const String getType() const;
	void setNewVal(String type, String value);

	const String getValue() const;

	
};


