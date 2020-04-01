#pragma once
#pragma warning(disable:4996)
#include "CellRow.h"

class Table
{
private:
	CellRow* f_table;

	size_t f_size;

public:

	Table(const char* fileName);

	Table(const Table& other);

	Table& operator=(const Table& other);

	~Table();

};

