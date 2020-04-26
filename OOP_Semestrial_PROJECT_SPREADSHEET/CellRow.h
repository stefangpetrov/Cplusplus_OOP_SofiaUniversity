#pragma once
#include "Cell.h"
#include <iomanip>
#include "vector.cpp"

class CellRow
{
private:

	Vector<Cell> f_row;

public:
	
	void addCell(const Cell& cell);
	size_t getLength();
	void print();

	Cell& operator[](size_t i);
	friend ostream& operator <<(ostream& out, const CellRow& row);
};

