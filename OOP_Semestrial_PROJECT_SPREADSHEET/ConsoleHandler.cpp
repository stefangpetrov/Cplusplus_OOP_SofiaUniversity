#include "ConsoleHandler.h"

void ConsoleHandler::print()
{
    if (!f_inout.is_open())
    {
        cout << "There is not a table thats been loaded yet. Try opening a file first!" << endl;
    }
    else
    {
        cout << f_table;
    }
}

void ConsoleHandler::open(String path)
{
    char* PATH = nullptr;
    PATH = new char[path.getLength() + 1];

    strcpy(PATH, path.getStr());

    if (f_inout.is_open())
    {
        cout << "Already opened a file." << endl;
        return;
    }
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

    while (!f_inout.eof())

    {
        char c;
        String strRow;

        while (f_inout.get(c))
        {
            if ('\n' == c || '\r' == c)
            {
                break;
            }
            else
            {               
                strRow += c;
            }

        }       
        
        if (strRow.getLength() == 0)
        {
            CellRow emptyRow;
            f_table.addRow(emptyRow);
        }
        else
        {
            CellRow nonEmptyRow;
            String value;

            for (size_t i = 0; i < strRow.getLength(); i++)
            {
                if (strRow[i] == '\"' && i < strRow.getLength() - 1)
                {
                    value += '\"';
                    i++;
                    bool isValidStr = false;
                    for (; i < strRow.getLength(); i++)
                    {
                        
                        if (i < strRow.getLength() - 2)
                        {
                            if (strRow[i] == '\\' && strRow[i + 1] == '\"')
                            {
                                value += "\"";
                                
                                i++;
                                continue;
                            }
                            else if (strRow[i] == '\\' && strRow[i + 1] == '\\')
                            {
                                int counter = 0;
                                while (i < strRow.getLength() - 1 && strRow[i] == '\\')
                                {
                                    counter++;
                                    i++;
                                    if (counter % 2 == 0 && strRow[i] != '\"')
                                    {
                                        value += "\\";
                                    }
                                }

                                if (counter % 2 == 0 && strRow[i] == '\"')
                                {
                                    value = "";
                                    break;
                                }
                                else if(counter % 2 == 1 && strRow[i] != '\"')
                                {
                                    value = "";
                                    break;
                                }
                                else if (counter % 2 == 1 && strRow[i] == '\"')
                                {
                                    value += "\"";
                                }
                                    
                                
                                //i++;
                                continue;
                            }
                            
                        }
                        
                        value += strRow[i];
                        
                        if (strRow[i] == '\"' && strRow[i - 1] != '\\')
                        {
                            if (i < strRow.getLength() - 2)
                            {
                                if (strRow[i + 1] != ' ' && strRow[i + 1] != ',')
                                {
                                    break;
                                }
                            }
                            isValidStr = true;
                            break;
                        }
                        if (strRow[i] == '\\' && strRow[i - 1] != '\\')
                        {
                            
                            break;
                        }
                        
                        
                    }
                    if (!isValidStr)
                    {
                        value = "";
                    }
                    if(i == strRow.getLength() - 1)
                    {
                        Cell currentCell(value);
                        nonEmptyRow.addCell(currentCell);
                    }
                }
                else
                {
                    
                    if (strRow[i] != ',' && strRow[i] != ' ')
                    {
                        value += strRow[i];
                        if (i == strRow.getLength() - 1)
                        {
                            Cell currentCell(value);
                            nonEmptyRow.addCell(currentCell);
                        }
                    }
                    else if(strRow[i] == ',')
                    {
                        Cell currentCell(value);

                        value = "";
                        nonEmptyRow.addCell(currentCell);
                        if (i + 1 < strRow.getLength() - 1)
                        {
                            while (strRow[i + 1] == ' ')
                                i++;
                        }


                    }
                    if (i == strRow.getLength() - 1 && strRow[i] == ',')
                    {
                        Cell currentCell;
                        nonEmptyRow.addCell(currentCell);
                    }
                }
                
                
            }
            f_table.addRow(nonEmptyRow);
        }
    }

    f_table.addCellsWhereNeeded();
    f_table.takeBiggestColumnSizes();
    
    if (f_table.signalMistakes())
    {
        f_table = Table();
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

        f_inout << f_table;
        cout << "Successfully saved in " << f_fileName << " file" << endl;
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
                    newstream << f_table;
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
        cout << "Successfully closed" << f_fileName << " file" <<endl;
        f_fileName = "";
        f_filePath = "";
        f_table = Table();
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
        path += command[i];
        
    }


    
    if (commandName == "open")
    {
        open(path);
    }
    else if (commandName == "print")
    {

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
