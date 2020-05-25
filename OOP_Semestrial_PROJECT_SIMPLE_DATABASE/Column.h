#pragma once
#include "Cell.h"
#include "Vector.cpp"

class Column
{
private:
	String f_type;
	Vector<Cell> f_column;
	String f_header;

public:
	void addCell(const Cell& cell);
	size_t getLength();


	void setHeader(String header);
	String getHeader();

	const String getType() const;
	void setType(String type);
	Cell& operator[](size_t i);

	
};

