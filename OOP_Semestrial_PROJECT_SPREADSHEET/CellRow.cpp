#include "CellRow.h"

CellRow::CellRow()
{	
	f_capacity = 2;
	f_row = new Cell[f_capacity];
	f_size = 0;
}

CellRow::CellRow(const CellRow& other)
{
	if (this != &other)
	{
		f_size = other.f_size;
		f_capacity = other.f_capacity;

		f_row = new Cell[f_capacity];

		for (size_t i = 0; i < f_size; i++)
		{
			f_row[i] = other.f_row[i];
		}


	}
}

CellRow& CellRow::operator=(const CellRow& other)
{
	if (this != &other)
	{
		delete[] f_row;
		f_size = other.f_size;
		f_capacity = other.f_capacity;

		f_row = new Cell[f_capacity];

		for (size_t i = 0; i < f_size; i++)
		{
			f_row[i] = other.f_row[i];
		}

		

	}
	return *this;
}

CellRow::~CellRow()
{
	delete[] f_row;
}
