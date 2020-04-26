#pragma once
#include "CellRow.h"

class Table
{
private:
	Vector<CellRow> f_table;
	size_t f_biggestRowSize;
	Vector<short> f_columnSizes;
public:
	Table();
	Table(const Table& other);
	Table& operator=(const Table& other);
	void addRow( CellRow row);
	void addCellsWhereNeeded();
	friend ostream& operator <<(ostream& out, const Table& table);

	bool signalMistakes();

	void takeBiggestColumnSizes();
};

