#include "Column.h"

void Column::addCell(const Cell& cell)
{
	f_column.to_end(cell);
}

size_t Column::getLength()
{
	return this->f_column.length();
}

void Column::setHeader(String header)
{
	f_header = header;
}

String Column::getHeader()
{
	return f_header;
}

const String Column::getType() const
{
	return f_type;
}

void Column::setType(String type)
{
	String dob = "double";
	String num = "int";
	String str = "string";
	String err = "ERROR";

	if (type == num || type == dob || type == str)
	{
		f_type = type;
	}
	else
	{
		type = err;
	}
	
}

const Cell Column::operator[](size_t i)
{
	return f_column[i];
}
