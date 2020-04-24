#pragma once
#include "CellRow.h"

class Table
{
private:
	Vector<CellRow> f_table;
	size_t f_biggestRowSize;
	Vector<size_t> f_columnSizes;
public:
	Table();
	void addRow( CellRow row);
	void addCellsWhereNeeded();
	friend ostream& operator <<(ostream& out, const Table& table);

	void takeBiggestColumnSizes();
};

