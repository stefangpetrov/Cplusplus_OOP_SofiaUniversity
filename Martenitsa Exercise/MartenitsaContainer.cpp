#include "MartenitsaContainer.h"

void MartenitsaContainer::sortContainerDescending()
{
	for (size_t i = 0; i < m_size - 1; i++)
	{
		Martenitsa bestMart = m_container[i];
		int indexMax = i;
		for (size_t j = i + 1; j < m_size; j++)
		{
			if (bestMart < m_container[j])
			{
				bestMart = m_container[j];
				indexMax = j;
			}
		}
		if (m_container[i] != bestMart)
		{
			Martenitsa temp = m_container[i];
			m_container[indexMax] = temp;
			m_container[i] = bestMart;

		}
	}
}

MartenitsaContainer::MartenitsaContainer()
{
	m_size = 0;
	
}

MartenitsaContainer::MartenitsaContainer(Martenitsa container[], int size)
{
	for (size_t i = 0; i < size; i++)
	{
		m_container[i] = container[i];
	}
	m_size = size;
}

void MartenitsaContainer::addMart(Martenitsa& martenitsa)
{

	if (m_size < 250)
	{
		m_container[m_size] = martenitsa;
		m_size++;

	}
	
}

void MartenitsaContainer::bestMart()
{
	if (m_size > 0)
	{
		Martenitsa bestMart = m_container[0];
		for (size_t i = 1; i < m_size; i++)
		{
			if (bestMart < m_container[i])
			{
				bestMart = m_container[i];
			}
		}

		bestMart.print();
		cout << endl;
	}
	else
	{
		cout << "There is no information about any martenitsa yet" << endl;
	}
	
}

void MartenitsaContainer::fiveBestMarts()
{
	if (m_size > 4)
	{	
		sortContainerDescending();

		for (size_t i = 0; i < 5; i++)
		{
			m_container[i].print();
			cout << endl;
		}

	}
	else
	{
		cout << "There is no information about five martenitsa yet" << endl;
	}
}


