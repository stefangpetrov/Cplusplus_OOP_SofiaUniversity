#pragma once
#include "Table.h"

class DataBase
{
private:
	Vector<Table> f_dataBase;
	void addTable(Table newTable);
	bool checkName(String tableName);
	void splitRowValues(Vector<String>& colTypes, String strRow);
	void setColumns(Vector<String> cols, Table& table);
	void getCurrentRow(fstream& newTableData, String& row);
	String getStringValue(String str);
public:
	void importFile(String path);

	void print(String name);

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

	void innerjoin(String tableName, int Col, String tableName2, int Col2);


	const size_t length();

	Table& operator[](int i);
};

