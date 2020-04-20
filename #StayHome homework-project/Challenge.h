#pragma once
#pragma warning(disable:4996)

#include<iostream>
#include <fstream>
#include <cstring>
#include <cmath>


using namespace std;

class Challenge
{
    char name[32];
    unsigned short numberOfRaters;
    unsigned short numberOfChallenges;
    float sumRate;
public:
    Challenge(const char* _name = "");
    

    const char* getName() const;
    
    void increaseChallenges();
    
    int getNumberOfChallenges();
    

    void ChangeRating(float newRating);
    
    void print();
    
};

