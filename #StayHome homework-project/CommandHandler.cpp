#include "CommandHandler.h"

bool CommandHandler::isChallenge(const char* command)
{
    char arr[20] = "challenge ";
    for (int i = 0; i < strlen("challenge "); i++)
    {
        if (command[i] != arr[i])
        {
            return false;
        }
    }
    return true;
}

bool CommandHandler::isFinish(const char* command)
{
    char arr[10] = "finish ";
    for (int i = 0; i < strlen("finish "); i++)
    {
        if (command[i] != arr[i])
        {
            return false;
        }
    }
    return true;
}

bool CommandHandler::isProfileInfo(const char* command)
{
    char arr[20] = "profile_info ";
    for (int i = 0; i < strlen("profile_info "); i++)
    {
        if (command[i] != arr[i])
        {
            return false;
        }
    }
    return true;
}

bool CommandHandler::isListBy(const char* command)
{
    char arr[20] = "list_by ";
    for (int i = 0; i < strlen("list_by "); i++)
    {
        if (command[i] != arr[i])
        {
            return false;
        }
    }
    return true;
}

bool CommandHandler::isLoad(const char* command)
{
    char arr[20] = "load ";
    for (int i = 0; i < strlen("load "); i++)
    {
        if (command[i] != arr[i])
        {
            return false;
        }
    }
    return true;
}

bool CommandHandler::isRegistration(const char* command)
{
    char arr[20] = "registration ";
    for (int i = 0; i < strlen("registration "); i++)
    {
        if (command[i] != arr[i])
        {
            return false;
        }
    }
    return true;
}

void CommandHandler::handleCommand(const char* command)
{
    char* _command = new char[strlen(command) + 1];
    strcpy(_command, command);

    if (isRegistration(_command))
    {
        registration(_command + 13);
    }
    else if (isChallenge(_command))
    {
        challenge(_command + 10);
    }
    else if (isFinish(_command))
    {
        finish(_command + 7);
    }
    else if (isProfileInfo(_command))
    {
        profileInfo(_command + 13);
    }
    else if (isListBy(_command))
    {
        listBy(_command + 8);
    }
    else if (isLoad(_command))
    {
        load(_command + 5);
    }
    else
    {
        cout << "Invalid command!" << endl;
    }

    if (_command != nullptr)
        delete[] _command;
}

void CommandHandler::registration(const char* userInfo)
{
    allUsers.add(userInfo);
    
}

void CommandHandler::challenge(const char* challengeInfo)
{
    char* tokArray = new char[strlen(challengeInfo) + 1];
    strcpy(tokArray, challengeInfo);

    char* tok;
    tok = strtok(tokArray, " ");
    char* challengerName = nullptr;
    char* challengeTag = nullptr;

    if (tok != NULL)
    {
        challengerName = new char[strlen(tok) + 1];
        strcpy(challengerName, tok);
    }

    //
    if (challengerName != nullptr)
    {
        if (allUsers.contains(challengerName))
        {
            tok = strtok(NULL, " ");

            if (tok != NULL)
            {
                challengeTag = new char[strlen(tok) + 1];
                strcpy(challengeTag, tok);
            }


            if (challengeTag != nullptr)
            {
                if (challengeTag[0] != '#' && (strlen(challengeTag) < 2 || strlen(challengeTag) > 31))
                {
                    cout << "Challenge must start with # and be 31 symbols long!";
                    return;
                }
                else
                {
                    tok = strtok(NULL, " ");
                    if (tok != NULL)
                    {

                        while (tok != NULL)
                        {

                            if (!allUsers.contains(tok))
                            {

                                cout << tok << " is not a registered user. Try challenging some registered users." << endl;
                                if (challengerName != nullptr)
                                    delete[] challengerName;
                                if (challengeTag != nullptr)
                                    delete[] challengeTag;
                                return;
                            }
                            tok = strtok(NULL, " ");
                        }

                        delete[] tokArray;
                        tokArray = new char[strlen(challengeInfo) + 1];
                        strcpy(tokArray, challengeInfo);
                        

                        tok = strtok(tokArray, " ");
                        
                        tok = strtok(NULL, " ");
                        tok = strtok(NULL, " ");

                        while (tok != NULL)
                        {
                            //cout<<tok<<endl;
                            for (size_t i = 0; i < allUsers.getSize(); i++)
                            {
                                if (strcmp(allUsers[i].getName(), tok) == 0)
                                {
                                    allUsers[i].addUnfinishedChallenge(challengeTag);
                                    
                                    
                                }
                            }
                            tok = strtok(NULL, " ");
                        }

                        allChallenges.add(challengeTag);
                        
                        
                    }
                    else
                    {
                        cout << "You haven't specified who you want to challenge! Try again." << endl;
                        return;
                    }


                }
            }
        }
        else
        {
            cout << "No in";
            return;
        }
    }

    if (challengerName != nullptr)
        delete[] challengerName;
    if (challengeTag != nullptr)
        delete[] challengeTag;
}

