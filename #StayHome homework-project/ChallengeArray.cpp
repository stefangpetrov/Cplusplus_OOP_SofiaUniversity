#include "ChallengeArray.h"

void ChallengeArray::copy(int _size, int _capacity, Challenge* _challenges)
{
    this->capacity = _capacity;
    this->size = _size;
    this->challenges = new Challenge[capacity];

    for (int i = 0; i < size; i++)
    {
        this->challenges[i] = _challenges[i];
    }
}

ChallengeArray::ChallengeArray()
{
    capacity = 4;
    size = 0;
    challenges = new Challenge[capacity];
}

ChallengeArray::ChallengeArray(const ChallengeArray& other)
{
    if (this != &other)
    {
        copy(other.size, other.capacity, other.challenges);
    }
}

const ChallengeArray& ChallengeArray::operator=(const ChallengeArray& other)
{
    if (this != &other)
    {
        delete[] this->challenges;
        copy(other.size, other.capacity, other.challenges);
    }
    return *this;
}

ChallengeArray::~ChallengeArray()
{
    if(challenges != nullptr)
        delete[] challenges;
}

bool ChallengeArray::contains(const char* challengeName)
{
    for (int i = 0; i < size; i++)
    {
        if (strcmp(challenges[i].getName(), challengeName) == 0)
        {
            return true;
        }

    }
    return false;
}

void ChallengeArray::add(const char* challengeName)
{
    if (this->contains(challengeName))
    {
        for (int i = 0; i < size; i++)
        {
            if (strcmp(challenges[i].getName(), challengeName) == 0)
            {
                challenges[i].increaseChallenges();
            }
        }
    }
    else
    {

        if (size == capacity)
        {
            capacity *= 2;
            Challenge* buffer = new Challenge[capacity];

            for (size_t i = 0; i < size; i++)
            {
                buffer[i] = challenges[i];
            }

            delete[] challenges;
            challenges = buffer;

        }

        Challenge newChallenge(challengeName);
        //newChallenge.print();
        challenges[size] = newChallenge;
        //challenges[size].print();
        size++;
    }
}

void ChallengeArray::remove(const char* challengeName)
{
    if (!(this->contains(challengeName)))
    {
        cout << "wrong challenge" << endl; 
    }
    else
    {
        int index = 0;
        Challenge* buffer = new Challenge[capacity];
        for (int i = 0; i < size; i++)
        {
            if (strcmp(challenges[i].getName(), challengeName) == 0)
            {
                continue;
            }
            else
            {
                buffer[index] = challenges[i];
                index++;
            }

        }

        delete[] this->challenges;
        this->challenges = buffer;
        this->size--;
    }
}


void ChallengeArray::print()
{
    for (size_t i = 0; i < size; i++)
    {
        challenges[i].print();
    }
}

const int ChallengeArray::getSize()
{
    return this->size;
}

Challenge& ChallengeArray::operator[](int i)
{
    return this->challenges[i];
}
