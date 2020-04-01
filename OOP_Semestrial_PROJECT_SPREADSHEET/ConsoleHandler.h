#pragma once
#include "Table.h"
#include <fstream>


class ConsoleHandler
{
private:
	ifstream f_input;
	ofstream f_output;
	bool isClosed;

	void save();
	void saveAs(const char* path, const char* fileName);

	void saveAs(const char* path);

	void help();

	void open(const char* path);
	void close();

	void exit();
public:
	

	void handleCommand(const char* command);

	
};
