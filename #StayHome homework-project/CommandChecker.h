#pragma once
#pragma warning(disable:4996)
#include <cstring>
namespace checker
{
    bool isChallenge(const char* command)
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

    bool isFinish(const char* command)
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

    bool isProfileInfo(const char* command)
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

    bool isListBy(const char* command)
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

    bool isLoad(const char* command)
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

    bool isRegistration(const char* command)
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
}