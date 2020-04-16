#include "CommandHandler.h"

int main()
{

    CommandHandler handler;
    char command[50];


    while (true)
    {
        cin.getline(command, 50);


        if (strcmp(command, "exit") == 0)
        {
            break;
        }
        handler.handleCommand(command);
    }  

    return 0;
}