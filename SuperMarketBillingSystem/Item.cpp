#include "Item.h"

void Item:: init(const char* name, Date date, size_t price)
{
	f_name = new char[strlen(name) + 1];
	strcpy(f_name, name);
	f_date = date;
	f_price = price;
}

Item::Item(const char* name, Date date, size_t price):
	f_date(date), f_price(price)
{
	if (name)
	{
		setName(name);
	}
	else
	{
		f_name = new char[2];
		strcpy(f_name, "");
	}
}

Item::Item(const Item& other)
{
	if (this != &other)
	{
		delete[] f_name;
		init(other.f_name, other.f_date, other.f_price);
		//cout << f_name;
	}
}

Item& Item::operator=(const Item& other)
{
	if (this != &other)
	{
		delete[] f_name;
		init(other.f_name, other.f_date, other.f_price);
	}

	return *this;
}

void Item::setName(const char* name)
{
	if (name)
	{
		delete[] f_name;
		f_name = new char[strlen(name) + 1];
		strcpy(f_name, name);
	}
}

void Item::print() const
{
	cout << "Name of item: ";
	cout << f_name << endl;
	cout << "Manufacturing date<dd-mm-yy>: ";


	cout << f_date.getYear() << "-" << f_date.getMonth() << "-" << f_date.getDay() << endl;

	cout << "Price: $" << f_price << endl;
}

Item::~Item()
{
	cout << f_name << endl;
	delete[] f_name;
}
