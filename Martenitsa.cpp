#include "Martenitsa.h"



void Martenitsa::del()
{
	delete[] this->m_studentName;
	delete[] this->m_wishMarta;
}

void Martenitsa::copy(const char* studentName, const char* wishMarta, int length, int numberM)
{
	this->m_studentName = new char[strlen(studentName) + 1];
	this->m_wishMarta = new char[strlen(wishMarta) + 1];

	this->setStudentName(studentName);
	this->setWish(wishMarta);
	this->m_length = length;
	this->m_numberM = numberM;
}

Martenitsa::Martenitsa()
{
	copy("\0", "\0", 1, 0);
}

Martenitsa::Martenitsa(const char* studentName, const char* wishMarta, int length, int numberM)
{
	copy(studentName, wishMarta, length, numberM);
}

Martenitsa::Martenitsa(Martenitsa const& other)
{
	if (this != &other)
	{
		del();

		copy(other.getStudentName(), other.getWish(), other.getLength(), other.getNumberM());
	}

}

Martenitsa& Martenitsa::operator=(const Martenitsa& other)
{
	if (this != &other)
	{

		del();

		copy(other.getStudentName(), other.getWish(), other.m_length, other.m_numberM);
	}

	return *this;
}

bool Martenitsa::operator>(const Martenitsa& other)
{
	if (m_length > other.getLength())
	{
		return true;
	}
	else if (m_length == other.getLength())
	{
		if (m_numberM > other.getNumberM())
		{
			return true;
		}
	}
	return false;
}

bool Martenitsa::operator<(const Martenitsa& other)
{
	if (m_length < other.getLength())
	{
		return true;
	}
	else if (m_length == other.getLength())
	{
		if (m_numberM < other.getNumberM())
		{
			return true;
		}
	}
	return false;
}

bool Martenitsa::operator==(const Martenitsa& other)
{
	if (m_length == other.getLength() && m_numberM == other.getNumberM())
	{
		return true;
	}
	return false;
}

const char* Martenitsa::getStudentName() const
{
	return m_studentName;
}

const char* Martenitsa::getWish() const
{
	return m_wishMarta;
}

int Martenitsa::getLength() const
{
	return m_length;
}

int Martenitsa::getNumberM() const
{
	return m_numberM;
}

void Martenitsa::setStudentName(const char* studentName)
{

	strcpy(m_studentName, studentName);
}

void Martenitsa::setWish(const char* wish)
{
	strcpy(m_wishMarta, wish);
}

void Martenitsa::setLength(int length)
{
	if (length <= 0)
	{
		m_length = 1;
	}
	{
		m_length = length;
	}
}

void Martenitsa::setNumberM(int numberM)
{
	if (numberM < 0)
	{
		numberM = 0;
	}
	else
	{
		m_numberM = numberM;
	}
}



void Martenitsa::print() const
{
	cout << "Student name: " << m_studentName << endl;
	cout << "Wish from Marta: " << m_wishMarta << endl;
	cout << "Martenitsa length: " << m_length << endl;
	cout << "Number of Manista: " << m_numberM << endl;

}

Martenitsa::~Martenitsa()
{
	cout << "Vlqzoh v destrcuctor" << endl;;
	del();
}
