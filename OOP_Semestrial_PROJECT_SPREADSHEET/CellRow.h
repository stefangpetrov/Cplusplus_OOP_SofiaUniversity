#pragma once
#include "Cell.h"
#include "vector.cpp"

class CellRow
{
private:

	Vector<Cell> f_row;

public:
	
	void addCell(const Cell& cell);
	size_t getLength();
	void print();

	friend ostream& operator <<(ostream& out, const CellRow& row);
};

