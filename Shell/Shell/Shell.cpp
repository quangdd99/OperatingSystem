// Shell.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Command.h"


void syntax(string command) {
	
}
void echo(string data) {
	cout << data;
}

int main()
{
	Command command;
	string s;
	while (true)
	{
		cout << "OSShell #>";
		getline(cin, s, '\n');
		command.syntax(s);
	}
}