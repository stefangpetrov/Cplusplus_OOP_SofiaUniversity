#pragma once
#include "CellRow.h"

class Table
{
private:
	Vector<CellRow> f_table;
	size_t biggestRowSize;
public:
	Table();
	void addRow( CellRow row);

	friend ostream& operator <<(ostream& out, const Table& table);
};

