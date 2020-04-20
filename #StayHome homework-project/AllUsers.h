#pragma once
#include"User.h"

class AllUsers
{
    User* users;
    int size;
    int capacity;
    void copy(const int _size, const int _capacity, const User* _users);
    void resize();


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
    bool containsID(const int ID);
    
};

