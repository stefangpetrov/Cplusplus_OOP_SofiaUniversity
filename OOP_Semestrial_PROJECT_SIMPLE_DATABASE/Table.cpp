#include "Table.h"



void Table::addColumn(Column column)
{
	f_table.to_end(column);
}


void Table::setName(String name)
{
	f_name = name;
}

const String Table::getName() const
{
	return f_name;
}

size_t Table::getLength()
{
	return f_table.length();
}

Column& Table::operator[](size_t i)
{
	return f_table[i];
}

int Table::countRowsWithAValue(int col, String value)
{
	int count = 0;
	if (col <= 0)
	{
		return count;
	}

	if (f_table.length() > 0)
	{
		for (size_t j = 0; j < f_table[0].getLength(); j++)
		{
			if (strcmp(f_table[col - 1][j].getValue().getStr(), value.getStr()) == 0)
			{
				count++;
			}

		}
	}
	
	return count;
}

void Table::takeBiggestColumnSizes()
{

	for (size_t i = 0; i < f_table.length(); i++)
	{
		if(i == f_columnSizes.length())
			f_columnSizes.to_end(f_table[i].getHeader().getLength());
		
		
	}

	
	for (size_t i = 0; i < f_table.length(); i++)
	{
		size_t currentColSize = f_columnSizes[i];
		for (size_t j = 0; j < f_table[i].getLength(); j++)
		{

			if (currentColSize < f_table[i][j].getLength())
			{
				currentColSize = f_table[i][j].getLength();
			}
		}

		f_columnSizes[i] = currentColSize;
		

	}
	
}

void Table::printAllRowsWithValueInCol(int col, String value)
{
	if (f_table.length() > 0)
	{
		for (size_t j = 0; j < f_table[0].getLength(); j++)
		{
			if (strcmp(f_table[col - 1][j].getValue().getStr(), value.getStr()) == 0)
			{
				for (size_t i = 0; i < f_table.length(); i++)
				{

					if (f_columnSizes[i] == f_table[i][j].getLength())
					{
						cout << f_table[i][j] << " | ";
					}
					else
					{

						cout << f_table[i][j] << setw(f_columnSizes[i] - f_table[i][j].getLength()) << " ";
						cout << " | ";
					}
				}
				cout << endl;
			}

		}
	}
}

ostream& operator<<(ostream& out, const Table& table)
{
	out << table.f_name << endl;

 	if (table.f_table.length() == 0)
	{
		out << "No columns in the table" << endl;
		return out;
	}
	for (size_t i = 0; i < table.f_table.length(); i++)
	{
		
		if (table.f_columnSizes[i] == table.f_table[i].getHeader().getLength())
		{
			out << table.f_table[i].getHeader() << " | ";
		}
		else
		{

			out << table.f_table[i].getHeader() << setw(table.f_columnSizes[i] - table.f_table[i].getHeader().getLength()) << " ";
			out << " | ";
		}
	}
	out << endl;

	
	for (size_t i = 0; i < table.f_table[0].getLength(); i++)
	{
		for (size_t j = 0; j < table.f_table.length(); j++)
		{
			//cout << table.f_table[j][i]<<endl;
			
			if (table.f_columnSizes[j] == table.f_table[j][i].getLength())
			{
				out << table.f_table[j][i] << " | ";
			}
			else
			{

				out << table.f_table[j][i] << setw(table.f_columnSizes[j] - table.f_table[j][i].getLength()) << " ";
				out << " | ";
			}
			
		}
		out << endl;
	}
	return out;
}
