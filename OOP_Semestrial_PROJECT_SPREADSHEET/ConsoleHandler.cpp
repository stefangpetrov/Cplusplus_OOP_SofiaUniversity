#include "ConsoleHandler.h"


void ConsoleHandler::handleCommand(const char* command)
{
	char* notConstCommand = new char[strlen(command) + 1];
	strcpy(notConstCommand, command);

	char*  commandName;

	char ** fileName = new char*[2];
	fileName[0] = nullptr;
	fileName[1] = nullptr;

	int index = 0;

	char* token;
	

	token = strtok(notConstCommand, " ");
	commandName = new char[strlen(token) + 1];


	strcpy(commandName, token);

	token = strtok(NULL, " ");
	
	while (token != NULL)
	{
		fileName[index] = new char[strlen(token) + 1];
		strcpy(fileName[index], token);
		index++;
		token = strtok(NULL, " ");
	}

	if (strcmp(commandName, "open") == 0)
	{
		open(fileName[0]);
	}
	else if (strcmp(commandName, "save") == 0)
	{
		//save();
	}
	else if (strcmp(commandName, "saveas") == 0)
	{
		if (fileName[1] != nullptr)
		{
			//saveAs(fileName[0], fileName[1]);
		}
		else
		{
			//saveAs(fileName[0]);
		}
			
	}
	else if (strcmp(commandName, "close") == 0)
	{
		//close();
	}
	else if (strcmp(commandName, "help") == 0)
	{
		help();
	}
	else if (strcmp(commandName, "exit") == 0)
	{
		exit();
	}
	else
	{
		cout << "Invalid command. Try again" << endl;
	}

	
	if(fileName[0] != nullptr)
		delete[] fileName[0];

	if (fileName[1] != nullptr)
		delete[] fileName[1];

	delete[] fileName;
	
	delete[] notConstCommand;

	delete[] commandName;
}

void ConsoleHandler::help()
{
	cout << "The following commands are supported :" << endl;
	cout << "open <file>	opens <file>"<<endl;
	cout << "close			closes currently opened file"<<endl;
	cout << "save			saves the currently open file" << endl;
	cout << "saveas <file>	saves the currently open file in <file>" << endl;
	cout << "help			prints this information" << endl;
	cout << "exit			exists the program" << endl;
}

void ConsoleHandler::open(const char* path)
{
	f_input.open(path);

	if (!f_input.is_open())
	{
		f_input.close();
		f_output.open(path);

		if (!f_output.is_open())
		{
			cout << "not a valid path";
			return;
		}
		f_output.close();


		f_input.open(path);
	}
	

}

void ConsoleHandler::exit()
{
	cout << "Exiting the program..." << endl;
	return;
}
