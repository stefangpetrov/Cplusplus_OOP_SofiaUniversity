#include "Challenge.h"

Challenge::Challenge(const char* _name)
{
    this->rating = 0;
    this->numberOfRaters = 0;
    this->sumRate = 0.00;
    this->numberOfChallenges = 1;

    strcpy(status, "new");
    if(name != nullptr)
        strcpy(this->name, _name);
    else
        strcpy(this->name, "");
}

void Challenge::ChangeRating(double newRating)
{
    this->numberOfRaters++;
    sumRate += newRating;

    rating = sumRate / numberOfRaters;
}

void Challenge::print()
{
    cout << "name: " << this->name << endl;
    cout << "status: " << this->status << endl;
    cout << "rating" << this->rating << endl;
}
