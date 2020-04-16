#pragma once
#include "AllUsers.h"
#include "ChallengeArray.h"

class CommandHandler
{
    AllUsers allUsers;
    ChallengeArray allChallenges;
    bool isChallenge(const char* command);
    bool isFinish(const char* command);
    bool isProfileInfo(const char* command);
    bool isListBy(const char* command);
    bool isLoad(const char* command);
    bool isRegistration(const char* command);
    
public:
    
    void handleCommand(const char* command);

    void registration(const char* userInfo);
    

    void challenge(const char* challengeInfo);
    

    void finish(const char* finishInfo);
    

    void profileInfo(const char* name);
    

    void listBy(const char* listInfo);
    

    void load()
    {

    }
};

