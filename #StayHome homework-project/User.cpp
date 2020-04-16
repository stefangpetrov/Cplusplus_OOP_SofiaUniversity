#include "User.h"
int _ID = 1;
User::User(const char* _name, const int _years, const char* _email)
{
    if (_name != nullptr)
    {
        name = new char[strlen(_name) + 1];
        strcpy(name, _name);
    }

    else
    {
        name = new char[1];
        strcpy(name, "");
    }

    this->years = _years;
    strcpy(email, _email);
    ID = _ID;
    _ID++;
}

User::User(const User& other)
{
    if (this != &other)
    {
        this->name = new char[strlen(other.name) + 1];

        strcpy(this->name, other.name);
        strcpy(this->email, other.email);
        this->years = other.years;

        ID = _ID;
        unfinishedChals = other.unfinishedChals;
        _ID++;

    }
}

User& User::operator=(const User& other)
{
    if (this != &other)
    {
        delete[] this->name;

        this->name = new char[strlen(other.name) + 1];

        strcpy(this->name, other.name);
        strcpy(this->email, other.email);
        this->years = other.years;
        unfinishedChals = other.unfinishedChals;

    }

    return *this;
}

User::~User()
{
    if(name != nullptr)
        delete[] name;
}

const char* User::getName() const
{
    return this->name;
}

void User::print()
{
    cout << this->ID << endl;
    cout << name << endl;
    if (years > 0 && years < 90)
    {
        cout << years << endl;
    }
    else
    {
        cout << "Unknown" << endl;
    }
    cout << email << endl;
}

const char* User::getEmail() const
{
    return this->email;
}

void User::addUnfinishedChallenge(const char* challengeTag)
{
    if (!this->unfinishedChals.contains(challengeTag))
    {
        this->unfinishedChals.add(challengeTag);
    }
    this->unfinishedChals.print();
    return;
}

void User::removeChallenge(const char* challengeName)
{
    this->unfinishedChals.remove(challengeName);
}

const int User::getId()const
{
    return this->ID;
}
