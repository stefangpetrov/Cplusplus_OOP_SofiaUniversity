#include <iostream>
#include <fstream>
#include<cstring>
#include "table.h"
#include "ConsoleHandler.h"
using namespace std;

const int INITIAL_SIZE = 8;

int main()
{

    // std::cout << "Hello World!\n";

     //Table table(char* filename);
    /*
    ifstream input("test.txt");

    char c;
    
    char* line;
    int index = 0;
    int allocated = INITIAL_SIZE;

    if (!input.is_open())
    {
        return 0;
    }
    else
    {
        line = new char[INITIAL_SIZE];
        while (input.get(c)) {       
         
            if (index == allocated)
            {
                allocated *= 2;
                char* temp = new char[allocated];

                for (size_t i = 0; i < index; i++)
                {
                    temp[i] = line[i];
                }

                delete[] line;

                line = temp;
            }

            line[index] = c;
       }

    }

    //strtok(line, "\n")
    //cout << line;
    input.close();
    
    */


    ConsoleHandler handler;

    handler.handleCommand("C:dasa/sda'\dasd'dtest.txt");
    
    

}

