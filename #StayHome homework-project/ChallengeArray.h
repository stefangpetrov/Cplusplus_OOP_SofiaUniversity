#pragma once
#include "Challenge.h"

class ChallengeArray
{
    Challenge* challenges;
    int size;
    int capacity;

public:
    ChallengeArray();
    
    ChallengeArray(const ChallengeArray& other);
    
    const ChallengeArray& operator= (const ChallengeArray& other);
    
    ~ChallengeArray();
    

    bool contains(const char* challengeName);
    
    void add(const char* challengeName);
   

    void remove(const char* challengeName);
    
    void print();
    

    const int getSize();
    

    Challenge& operator [] (int i);
    
};

