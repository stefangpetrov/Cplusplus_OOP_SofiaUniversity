#pragma once
#include"User.h"

class AllUsers
{
    User* users;
    int size;
    int capacity;

public:
    AllUsers();
    AllUsers(const AllUsers& other);
    const AllUsers& operator= (const AllUsers& other);
    ~AllUsers();

    User& operator [] (int i);
    
    const int getSize() const;
   
    void add(const char* userInfo);
    

    void print();
    

    bool contains(const char* name);
    

    User& getByName(const char* userName);
    
    
};

