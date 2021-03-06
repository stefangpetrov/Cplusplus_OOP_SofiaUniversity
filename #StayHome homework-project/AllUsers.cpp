#include "AllUsers.h"

void AllUsers::copy(const int _size, const int _capacity, const User* _users)
{
    this->capacity = _capacity;
    this->size = _size;
    this->users = new User[capacity];

    for (int i = 0; i < size; i++)
    {
        this->users[i] = _users[i];
    }
}

void AllUsers::resize()
{
    if (size == capacity)
    {
        capacity *= 2;
        User* buffer = new User[capacity];

        for (size_t i = 0; i < size; i++)
        {
            buffer[i] = users[i];
        }

        delete[] users;
        users = buffer;

    }
}

AllUsers::AllUsers()
{
    capacity = 2;
    size = 0;
    users = new User[capacity];
}

AllUsers::AllUsers(const AllUsers& other)
{
    if (this != &other)
    {
        copy(other.size, other.capacity, other.users);
    }
}

const AllUsers& AllUsers::operator=(const AllUsers& other)
{
    if (this != &other)
    {
        delete[] this->users;
        copy(other.size, other.capacity, other.users);
    }
    return *this;
}

AllUsers::~AllUsers()
{
    if(users != nullptr)
        delete[] users;
}

User& AllUsers::operator[](int i)
{
    return this->users[i];
}

const int AllUsers::getSize() const
{
    return this->size;
}

void AllUsers::add(const char* userInfo)
{
    resize();

    char* _userInfo = nullptr;
    _userInfo = new char[strlen(userInfo) + 1];

    strcpy(_userInfo, userInfo);

    char* userName = nullptr;
    char* userYears = nullptr;
    char* userEmail = nullptr;
    int years = -1;

    char* tok;
    tok = strtok(_userInfo, " ");
    if (tok != nullptr)
    {
        userName = new char[strlen(tok) + 1];
        strcpy(userName, tok);
    }

    tok = strtok(NULL, " ");

    if (tok != NULL)
    {
        userYears = new char[strlen(tok) + 1];
        strcpy(userYears, tok);


        if (strlen(userYears) == 1)
        {
            if (userYears[0] >= '0' && userYears[0] <= '9')
                years = userYears[0] - '0';
        }

        else if (strlen(userYears) == 2)
        {
            if (userYears[0] >= '0' && userYears[0] <= '9')
            {
                years = (userYears[0] - '0') * 10;
                if (userYears[1] >= '0' && userYears[1] <= '9')
                {
                    years += userYears[1] - '0';
                }
            }
        }
        else
        {
            userEmail = new char[strlen(tok) + 1];
            strcpy(userEmail, tok);
        }

    }


    tok = strtok(NULL, " ");

    if (tok != NULL)
    {
        userEmail = new char[strlen(tok) + 1];
        strcpy(userEmail, tok);
    }

    if (userName != nullptr)
    {

        if (userEmail != nullptr && (years > -1 && years < 90))
        {
            User newUser(userName, years, userEmail);
            users[size] = newUser;
        }
        else if (userEmail != nullptr)
        {

            User newUser(userName, -1, userEmail);
            users[size] = newUser;
        }
        else if (userEmail == nullptr && (years > -1 && years < 90))
        {
            User newUser(userName, years);
            users[size] = newUser;
        }
        else
        {
            User newUser(userName);
            users[size] = newUser;
        }
        size++;
    }

    if (_userInfo != nullptr)
        delete[]_userInfo;

    if (userName != nullptr)
        delete[] userName;
    if (userYears != nullptr)
        delete[] userYears;
    if (userEmail != nullptr)
        delete[] userEmail;
}

void AllUsers::print()
{
    for (size_t i = 0; i < size; i++)
    {
        users[i].print();

    }
}

bool AllUsers::contains(const char* name)
{
    for (int i = 0; i < size; i++)
    {
        if (strcmp(users[i].getName(), name) == 0)
        {
            return true;
        }
    }
    return false;
}

bool AllUsers::containsID(const int ID)
{
    for (int i = 0; i < size; i++)
    {
        if (users[i].getId() == ID )
        {
            return true;
        }
    }
    return false;

}



