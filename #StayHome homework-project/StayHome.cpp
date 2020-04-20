#include "CommandHandler.h"

int main()
{
    
    CommandHandler handler;


    while (true)
    {
        char c;
        char* command = new char[8];
        int allocated = 8;
        int index = 0;

        while (cin.get(c))
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
                        buffer[i] = command[i];
                    }
                    delete[] command;
                    command = buffer;

                }
                command[index] = c;
                index++;
            }


        }

        command[index] = '\0';
        handler.handleCommand(command);

        delete[] command;
    }  

    return 0;
    


  

}