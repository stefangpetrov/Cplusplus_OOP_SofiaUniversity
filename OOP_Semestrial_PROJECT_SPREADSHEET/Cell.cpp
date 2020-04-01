#include "Cell.h"
#include <cstring>


Cell::Cell(const char* type, long intVal, double doubleVal, const char* stringVal):
	f_intVal(intVal), f_doubleVal(doubleVal)
{
	if (type)
	{
		f_type = new char[strlen(type) + 1];
		strcpy(f_type, type);
	}
	else
	{
		f_type = new char[strlen("string") + 1];
		strcpy(f_type, "string");
	}

	if (stringVal)
	{
		f_stringVal = new char[strlen(stringVal) + 1];
		strcpy(f_stringVal, stringVal);
	}
	else
	{
		f_stringVal = new char[strlen("") + 1];
		strcpy(f_stringVal, "");
	}
	
}

Cell::Cell(const Cell& other)
{

	if (this != &other)
	{
		f_intVal = other.f_intVal;
		f_doubleVal = other.f_doubleVal;

		strcpy(f_stringVal, other.f_stringVal);
		strcpy(f_type, other.f_type);
	}
}

Cell& Cell::operator=(const Cell& other)
{
	if (this != &other)
	{
		delete[] f_stringVal;
		delete[] f_type;

		f_intVal = other.f_intVal;
		f_doubleVal = other.f_doubleVal;

		strcpy(f_stringVal, other.f_stringVal);
		strcpy(f_type, other.f_type);
	}

	return *this;
}

Cell::~Cell()
{
	delete[] f_stringVal;
	delete[] f_type;
}
