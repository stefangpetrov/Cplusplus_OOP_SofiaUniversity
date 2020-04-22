/*
#include "Table.h"




int main()
{
    ofstream out("test.txt");

    String type1 = "double";
    String type2 = "string";

    String type3 = "number";

    Cell A(0.5);
    Cell B(5);

    Cell C(type3);

    CellRow row;
    CellRow row2;
    row.addCell(A);
    row.addCell(B);

    row.addCell(C);

    row2.addCell(C);
    row2.addCell(B);

    row2.addCell(A);

    Table table;

    table.addRow(row);
    table.addRow(row2);

    out << table;
    

    out.close();
    
    
}
*/

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
        String strCommand(command);
        if (strCommand.getLength() > 0)
            handler.handleCommand(strCommand);
        else
            cout << "Invalid command!. Try again." << endl;
        delete[] command;
    }

    return 0;


    
    
}