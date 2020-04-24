#include "Table.h"

Table::Table()
{
	f_biggestRowSize = 0;
}

void Table::addRow(CellRow row)
{
	f_table.to_end(row);
	if (f_biggestRowSize < row.getLength())
	{
		f_biggestRowSize = row.getLength();
	}
}

void Table::addCellsWhereNeeded()
{
	
	for (size_t i = 0; i < f_table.length(); i++)
	{
		for (size_t j = f_table[i].getLength(); j < f_biggestRowSize; j++)
		{
			Cell emptyCell;
			f_table[i].addCell(emptyCell);
		}
	}
}

void Table::takeBiggestColumnSizes()
{
	if (f_table.length() > 1)
	{
		for (size_t i = 0; i < f_table.length(); i++)
		{
			if (f_table[i].getLength() != f_biggestRowSize)
				return;
		}
	}

	for (size_t i = 0; i < f_biggestRowSize; i++)
	{
		if (i > f_columnSizes.length())
		{
			
			f_columnSizes.to_end(f_table[0][i].getLength());
		}
		
	}

	for (size_t i = 0; i < f_biggestRowSize; i++)
	{
		size_t currentColSize = f_table[0][i].getLength();
		for (size_t j = 1; j < f_table.length(); j++)
		{
			
			if (currentColSize < f_table[j][i].getLength())
			{
				currentColSize = f_table[j][i].getLength();
			}
		}

		f_columnSizes[i] = currentColSize;
		
	}
	
}

ostream& operator<<(ostream& out, const Table& table)
{
	for (size_t i = 0; i < table.f_table.length(); i++)
	{
		for (size_t j = 0; j < table.f_biggestRowSize; j++)
		{
			
			if (table.f_columnSizes[j] == table.f_table[i][j].getLength())
			{
				out << table.f_table[i][j] << " | ";
			}
			else
			{
				
				out << table.f_table[i][j] << setw(table.f_columnSizes[j] - table.f_table[i][j].getLength()) << " ";
				out << " | ";
			}
			
		}
		out << endl;
	}
	return out;
}
