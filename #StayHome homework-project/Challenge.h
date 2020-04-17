#pragma once
#include<iostream>
#include <cstring>
#include <cmath>
#include <fstream>
#pragma warning(disable:4996)
using namespace std;

class Challenge
{
    char name[32];
    unsigned short numberOfRaters;
    unsigned short numberOfChallenges;
    float sumRate;
public:
    Challenge(const char* _name = "");
    

    const char* getName() const
    {
        return this->name;
    }
    void increaseChallenges()
    {
        this->numberOfChallenges++;
    }
    int getNumberOfChallenges()
    {
        return this->numberOfChallenges;
    }

    void ChangeRating(float newRating);
    
    void print();
    
};

