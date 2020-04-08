#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include <Windows.h>
#include <string>

using namespace std;
class Command {
private:
	vector<string> command = {"ECHO","EXIT","HELP","DIR","DATE","CD","COUNT","CLEAR","MKFILE"};
public:
	Command();
	vector<string> getListCommand();
	vector<string> getCommand();
	void syntax(string command);
	void echo(string data);
	void help(string data);
	void mkfile(string path);
	void ClearScreen();
};