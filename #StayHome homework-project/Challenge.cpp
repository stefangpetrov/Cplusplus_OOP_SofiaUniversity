#include "Challenge.h"

Challenge::Challenge(const char* _name):
    numberOfChallenges(1), numberOfRaters(0), sumRate(0.00)
{
    if(name != nullptr)
        strcpy(this->name, _name);
    else
        strcpy(this->name, "");
}

const char* Challenge::getName() const
{
    return this->name;
}

void Challenge::increaseChallenges()
{
    this->numberOfChallenges++;
}

int Challenge::getNumberOfChallenges()
{
    return this->numberOfChallenges;
}

void Challenge::ChangeRating(float newRating)
{
    this->numberOfRaters++;
    this->sumRate += newRating;
}

void Challenge::print()
{
    cout << "name: " << this->name << endl;
    cout << "status: ";
    if (numberOfChallenges < 2)
    {
        cout << "new" << endl;
    }
    else if (numberOfChallenges > 2 && numberOfChallenges < 10)
    {
        cout << "quite recently" << endl;
    }
    else
    {
        cout << "old" << endl;
    }
    if (this->sumRate != 0)
        cout << "rating: " << (double)(this->sumRate / this->numberOfRaters) << endl;
    else
        cout << "rating: " << 0 << endl;
}
