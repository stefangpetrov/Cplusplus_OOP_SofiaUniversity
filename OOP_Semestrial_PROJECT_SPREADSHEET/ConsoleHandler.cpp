#include "ConsoleHandler.h"

void ConsoleHandler::open(String path)
{
    char* PATH = nullptr;
    PATH = new char[path.getLength() + 1];

    strcpy(PATH, path.getStr());

    f_inout.open(PATH);

    if (!f_inout.is_open())
    {
        ofstream openFile(PATH);
        if (!openFile.is_open())
        {
            cout << "file could not open" << endl;
            return;
        }
        else
        {
            openFile.close();
            f_inout.open(PATH);
            if (!f_inout.is_open())
            {
                cout << "not a valid path" << endl;
                return;
            }
            
        }
    }

    cout << "Successfully opened a file!" << endl;
    f_filePath = path;

    char* token;
    token = strtok(PATH, "/");

    while (token != NULL)
    {
        f_fileName = token;

        token = strtok(NULL, "/");
    }

    if (PATH != nullptr)
        delete[] PATH;
}

void ConsoleHandler::save()
{
    if (!f_inout.is_open())
    {
        cout << "Invalid command" << endl;
        cout << "Try opening a file first. The command is 1." << endl;

    }
    else
    {
        f_inout.clear();

        f_inout << f_table;
        cout << "Successfully saved in " << f_fileName << "file";
    }
}

void ConsoleHandler::saveAs(String path)
{
    if (path == f_filePath)
    {
        f_inout << f_table;
        cout << "Successfully saved in file" << endl;
    }
    else
    {
        fstream newstream(path.getStr());
        if (!newstream.is_open())
        {
            ofstream openFile(path.getStr());
            if (!openFile.is_open())
            {
                cout << "file could not open" << endl;
                return;
            }
            else
            {
                openFile.close();
                f_inout.open(path.getStr());
                if (!f_inout.is_open())
                {
                    cout << "Not a valid path fo saving data." << endl;
                    return;
                }
            }
        }
        else
        {
            newstream.clear();

            newstream << f_table;
             
            cout << "Successfully saved in file" << endl;
            newstream.close();
        }
    }
}

void ConsoleHandler::close()
{
    if (!f_inout.is_open())
    {
        cout << "Invalid command" << endl;
        cout << "Try opening a file first. The command is open <filepath>." << endl;
    }
    else
    {
        cout << "Successfully closed" << f_fileName << "file";
        f_fileName = "";
        f_filePath = "";

        f_inout.close();
    }
}

void ConsoleHandler::exit()
{
    if (f_inout.is_open())
    {
        f_inout.close();
    }
    cout << "Exiting the program..." << endl;
    return;
}

void ConsoleHandler::help()
{
    cout << "The following commands are supported :" << endl;
    cout << "open <file>    opens <file>" << endl;
    cout << "close          closes currently opened file" << endl;
    cout << "save           saves the currently open file" << endl;
    cout << "saveas <file>  saves the currently open file in <file>" << endl;
    cout << "help           prints this information" << endl;
    cout << "exit           exists the program" << endl;
}

void ConsoleHandler::handleCommand(String command)
{
    
    char* notConstCommand = new char[command.getLength() + 1];
    strcpy(notConstCommand, command.getStr());

    String commandName;

    for (size_t i = 0; i < command.getLength(); i++)
    {
        if (command[i] != ' ')
            commandName += command[i];
        else
            break;
    }

    String path;
    for (size_t i = commandName.getLength() + 1; i < command.getLength(); i++)
    {
        if (command[i] != '\\')
            path += command[i];
        else
            path += '/';
        
    }



    if (commandName == "open")
    {
        open(path);
    }
    else if (commandName == "save")
    {
        save();
    }
    else if (commandName == "saveas")
    {
        saveAs(path);
    }

    else if (commandName == "close")
    {
        close();
    }
    else if (commandName == "help")
    {
        help();
    }
    else if (commandName == "exit")
    {
        exit();
    }
    else
    {
        cout << "Invalid command. Try again" << endl;
    }
}
