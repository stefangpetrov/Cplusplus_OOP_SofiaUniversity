#include "ConsoleHandler.h"
#include <cstring>
using namespace std;

int main()
{
    
    ConsoleHandler handler;

    cout << "Type help to see all the available commands!" << endl;

    while (true)

    {
        char c;
        String strCommand;

        while (cin.get(c))
        {
            if ('\n' == c || '\r' == c)
            {
                break;
            }
            else
            {
                
                strCommand += c;
                
            }


        }
        
        if (strCommand.getLength() > 0)
            handler.handleCommand(strCommand);
        else
            cout << "Invalid command!. Try again." << endl;
    }

    return 0;
    
    
 

    

    
    
}