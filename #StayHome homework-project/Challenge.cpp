#include "Challenge.h"

Challenge::Challenge(const char* _name)
{
    this->numberOfRaters = 0;
    this->sumRate = 0.00;
    this->numberOfChallenges = 1;

    
    if(name != nullptr)
        strcpy(this->name, _name);
    else
        strcpy(this->name, "");
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