void CommandHandler::finish(const char* finishInfo)
{
    char* infoToChar = nullptr;
    infoToChar = new char[strlen(finishInfo) + 1];
    strcpy(infoToChar, finishInfo);

    char* tok = strtok(infoToChar, " ");
    char* tag = nullptr;
    char* userId = nullptr;
    char* rateToChar = nullptr;
    float rate;
    int userID = 0;

    if (tok != NULL)
    {
        tag = new char[strlen(tok) + 1];
        strcpy(tag, tok);
    }
    else
    {
        cout << "Please write a valid tag!";
        return;
    }

    tok = strtok(NULL, " ");
    if (tok != NULL)
    {
        userId = new char[strlen(tok) + 1];
        strcpy(userId, tok);

        int length = strlen(userId);

        for (int i = 0; i < length; i++)
        {
            if (userId[i] < '0' || userId[i] > '9')
            {
                cout << "No such ID" << endl;
                if (userId != nullptr)
                    delete[] userId;
                if (rateToChar != nullptr)
                    delete[] rateToChar;
                if (tag != nullptr)
                    delete[] tag;
                if (infoToChar != nullptr)
                    delete[] infoToChar;

                return;
            }
            int currentDigit = userId[i] - '0';
            userID += currentDigit * pow(10, length - i - 1);
        }


        tok = strtok(NULL, " ");
        if (tok != NULL)
        {
            rateToChar = new char[strlen(tok) + 1];
            
            strcpy(rateToChar, tok);
            rate = strtod(rateToChar, NULL);

            if (rate >= -5 && rate <= 10)
            {
                for (size_t i = 0; i < allUsers.getSize(); i++)
                {
                    if (allUsers[i].getId() == userID)
                    {
                        allUsers[i].removeChallenge(tag);
                    }
                }

                for (size_t i = 0; i < allChallenges.getSize(); i++)
                {
                    if (strcmp(allChallenges[i].getName(), tag) == 0)
                    {
                        allChallenges[i].ChangeRating(rate);
                    }
                }
            }
            else
            {
                cout << "Try givin the challenge a valid rating. Hint [-5, 10]." << endl;
            }
            
            
        }
        else
        {
            cout << "Write proper rate." << endl;
        }
    }
    else
    {
        cout << "Write a proper ID!" << endl;
        return;
    }

    if (userId != nullptr)
        delete[] userId;
    if (rateToChar != nullptr)
        delete[] rateToChar;
    if (tag != nullptr)
        delete[] tag;
    if (infoToChar != nullptr)
        delete[] infoToChar;
}

void CommandHandler::profileInfo(const char* name)
{
    if (allUsers.contains(name))
    {
        for (size_t i = 0; i < allUsers.getSize(); i++)
        {
            if (strcmp(allUsers[i].getName(), name) == 0)
            {
                allUsers[i].print();
            }

        }
    }
    else
    {
        cout << "No such user!";
    }
}

