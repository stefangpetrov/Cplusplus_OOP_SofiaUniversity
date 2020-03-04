#include "Martenitsa.h"



void testMartenitsaClass()
{
	Martenitsa defaultMart;

	Martenitsa constructMart("Gosho", "Vesela Marta", 5, 10);
	defaultMart.print();

	cout << endl;
	constructMart.print();

	cout << endl;

	Martenitsa copyMartenitsa = constructMart;
	copyMartenitsa.print();

	cout << endl;

	defaultMart = copyMartenitsa;
	defaultMart.print();

	defaultMart = Martenitsa("Pesho", "Vesela koleda", 1, 2);

	(defaultMart = copyMartenitsa) = constructMart;

	cout << endl;
	defaultMart.print();

}

int main()
{
	testMartenitsaClass();
}