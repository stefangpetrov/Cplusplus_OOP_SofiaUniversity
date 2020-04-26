#pragma once
#include "Column.h"

class Table
{
private:
	String f_name;
	Vector<Column> f_table;
	
	Vector<size_t> f_columnSizes;
public:

	void addColumn(Column column);
	
	friend ostream& operator <<(ostream& out, const Table& table);

	void setName(String name);
	const String getName() const;

	size_t getLength();

	Column& operator [](size_t i);

	int countRowsWithAValue(int col, String value);

	void takeBiggestColumnSizes();

	void printAllRowsWithValueInCol(int col, String value);
};

