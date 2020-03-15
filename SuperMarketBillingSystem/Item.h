#pragma once
#pragma warning(disable:4996)
#include <iostream>
#include "Date.h"
using namespace std;



class Item
{
private:
	char* f_name;
	Date f_date;
	size_t f_price;

public:
	Item(const char* name = "", Date date = Date(2020, 1, 1), size_t price = 1);
	Item(const Item& other);

	Item& operator=(const Item& other);

	void setName(const char* name);

	void init(const char* name, Date date, size_t price);
	void print() const;

	~Item();

};

