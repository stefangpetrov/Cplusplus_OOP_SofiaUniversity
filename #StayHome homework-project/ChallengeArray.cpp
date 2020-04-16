#include "ChallengeArray.h"

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
        this->capacity = other.capacity;
        this->size = other.size;
        this->challenges = new Challenge[capacity];

        for (int i = 0; i < size; i++)
        {
            this->challenges[i] = other.challenges[i];
        }

    }
}

const ChallengeArray& ChallengeArray::operator=(const ChallengeArray& other)
{
    if (this != &other)
    {
        delete[] this->challenges;
        this->capacity = other.capacity;
        this->size = other.size;
        this->challenges = new Challenge[capacity];

        for (int i = 0; i < size; i++)
        {
            this->challenges[i] = other.challenges[i];
        }

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
        cout << "tuk" << endl;
        for (int i = 0; i < size; i++)
        {
            if (strcmp(challenges[i].getName(), challengeName) == 0)
            {
                challenges[i].increaseChallenges();

                if (challenges[i].getNumberOfChallenges() >= 2 && challenges[i].getNumberOfChallenges() <= 10)
                {
                    challenges[i].changeStatus("quite recently");
                }
                else if (challenges[i].getNumberOfChallenges() >= 11)
                {
                    challenges[i].changeStatus("old");
                }
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
    if (this->contains(challengeName))
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
    else
    {
        cout << "wrong challenge" << endl;
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