void CommandHandler::listBy(const char* listInfo)
{
    int size = allChallenges.getSize();

    if (strcmp(listInfo, "newest") == 0)
    {

        for (int i = size - 1; i >= 0; i--)
        {
            allChallenges[i].print();
        }

    }
    else if (strcmp(listInfo, "oldest") == 0)
    {
        for (int i = 0; i < size; i++)
        {
            allChallenges[i].print();
        }
    }
    else if (strcmp(listInfo, "most_popular") == 0)
    {
        for (int i = 0; i < size; i++)
        {
            Challenge currentPopular = allChallenges[i];
            for (int j = i + 1; j < size; j++)
            {
                if (allChallenges[j].getNumberOfChallenges() > allChallenges[i].getNumberOfChallenges())
                {
                    currentPopular = allChallenges[j];
                }

            }
            currentPopular.print();

        }

    }
    else
    {
        cout << "Invalid command!";
    }
}

void CommandHandler::load(const char* fileInfo)
{
    fstream file;

    char* fileToChar = nullptr;
    fileToChar = new char[strlen(fileInfo) + 1];
    strcpy(fileToChar, fileInfo);

    char* tok = strtok(fileToChar, ".");
    char* ext = nullptr;
    char* fileN = nullptr;

    if (tok != NULL)
    {
        fileN = new char[strlen(tok) + 1];
        strcpy(fileN, tok);
    }

    tok = strtok(NULL, " ");

    if (tok != NULL)
    {
        ext = new char[strlen(tok) + 1];
        strcpy(ext, tok);
    }

    if (strcmp(fileN, "users") == 0)
    {
        if (strcmp(ext, "txt") == 0)
        {
            file.open("users.txt");

            char c;
            while (!file.eof())
            {

                char* userInfo = new char[8];
                int allocated = 8;
                int index = 0;
                while (file.get(c))
                {
                    if ('\n' == c || '\r' == c)
                    {
                        break;
                    }
                    else
                    {
                        if (index == allocated)
                        {
                            allocated *= 2;
                            char* buffer = new char[allocated];

                            for (int i = 0; i < index; i++)
                            {
                                buffer[i] = userInfo[i];
                            }
                            delete[] userInfo;
                            userInfo = buffer;

                        }
                        userInfo[index] = c;
                        index++;
                    }
                }

                userInfo[index] = '\0';

                cout << userInfo << endl;
                allUsers.add(userInfo);

                delete[] userInfo;
            }
            file.close();
        }
        else
        {
            cout << "Wrong ext" << endl;
            return;
        }
    }

    else if (strcmp(fileN, "challenges") == 0)
    {
        if (strcmp(ext, "bin") == 0)
        {
            ifstream fileToOpen("challenges.bin", ios::binary);
            char value;

            if (fileToOpen.is_open())
            {
                while (!fileToOpen.eof())
                {
                    char* challengeInfo = new char[8];
                    int allocated = 8;
                    int index = 0;
                    while (fileToOpen.read((char*)&value, sizeof(char)))
                    {
                        if ('\n' == value || '\r' == value)
                        {
                            break;
                        }
                        else
                        {
                            if (index == allocated)
                            {
                                allocated *= 2;
                                char* buffer = new char[allocated];

                                for (int i = 0; i < index; i++)
                                {
                                    buffer[i] = challengeInfo[i];
                                }
                                delete[] challengeInfo;
                                challengeInfo = buffer;

                            }
                            challengeInfo[index] = value;
                            index++;
                        }


                    }

                    challengeInfo[index] = '\0';

                    cout << challengeInfo << endl;
                    this->challenge(challengeInfo);

                    delete[] challengeInfo;
                }
            }
            else
            {
                cout << "file is not correct";
                return;
            }

            fileToOpen.close();
        }
        else
        {
            cout << "Wrong ext" << endl;
            return;
        }

    }
    else
    {
        cout << "Wrong file name!" << endl;
    }

}

