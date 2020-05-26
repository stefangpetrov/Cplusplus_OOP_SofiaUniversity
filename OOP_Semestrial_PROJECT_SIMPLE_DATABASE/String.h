#pragma once
#pragma warning(disable:4996)
#include <iostream>
#include <cstring>
#include <cassert>
using namespace std;

class String
{
private:
    char* str;
    int length;

    bool isMatching(char* strToSearch, const char* strToMatch);
    void shiftLeft(char* strToShift, int shiftPosCount);
    void shiftRight(char* strToShift, int shiftPosCount);
    void performStringReplacement(char* source, const char* newWord);
    void setStr(const char* _str);
    void setLength(int _length);

public:
    String();
    String(const char* _str);
    String(const String& other);
    ~String();
    String& operator=(const String& other);

    const char* getStr() const;
    int getLength() const;

    String operator+=(const String& other);
    String operator+=(const char* _str);
    String operator+=(char _str);
    String operator+(const String& other);
    String operator+(const char* _str);
    char operator[](const int index) const;

    bool operator!=(const String& other);
    bool operator!=(const char* other);

    bool operator==(const String& other);
    bool operator==(const char* other);
    bool operator<(const String& other);
    bool operator>(const String& other);
    bool operator<=(const String& other);
    bool operator>=(const String& other);

    bool isIntString();
    bool isDoubleString();
    bool isGood();

    void output();
    void add(const char* _str);
    void removeLast();
    String slice(int start, int end) const;
    //void replace(const char* oldWord, const char* newWord);



    friend ostream& operator <<(ostream& out, const String str);
};

