#pragma once
#include "Martenitsa.h"
class MartenitsaContainer
{
	Martenitsa m_container[250];
	int m_size;
	void sortContainerDescending();
public:
	MartenitsaContainer();
	MartenitsaContainer(Martenitsa container[], int size = 0);

	void addMart(Martenitsa& martenitsa);

	void bestMart();

	void fiveBestMarts();
};

