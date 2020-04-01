#pragma once
#include "Cell.h"

class CellRow
{
private:

	Cell* f_row;
	size_t f_capacity;
	size_t f_size;

public:
	CellRow();

	CellRow(const CellRow& other);

	CellRow& operator=(const CellRow& other);

	~CellRow();
};

