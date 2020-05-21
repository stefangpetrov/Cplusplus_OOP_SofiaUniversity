#include "ConsoleHandler.h"

void ConsoleHandler::splitRowValues(Vector<String>& colTypes, String strRow)
{
    String value;
    for (size_t i = 0; i < strRow.getLength(); i++)
    {
        if (value[0] == '\"')
        {
            for (; i < strRow.getLength(); i++)
            {
                value += strRow[i];
                if (strRow[i] == '\"' && strRow[i - 1] != '\\')
                {
                    i++;
                    break;
                }
                
            }
        }

        if (strRow[i] != ' ')
        {
            value += strRow[i];
            if (i == strRow.getLength() - 1)
            {
                colTypes.to_end(value);
            }
        }
        else
        {
            colTypes.to_end(value);
            
            value = "";
            if (i + 1 < strRow.getLength() - 1)
            {
                while (strRow[i + 1] == ' ')
                    i++;
            }

        }
        
    }


}

void ConsoleHandler::setColumns(Vector<String> cols, Table& table)
{
    for (size_t i = 0; i < cols.length(); i++)
    {
        Column col;
        col.setType(cols[i]);
        if (strcmp(col.getType().getStr(), "ERROR") == 0)
        {
            cout << "Invalid column type" << endl;
            return;
        }
        table.addColumn(col);
    }
}

void ConsoleHandler::getCurrentRow(fstream& newTableData, String& row)
{
    char c;
    while (newTableData.get(c))
    {
        if ('\n' == c || '\r' == c)
        {
            break;
        }
        else
        {
            row += c;
        }

    }
}

bool ConsoleHandler::checkName(String tableName)
{
    for (size_t i = 0; i < f_dataBase.length(); i++)
    {
        if (strcmp(f_dataBase[i].getName().getStr(), tableName.getStr()) == 0)
        {
            return false;
        }
    }
    return true;
}

String ConsoleHandler::getStringValue(String str)
{
    String result = "";
    bool isValidStr = false;

    if (str[0] == '\"' && str[str.getLength() - 1] == '\"')
    {
        for (size_t i = 1; i < str.getLength() - 1; i++)
        {
            if (str[i] != '\"' && str[i] != '\\')
            {
                result += str[i];
            }
            else if (str[i] == '\\')
            {
                int counter = 0;
                while (str[i] == '\\')
                {
                    counter++;
                    i++;
                    if (counter % 2 == 0 && str[i] != '\"')
                    {
                        result += "\\";
                    }
                }

                if (counter % 2 == 0 && str[i] == '\"')
                {
                    result = "NULL";
                    break;
                }
                else if (counter % 2 == 1 && str[i] != '\"')
                {
                    result = "NULL";
                    break;
                }
                else if (counter % 2 == 1 && str[i] == '\"')
                {
                    result += "\"";
                }
            }
        }
    }
    else
    {
        result = "NULL";
    }

    return result;
}


void ConsoleHandler::print(String name)
{
    if (!f_inout.is_open())
    {
        cout << "There is not a table thats been loaded yet. Try opening a file first!" << endl;
    }
    else
    {
        for (size_t i = 0; i < f_dataBase.length(); i++)
        {
            if (strcmp(f_dataBase[i].getName().getStr(), name.getStr()) == 0)
            {
                cout << f_dataBase[i] << endl;
                return;
            }
            
        }

        cout << "No such table in the database!" << endl;
    }
}

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

