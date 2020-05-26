#pragma once
#include "Table.h"



class ConsoleHandler
{
private:
	fstream f_inout;
	String f_fileName;
	String f_filePath;
	Vector<Table> f_dataBase;

	void splitRowValues(Vector<String>& rowValues, String strRow);
	void setColumns(Vector<String> cols, Table& table);
	void getCurrentRow(fstream& newTableData, String& row);
	bool checkName(String tableName);
	String getStringValue(String str);

	void print(String name);
	void open(String path);
	void save();
	
	void importFile(String path);

	void saveAs(String path);

	void close();

	void exit();

	void help();

	void showTables();

	void exportFile(String tableName, String fileName);

	void countValuesIntable(String tableName, int searchCol, String searchValue);

	void renameTable(String oldName, String newName);

	void select(int col, String value, String tableName);

	void describe(String tableName);

	void addColumn(String tableName, String columnName, String columnType);

	void update(String tableName, int searchCol, String searchValue, int targetCol, String targetValue);

	void deleteRows(String tableName, int searchCol, String searchValue);

	void insert(Vector<String> tokens);

	void aggregate(String tableName, int searchCol, String searchValue, int targetCol, String operation);
public:




	void handleCommand(String command);


};