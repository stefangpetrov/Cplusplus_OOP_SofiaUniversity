#pragma once
#pragma warning(disable:4996)
#include <iostream>
#include<cstring>
using namespace std;

class Martenitsa
{
	char* m_studentName;
	char* m_wishMarta;
	int m_length;
	int m_numberM;
	
	void del();
	void copy(const char* studentName, const char* wishMarta, int length, int numberM);

public:
	Martenitsa();
	Martenitsa(const char* studentName, const char* wishMarta, int length, int numberM);
	Martenitsa(const Martenitsa& other);

	Martenitsa& operator=(const Martenitsa& other);
	bool operator>(const Martenitsa& other);
	bool operator<(const Martenitsa& other);
	bool operator==(const Martenitsa& other);

	void setStudentName(const char* studentName);
	void setWish(const char* wish);

	void setLength(int length);
	void setNumberM(int numberM);


	const char* getStudentName() const;
	const char* getWish() const;

	int getLength() const;
	int getNumberM() const;

	

	void print() const;

	~Martenitsa();
};
