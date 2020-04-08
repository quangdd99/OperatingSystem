#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include <Windows.h>
#include <string>
#include <ctime>

using namespace std;

class Command {
private:
	vector<string> command = {"ECHO","EXIT","HELP","DIR","DATE","CD","COUNT","CLEAR","MKFILE","EXE"};
	vector<string> tutorial = {"ECHO [message]","EXIT [exitCode]","HELP [action]","DIR [path]","DATE [none]","CD","COUNT","CLEAR","MKFILE [filename]","EXE [application path]"};
public:
	Command();
	vector<string> getListCommand();
	vector<string> getCommand();
	vector<string> getTutorial();
	void syntax(string command);
	void echo(string data);
	void help(string data);
	void mkfile(string path);
	void ClearScreen();
	void dir(string data);
	void date();
	void startProgram(LPCSTR lpApplicationName);
	void exe(string applicatioName);
};