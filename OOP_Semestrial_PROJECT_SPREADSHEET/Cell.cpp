#include "Cell.h"


Cell::Cell()
{
	setNewVal(String("string"), String(""));
}



const String Cell::getType() const
{
	return this->f_type;
}

void Cell::setNewVal(String type, String value) 
{
	f_type = type;
	f_value = value;
}

const String Cell::getValue() const
{
	return f_value;
}



ostream& operator<<(ostream& out, const Cell& cell)
{
	out << cell.f_value;
	return out;
}

