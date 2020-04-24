#include "Table.h"

Table::Table()
{
	biggestRowSize = 0;
}

void Table::addRow(CellRow row)
{
	f_table.to_end(row);
	if (biggestRowSize < row.getLength())
	{
		biggestRowSize = row.getLength();
	}
}

void Table::addCellsWhereNeeded()
{
	
	for (size_t i = 0; i < f_table.length(); i++)
	{
		for (size_t j = f_table[i].getLength(); j < biggestRowSize; j++)
		{
			Cell emptyCell;
			f_table[i].addCell(emptyCell);
		}
	}
}

ostream& operator<<(ostream& out, const Table& table)
{
	for (size_t i = 0; i < table.f_table.length(); i++)
	{
		out << table.f_table[i] << endl;
	}
	return out;
}
