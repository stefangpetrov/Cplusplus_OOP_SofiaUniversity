#include "Cell.h"


Cell::Cell(String type, long intVal, double doubleVal, String stringVal) :
	f_intVal(intVal), f_doubleVal(doubleVal), f_stringVal(stringVal), f_type(type)
{}

String Cell::getType()
{
	return this->f_type;
}

long Cell::getIntVal()
{
	return f_intVal;
}

double Cell::getDoubleVal()
{
	return f_doubleVal;
}

String Cell::getStringVal()
{
	return f_stringVal;
}

ostream& operator<<(ostream& out, const Cell& cell)
{
	String str = "string";
	String dob = "double";
	String num = "number";
	
	if (str == cell.f_type)
	{
		out << cell.f_stringVal << endl;
	}
	else if (dob == cell.f_type)
	{
		out << cell.f_doubleVal << endl;
	}
	else if (num == cell.f_type)
	{
		out << cell.f_intVal << endl;
	}
	

	return out;
}
