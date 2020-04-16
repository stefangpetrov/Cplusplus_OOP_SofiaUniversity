#pragma once
#include<iostream>
#include <cstring>
#include <cmath>
#pragma warning(disable:4996)
using namespace std;

class Challenge
{
    char name[32];
    char status[20];
    int numberOfRaters;
    unsigned short numberOfChallenges;
    double sumRate;
    double rating;
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
    void changeStatus(const char* newStatus)
    {
        strcpy(this->status, newStatus);
    }

    void ChangeRating(double newRating);
    
    void print();
    
};

