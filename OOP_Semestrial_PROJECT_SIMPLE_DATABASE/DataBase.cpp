#include "DataBase.h"

void DataBase::addTable(Table newTable)
{
	f_dataBase.to_end(newTable);
}

bool DataBase::checkName(String tableName)
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

void DataBase::splitRowValues(Vector<String>& colTypes, String strRow)
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

void DataBase::setColumns(Vector<String> cols, Table& table)
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

void DataBase::getCurrentRow(fstream& newTableData, String& row)
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

String DataBase::getStringValue(String str)
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
                i--;
            }
        }
    }
    else
    {
        result = "NULL";
    }

    return result;
}

void DataBase::importFile(String path)
{
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
            cout << "Headers count must match the number of columns!" << endl;
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

void DataBase::print(String name)
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

void DataBase::showTables()
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

void DataBase::exportFile(String tableName, String fileName)
{

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

void DataBase::countValuesIntable(String tableName, int searchCol, String searchValue)
{
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

void DataBase::renameTable(String oldName, String newName)
{
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

void DataBase::select(int col, String value, String tableName)
{
    for (size_t i = 0; i < f_dataBase.length(); i++)
    {
        if (strcmp(f_dataBase[i].getName().getStr(), tableName.getStr()) == 0)
        {
            f_dataBase[i].printAllRowsWithValueInCol(col, value);
        }
    }
}

void DataBase::describe(String tableName)
{
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

void DataBase::addColumn(String tableName, String columnName, String columnType)
{
    for (size_t i = 0; i < f_dataBase.length(); i++)
    {
        if (tableName == f_dataBase[i].getName())
        {
            bool isThereACol = false;
            for (size_t j = 0; j < f_dataBase[i].getLength(); j++)
            {
                if (f_dataBase[i][j].getHeader() == columnName)
                {
                    isThereACol = true;
                }
            }

            if (isThereACol)
            {
                cout << "There is already a column with such a header" << endl;
                return;
            }

            if (columnType == "string" || columnType == "double" || columnType == "int")
            {
                Column newCol;
                newCol.setHeader(columnName);
                newCol.setType(columnType);

                for (size_t i = 0; i < f_dataBase[0].getLength(); i++)
                {
                    String empty;
                    Cell newCell(columnType, empty);
                    newCol.addCell(newCell);
                }
                f_dataBase[i].addColumn(newCol);
                f_dataBase[i].takeBiggestColumnSizes();
            }
            else
            {
                cout << "Invalid type" << endl;
                return;
            }
        }
    }
}

void DataBase::update(String tableName, int searchCol, String searchValue, int targetCol, String targetValue)
{
    for (size_t i = 0; i < f_dataBase.length(); i++)
    {
        if (tableName == f_dataBase[i].getName())
        {
            if (searchCol - 1 >= f_dataBase[i].getLength() || searchCol - 1 < 0 || targetCol - 1 >= f_dataBase[i].getLength() || targetCol - 1 < 0)
            {
                cout << "Invalid search or target column values!" << endl;
                return;
            }

            for (size_t j = 0; j < f_dataBase[i][searchCol - 1].getLength(); j++)
            {
                String current = f_dataBase[i][searchCol - 1][j].getValue();
                if (current == searchValue)
                {
                    String colType = f_dataBase[i][targetCol - 1].getType();
                    if (colType == "string")
                    {
                        String str = "string";
                        String value = "NULL";
                        if (targetValue[0] != '\"' || targetValue[targetValue.getLength() - 1] != '\"')
                        {
                            Cell copyCell(str, value);
                            f_dataBase[i][targetCol - 1][j] = copyCell;
                        }
                        else
                        {
                            String newVal;
                            for (size_t k = 1; k < targetValue.getLength() - 1; k++)
                            {
                                newVal += targetValue[k];
                            }
                            Cell copyCell(str, newVal);
                            f_dataBase[i][targetCol - 1][j] = copyCell;

                        }
                    }
                    else if (colType == "int")
                    {
                        Cell copyCell(colType, targetValue);

                        f_dataBase[i][targetCol - 1][j] = copyCell;
                    }
                    else if (colType == "double")
                    {
                        Cell copyCell(colType, targetValue);

                        f_dataBase[i][targetCol - 1][j] = copyCell;
                    }
                    else
                    {
                        cout << "No such type can be integrated in the database!" << endl;
                        return;

                    }

                    f_dataBase[i].takeBiggestColumnSizes();
                }
            }
        }
    }
}

void DataBase::deleteRows(String tableName, int searchCol, String searchValue)
{
    Table newTable;
    for (size_t i = 0; i < f_dataBase.length(); i++)
    {
        if (tableName == f_dataBase[i].getName())
        {
            newTable.setName(f_dataBase[i].getName());
            for (size_t j = 0; j < f_dataBase[i].getLength(); j++)
            {

                Column newCol;
                newCol.setHeader(f_dataBase[i][j].getHeader());
                newTable.addColumn(newCol);
            }

            if (searchCol > f_dataBase[i].getLength() || searchCol <= 0)
            {
                cout << "Invalid column!" << endl;
                return;
            }

            for (size_t j = 0; j < f_dataBase[i][searchCol - 1].getLength(); j++)
            {
                String current = f_dataBase[i][searchCol - 1][j].getValue();
                if (current == searchValue)
                {
                    continue;
                }

                for (size_t k = 0; k < f_dataBase[i].getLength(); k++)
                {
                    newTable[k].addCell(f_dataBase[i][k][j]);
                }
            }

            newTable.takeBiggestColumnSizes();

            f_dataBase[i] = newTable;
        }
    }
}

void DataBase::insert(Vector<String> tokens)
{
    String tableName = tokens[1];
    for (size_t i = 0; i < f_dataBase.length(); i++)
    {
        if (tableName == f_dataBase[i].getName())
        {
            if (f_dataBase[i].getLength() != tokens.length() - 2)
            {
                cout << "Invalid parameters!" << endl;
                return;
            }

            for (size_t j = 2; j < tokens.length(); j++)
            {
                String currentColType = f_dataBase[i][j - 2].getType();
                if (currentColType == "string")
                {

                    String value = "NULL";
                    if (tokens[j][0] != '\"' || tokens[j][tokens[j].getLength() - 1] != '\"')
                    {
                        Cell newCell(currentColType, value);
                        f_dataBase[i][j - 2].addCell(newCell);
                    }
                    else
                    {
                        String newVal;
                        for (size_t k = 1; k < tokens[j].getLength() - 1; k++)
                        {
                            newVal += tokens[j][k];
                        }
                        Cell newCell(currentColType, newVal);
                        f_dataBase[i][j - 2].addCell(newCell);

                    }
                }
                else if (currentColType == "int" || currentColType == "double")
                {
                    Cell newCell(currentColType, tokens[j]);
                    f_dataBase[i][j - 2].addCell(newCell);
                }

            }

            f_dataBase[i].takeBiggestColumnSizes();
        }
    }
}

void DataBase::aggregate(String tableName, int searchCol, String searchValue, int targetCol, String operation)
{
    for (size_t i = 0; i < f_dataBase.length(); i++)
    {
        if (tableName == f_dataBase[i].getName())
        {
            if (searchCol - 1 >= f_dataBase[i].getLength() || searchCol - 1 < 0 || targetCol - 1 >= f_dataBase[i].getLength() || targetCol - 1 < 0)
            {
                cout << "Invalid search or target column numbers!" << endl;
                return;
            }

            String searchColType = f_dataBase[i][searchCol - 1].getType();
            String targetColType = f_dataBase[i][targetCol - 1].getType();

            if (searchColType != "double" && searchColType != "int" && targetColType != "double" && targetColType != "int")
            {
                cout << "Column types are not double or int" << endl;
                return;
            }

            for (size_t j = 0; j < f_dataBase[i][searchCol - 1].getLength(); j++)
            {
                String current = f_dataBase[i][searchCol - 1][j].getValue();

                if (current == searchValue)
                {
                    f_dataBase[i][targetCol - 1][j].operate(operation, f_dataBase[i][searchCol - 1][j]);

                }
            }

            f_dataBase[i].takeBiggestColumnSizes();
        }
    }
}

void DataBase::innerjoin(String tableName, int Col, String tableName2, int Col2)
{
    Table newTable;

    if (tableName == tableName2)
    {
        cout << "You cannot innerjoin the same table" << endl;
        return;
    }


    for (size_t i = 0; i < f_dataBase.length(); i++)
    {
        if (tableName == f_dataBase[i].getName())
        {
            if (Col - 1 >= f_dataBase[i].getLength() || Col - 1 < 0)
            {
                cout << "Invalid first table column number!" << endl;
                return;
            }

            for (size_t j = 0; j < f_dataBase.length(); j++)
            {
                if (tableName2 == f_dataBase[j].getName())
                {
                    if (Col2 - 1 >= f_dataBase[j].getLength() || Col2 - 1 < 0)
                    {
                        cout << "Invalid second table column number!" << endl;
                        return;
                    }

                    String newTableName = f_dataBase[i].getName();
                    newTableName += "JOIN";
                    newTableName += ('0' + Col);
                    newTableName += ('0' + Col2);
                    newTableName += f_dataBase[j].getName();

                    newTable.setName(newTableName);

                    String firstTableType = f_dataBase[i][Col - 1].getType();
                    String secondTableType = f_dataBase[j][Col2 - 1].getType();

                    size_t newTableLength = f_dataBase[i].getLength() + f_dataBase[j].getLength() - 2;

                    for (size_t k = 0; k < f_dataBase[i].getLength(); k++)
                    {
                        if (k != Col - 1)
                        {
                            Column newCol;
                            newCol.setHeader(f_dataBase[i][k].getHeader());
                            newTable.addColumn(newCol);
                        }
                    }
                    for (size_t k = 0; k < f_dataBase[j].getLength(); k++)
                    {
                        if (k != Col2 - 1)
                        {
                            Column newCol;
                            newCol.setHeader(f_dataBase[j][k].getHeader());
                            newTable.addColumn(newCol);
                        }
                    }

                    if (firstTableType != secondTableType)
                    {
                        newTable.takeBiggestColumnSizes();
                        f_dataBase.to_end(newTable);
                        cout << newTable.getName() << endl;
                        return;
                    }

                    for (size_t k = 0; k < f_dataBase[i][Col - 1].getLength(); k++)
                    {
                        String currentFirst = f_dataBase[i][Col - 1][k].getValue();
                        for (size_t p = 0; p < f_dataBase[j][Col2 - 1].getLength(); p++)
                        {
                            String currentSecond = f_dataBase[j][Col2 - 1][p].getValue();

                            if (currentFirst == currentSecond)
                            {
                                size_t newTableIndex = 0;
                                for (size_t g = 0; g < f_dataBase[i].getLength(); g++)
                                {
                                    if (g != Col - 1)
                                    {
                                        newTable[newTableIndex].addCell(f_dataBase[i][g][k]);
                                        newTableIndex++;
                                    }
                                }
                                for (size_t g = 0; g < f_dataBase[j].getLength(); g++)
                                {
                                    if (g != Col2 - 1)
                                    {
                                        newTable[newTableIndex].addCell(f_dataBase[j][g][p]);
                                        newTableIndex++;
                                    }
                                }
                            }
                        }
                    }

                    newTable.takeBiggestColumnSizes();
                    f_dataBase.to_end(newTable);
                    cout << newTable.getName() << endl;
                    return;
                }
            }
        }
    }
}

const size_t DataBase::length()
{
    return f_dataBase.length();
}

Table& DataBase::operator[](int i)
{
    return f_dataBase[i];
}
