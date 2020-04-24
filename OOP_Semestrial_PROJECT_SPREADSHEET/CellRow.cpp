#include "CellRow.h"
#include <iomanip>


void CellRow::addCell(const Cell& cell)
{
	f_row.to_end(cell);
}

size_t CellRow::getLength()
{
	return this->f_row.length();
}

void CellRow::print()
{
	for (size_t i = 0; i < f_row.length(); i++)
	{
		cout << f_row[i]<<" ";
	}
	cout << endl;
}

ostream& operator<<(ostream& out, const CellRow& row)
{
	for (size_t i = 0; i < row.f_row.length(); i++)
	{
		out << row.f_row[i] << setw(10) << " | ";
	}
	out << endl;
	return out;
}
