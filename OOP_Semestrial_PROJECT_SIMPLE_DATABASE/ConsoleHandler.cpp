#include "ConsoleHandler.h"

void ConsoleHandler::open(String path)
{
    if (f_inout.is_open())
    {
        cout << "Already opened a file." << endl;
        return;
    }

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
    token = strtok(PATH, "/\\");

    while (token != NULL)
    {
        f_fileName = token;
        token = strtok(NULL, "/\\");
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
        f_inout.close();
        f_inout.open(f_filePath.getStr(), ios::out | ios::trunc);
        f_inout.close();
        f_inout.open(f_filePath.getStr());

        
        for (size_t i = 0; i < f_dataBase.length(); i++)
        {
            f_inout << f_dataBase[i];
        }
        cout << "Successfully saved in " << f_fileName << " file" << endl;
    }
}

void ConsoleHandler::saveAs(String path)
{
    if (path == f_filePath)
    {
        f_inout << f_fileName << endl;
        for (size_t i = 0; i < f_dataBase.length(); i++)
        {
            f_inout << f_dataBase[i];
        }
        
        cout << "Successfully saved in file" << endl;
    }
    else
    {
        fstream newstream(path.getStr());
        if (!newstream.is_open())
        {
            newstream.close();
            ofstream openFile(path.getStr());
            if (!openFile.is_open())
            {
                cout << "file could not open" << endl;
                return;
            }
            else
            {
                openFile.close();
                newstream.open(path.getStr());
                if (!newstream.is_open())
                {
                    cout << "Not a valid path fo saving data." << endl;
                    return;
                }
                else

                {
                    newstream << f_fileName << endl;
                    for (size_t i = 0; i < f_dataBase.length(); i++)
                    {
                        newstream << f_dataBase[i];
                    }
                    
                    cout << "Successfully saved in file" << endl;
                    newstream.close();
                }
            }
        }
        else
        {
            newstream.close();
            newstream.open(path.getStr(), ios::out | ios::trunc);
            newstream.close();
            newstream.open(path.getStr());

            
            for (size_t i = 0; i < f_dataBase.length(); i++)
            {
                newstream << f_dataBase[i];
            }

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
        cout << "Successfully closed" << f_fileName << " file" << endl;
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

void ConsoleHandler::importFile(String path)
{

    if (!f_inout.is_open())
    {
        cout << "Try opening a file first." << endl;
        return;
    }
    f_dataBase.importFile(path);
}

void ConsoleHandler::print(String name)
{
    if (!f_inout.is_open())
    {
        cout << "There is not a table thats been loaded yet. Try opening a file first!" << endl;
    }
    else
    {
        f_dataBase.print(name);
    }
}

void ConsoleHandler::showTables()
{
    if (!f_inout.is_open())
    {
        cout << "Try opening a file before trying out the whole app!" << endl;
        return;
    }
    f_dataBase.showTables();
}

void ConsoleHandler::exportFile(String tableName, String fileName)
{
    if (!f_inout.is_open())
    {
        cout << "Try opening a file first!" << endl;
        return;
    }

    f_dataBase.exportFile(tableName, fileName);
    
}

void ConsoleHandler::countValuesIntable(String tableName, int searchCol, String searchValue)
{
    if (!f_inout.is_open())
    {
        cout << "Try opening a file first!" << endl;
        return;
    }
 
    f_dataBase.countValuesIntable(tableName, searchCol, searchValue);

}

void ConsoleHandler::renameTable(String oldName, String newName)
{
    if (!f_inout.is_open())
    {
        cout << "Try opening a file first!" << endl;
        return;
    }

    f_dataBase.renameTable(oldName, newName);
}

void ConsoleHandler::select(int col, String value, String tableName)
{
    if (!f_inout.is_open())
    {
        cout << "Try opening a file first!" << endl;
        return;
    }
    else if (value.getLength() < 1 && tableName.getLength() < 1)
    {
        cout << "Incomplete command. Try again" << endl;
        return;
    }
    
    f_dataBase.select(col, value, tableName);
}

void ConsoleHandler::describe(String tableName)
{
    if (!f_inout.is_open())
    {
        cout << "Try opening a file first!" << endl;
        return;
    }

    f_dataBase.describe(tableName);

}

void ConsoleHandler::addColumn(String tableName, String columnName, String columnType)
{
    if (!f_inout.is_open())
    {
        cout << "Try opening a file first!" << endl;
        return;
    }

    f_dataBase.addColumn(tableName, columnName, columnType);

    
}

void ConsoleHandler::update(String tableName, int searchCol, String searchValue, int targetCol, String targetValue)
{
    if (!f_inout.is_open())
    {
        cout << "Try opening a file first!" << endl;
        return;
    }

    f_dataBase.update(tableName, searchCol, searchValue, targetCol, targetValue);
    
}

void ConsoleHandler::deleteRows(String tableName, int searchCol, String searchValue)
{
    if (!f_inout.is_open())
    {
        cout << "Try opening a file first!" << endl;
        return;
    }

    f_dataBase.deleteRows(tableName, searchCol, searchValue);
}

void ConsoleHandler::insert(Vector<String> tokens)
{
    if (!f_inout.is_open())
    {
        cout << "Try opening a file first!" << endl;
        return;
    }

    f_dataBase.insert(tokens);
    
}

void ConsoleHandler::aggregate(String tableName, int searchCol, String searchValue, int targetCol, String operation)
{
    if (!f_inout.is_open())
    {
        cout << "Try opening a file first!" << endl;
        return;
    }

    if (operation != "minimum" && operation != "maximum" && operation != "sum" && operation != "product")
    {
        cout << "Invalid operation!" << endl;
        return;
    }

    f_dataBase.aggregate(tableName, searchCol, searchValue, targetCol, operation);
}

void ConsoleHandler::innerjoin(String tableName, int Col, String tableName2, int Col2)
{
    if (!f_inout.is_open())
    {
        cout << "Try opening a file first!" << endl;
        return;
    }

    f_dataBase.innerjoin(tableName, Col, tableName2, Col2);
}


void ConsoleHandler::handleCommand(String command)
{

    Vector<String> tokens;
    String currToken = "";

    for (size_t i = 0; i < 6; i++)
    {
        tokens.to_end(currToken);
    }

   
    size_t index = 0;
    for (size_t i = 0; i < command.getLength(); i++)
    {
        if (command[i] == ' ')
        {
            index++;
            while (command[i + 1] == ' ')
            {
                i++;
            }
            continue;
        }
        tokens[index] += command[i];

    }



    if (tokens[0] == "open")
    {
        open(tokens[1]);
    }
    
    else if (tokens[0] == "save")
    {
        save();
    }
    else if (tokens[0] == "saveas")
    {
        saveAs(tokens[1]);
    }

    else if (tokens[0] == "close")
    {
        close();
    }
    else if (tokens[0] == "help")
    {
        help();
    }
    else if (tokens[0] == "exit")
    {
        exit();
    }
    else if (tokens[0] == "print")
    {
        print(tokens[1]);
    }
    else if (tokens[0] == "import")
    {
        importFile(tokens[1]);
    }
    else if (tokens[0] == "export")
    {
        exportFile(tokens[1], tokens[2]);
    }
    else if (tokens[0] == "showtables")
    {
        showTables();
    }
    else if (tokens[0] == "describe")
    {
        describe(tokens[1]);
    }
    else if (tokens[0] == "addColumn")
    {
        addColumn(tokens[1], tokens[2], tokens[3]);
    }
    else if (tokens[0] == "update")
    {
        update(tokens[1], atoi(tokens[2].getStr()), tokens[3], atoi(tokens[4].getStr()), tokens[5]);
    }
    else if (tokens[0] == "delete")
    {
        deleteRows(tokens[1], atoi(tokens[2].getStr()), tokens[3]);
    }
    else if (tokens[0] == "insert")
    {
        insert(tokens);
    }
    else if (tokens[0] == "innerjoin")
    {
        innerjoin(tokens[1], atoi(tokens[2].getStr()), tokens[3], atoi(tokens[4].getStr()));
    }
    else if (tokens[0] == "aggregate")
    {
        aggregate(tokens[1], atoi(tokens[2].getStr()), tokens[3], atoi(tokens[4].getStr()), tokens[5]);
    }
    else if (tokens[0] == "count")
    {
        countValuesIntable(tokens[1], atoi(tokens[2].getStr()), tokens[3]);
    }
    else if (tokens[0] == "rename")
    {
        renameTable(tokens[1], tokens[2]);
    }
    else if (tokens[0] == "select")
    {
        select(atoi(tokens[1].getStr()), tokens[2], tokens[3]);
    }
    else
    {
        cout << "Invalid command. Try again" << endl;
    }
}
