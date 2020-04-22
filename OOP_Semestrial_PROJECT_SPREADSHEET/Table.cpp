#include "Table.h"

Table::Table()
{
	biggestRowSize = 0;
}

void Table::addRow(CellRow row)
{
	f_table.to_end(row);
}

ostream& operator<<(ostream& out, const Table& table)
{
	for (size_t i = 0; i < table.f_table.length(); i++)
	{
		out << table.f_table[i] << endl;
	}
	return out;
}
