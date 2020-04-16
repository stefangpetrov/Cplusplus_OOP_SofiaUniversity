#pragma once
#include "ChallengeArray.h"


class User
{
    char* name;
    char email[100];
    int years;
    int ID;
    ChallengeArray unfinishedChals;

public:
    User(const char* _name = "", const int _years = 0, const char* _email = "Unknown");
    User(const User& other);   
    User& operator = (const User& other);
    ~User();
    

    const char* getName() const;
    void print();
    
    const char* getEmail()const;
    
    void addUnfinishedChallenge(const char* challengeTag);

    void removeChallenge(const char* challengeName);

    const int getId() const;
    
};

