#pragma once
#include "Table.h"



class ConsoleHandler
{
private:
	fstream f_inout;
	String f_fileName;
	String f_filePath;
	Table f_table;

	void print();
	void open(String path);
	void save();

	void saveAs(String path);
	
	void close();

	void exit();

	void help();
public:




	void handleCommand(String command);


};