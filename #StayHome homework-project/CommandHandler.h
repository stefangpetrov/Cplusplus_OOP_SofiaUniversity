#pragma once

#include "AllUsers.h"
#include "ChallengeArray.h"


class CommandHandler
{
    AllUsers allUsers;
    ChallengeArray allChallenges;
    
    
public:
    
    void handleCommand(const char* command);

    void registration(const char* userInfo);
    

    void challenge(const char* challengeInfo);
    

    void finish(const char* finishInfo);
    

    void profileInfo(const char* name);
    

    void listBy(const char* listInfo);
    

    void load(const char* fileInfo);
    
};

