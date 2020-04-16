#include "CommandHandler.h"

int main()
{

    CommandHandler handler;
    char command[50];

    
    while (true)
    {
        cin.getline(command, 50);
        handler.handleCommand(command);
    }

    

    

    return 0;
}