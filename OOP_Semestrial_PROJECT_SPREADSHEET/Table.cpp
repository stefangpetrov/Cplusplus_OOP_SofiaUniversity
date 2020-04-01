#include "Table.h"

Table::Table(const char * fileName)
{
	
	//f_size = 0;
	//f_table = new CellRow[f_capacity];

	//drobq faila zemam raoti i gi puham v otdelnite redove//

	//zadelqm pamet za f_table !! trqbva da znam kolko reda sa vav faila?!!

	//while(imame redove){

		//while(sedq na sashtiq red){

			//vzel sam red, 
			//vzemam vseki element, namiram mu tipa, slagam go v temp
			
			
		//}
		//kato e gotov zadelqm pamet za table[i] i go priravnqvam na temp
	//}

}

Table::Table(const Table& other)
{
	if (this != &other)
	{
		f_size = other.f_size;
		f_table = new CellRow[f_size];
		for (size_t i = 0; i < f_size; i++)
		{
			f_table[i] = other.f_table[i];
		}
	}
}

Table& Table::operator=(const Table& other)
{
	if (this != &other)
	{
		delete[] f_table;
		f_size = other.f_size;
		f_table = new CellRow[f_size];
		for (size_t i = 0; i < f_size; i++)
		{
			f_table[i] = other.f_table[i];
		}
	}

	return *this;
}

Table::~Table()
{
	delete[] f_table;
}