void ConsoleHandler::importFile(String path)
{

    if (!f_inout.is_open())
    {
        cout << "Try opening a file first." << endl;
        return;
    }
    char* PATH = nullptr;
    PATH = new char[path.getLength() + 1];

    strcpy(PATH, path.getStr());
    fstream newTableData(path.getStr());

    if (!newTableData.is_open())
    {
        cout << "No such file" << endl;
    }
    else
    {
        String tableName;
        char* token;
        token = strtok(PATH, "/\\");
        while (token != NULL)
        {
            tableName = token;
            token = strtok(NULL, "/\\");
        }

        if (!checkName(tableName))
        {
            cout << "There is already a table with such a name in the database!" << endl;
            return;
        }
        Table newTable;
        newTable.setName(tableName);

        String strRow = "";
        
        getCurrentRow(newTableData, strRow);

        if (strRow.getLength() == 0)
        {
            cout << "Cannot import a table without knowing its column types!";
            cout << endl;
            return;
        }

        Vector<String> colTypes;
        
        splitRowValues(colTypes, strRow);
        

        setColumns(colTypes, newTable);
        
        strRow = "";
        getCurrentRow(newTableData, strRow);

        if (strRow.getLength() == 0)
        {

            cout << endl;
            return;
        }

        Vector<String> colHeaders;

        splitRowValues(colHeaders, strRow);

        if (colHeaders.length() != colTypes.length())
        {
            cout << "Headers count must match the number of columns!"<<endl;
            return;
        }

        for (size_t i = 0; i < colHeaders.length(); i++)
        {
            newTable[i].setHeader(colHeaders[i]);
        }

        strRow = "";
        
        bool tooManyArguments = false;

        
        do
        {
            if (newTableData.eof())
            {
                break;
            }
            getCurrentRow(newTableData, strRow);
            Vector<String> rowValues;
            splitRowValues(rowValues, strRow);
            if (rowValues.length() > colHeaders.length())
            {
                tooManyArguments = true;
                break;
            }
            
            int i = 0;
            for (; i < rowValues.length(); i++)
            {
                String currentType = newTable[i].getType();

                if (currentType == "string")
                {
                    String result = getStringValue(rowValues[i]);
                    Cell newCell(currentType, result);
                    newTable[i].addCell(newCell);
                }
                else
                {
                    Cell newCell(currentType, rowValues[i]);
                    newTable[i].addCell(newCell);
                } 
            }
            
            for (; i < colHeaders.length(); i++)
            {
                String currentType = newTable[i].getType();
                String result = "NULL";
                Cell newCell(currentType, result);
                newTable[i].addCell(newCell);
            }

            strRow = "";
            

        } while (!newTableData.eof());

        if (tooManyArguments)
        {
            cout << "Too many arguments in a row. Try importing a valid table." << endl;
            return;
        }
        newTable.takeBiggestColumnSizes();
        f_dataBase.to_end(newTable);
        cout << "Successfully imported a table" << endl;

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

void ConsoleHandler::showTables()
{
    if (!f_inout.is_open())
    {
        cout << "Try opening a file before trying out the whole app!" << endl;
        return;
    }
    else
    {
        if (f_dataBase.length() == 0)
        {
            cout << "There are no tables in the database yet! Try importing one!" << endl;
            return;
        }

        for (size_t i = 0; i < f_dataBase.length(); i++)
        {
            cout << f_dataBase[i].getName() << endl;
        }
    }
}

void ConsoleHandler::exportFile(String tableName, String fileName)
{
    if (!f_inout.is_open())
    {
        cout << "Try opening a file first!" << endl;
        return;
    }

    for (size_t i = 0; i < f_dataBase.length(); i++)
    {
        if (strcmp(f_dataBase[i].getName().getStr(), tableName.getStr()) == 0)
        {
            ofstream out(fileName.getStr());

            if (!out.is_open())
            {
                cout << "Invalid filePath" << endl;
            }
            out << f_dataBase[i];
            cout << "Successfully exported a table to a file" << endl;
            return;
        }

    }


    cout << "Exporting could not happen" << endl;
    
}

void ConsoleHandler::countValuesIntable(String tableName, int searchCol, String searchValue)
{
    if (!f_inout.is_open())
    {
        cout << "Try opening a file first!" << endl;
        return;
    }

    
    for (size_t i = 0; i < f_dataBase.length(); i++)
    {
        if (strcmp(f_dataBase[i].getName().getStr(), tableName.getStr()) == 0)
        {
            if (searchCol >= 1 && searchCol <= f_dataBase[i].getLength())
            {
                cout << "The number of " << searchValue << " in the table is: " << f_dataBase[i].countRowsWithAValue(searchCol, searchValue) << endl;
                return;
            }
            cout << "No such column in the table!" << endl;

        }
    }

}

void ConsoleHandler::renameTable(String oldName, String newName)
{
    if (!f_inout.is_open())
    {
        cout << "Try opening a file first!" << endl;
        return;
    }

    for (size_t i = 0; i < f_dataBase.length(); i++)
    {
        if (strcmp(f_dataBase[i].getName().getStr(), oldName.getStr()) == 0)
        {
            if (checkName(newName) && (newName.getLength() > 0))
            {
                f_dataBase[i].setName(newName);
                cout << "Successfully renamed a table" << endl;
            }
            else
            {
                cout << "You cannot assign a name that already exists in the dataBase or is less than 1 symbols long" << endl;
                return;
            }
        }
        else
        {
            cout << "No such table name in the first place!" << endl;
            return;
        }
    }

    
}

void ConsoleHandler::select(int col, String value, String tableName)
{
    if (!f_inout.is_open())
    {
        cout << "Try opening a file first!" << endl;
        return;
    }
    else if (value.getLength() < 1 && value.getLength() < 1)
    {
        cout << "Incomplete command. Try again" << endl;
        return;
    }
    
    for (size_t i = 0; i < f_dataBase.length(); i++)
    {
        if (strcmp(f_dataBase[i].getName().getStr(), tableName.getStr()) == 0)
        {
            f_dataBase[i].printAllRowsWithValueInCol(col, value);
        }
    }
}

void ConsoleHandler::describe(String tableName)
{
    if (!f_inout.is_open())
    {
        cout << "Try opening a file first!" << endl;
        return;
    }

    for (size_t i = 0; i < f_dataBase.length(); i++)
    {
        if (tableName == f_dataBase[i].getName())
        {
            for (size_t j = 0; j < f_dataBase[i].getLength(); j++)
            {
                cout << "col " << j + 1 << "is of type " << f_dataBase[i][j].getType() << endl;
            }
        }
    }

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
