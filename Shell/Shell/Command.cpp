#include "Command.h"

void  toUpperCase(std::string& str)
{
	std::transform(str.begin(), str.end(), str.begin(), ::toupper);
}

Command::Command() {

}
vector<string> Command::getListCommand() {
	vector<string> v;
	v.push_back("ECHO           Displays messages, or turns command echoing on or off.");
	v.push_back("EXIT           Quits the Shell program.");
	v.push_back("HELP           Provides Help information for Shell commands.");
	v.push_back("DIR            Displays a list of files and subdirectories in a directory.");
	v.push_back("DATE           Displays or sets the date.");
	v.push_back("CD             Displays the name of or changes the current directory.");
	v.push_back("COUNT          Start child.exe.");
	v.push_back("CLEAR          Clear the screen.");
	v.push_back("MKFILE         Create file.");
	return v;
}

vector<string> Command::getCommand() {
	return command;
}

void Command::help(string data) {
	if (data == "") {
		cout << "syntax error";
		return;
	}
	vector<string> help = getListCommand();
	cout << "*****************************************" << endl << endl;
	cout << "        WELCOME TO MY WORLD" << endl << endl;
	cout << "*****************************************" << endl << endl;
	for (string s : help) cout << s << endl;
	cout << endl;
}
void Command::echo(string data) {
	cout << data << endl;
}
void Command::mkfile(string path) {

}
void SetCursorPosition(short int x, short int y)
{
	HANDLE Output = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD Pos = { x, y };
	SetConsoleCursorPosition(Output, Pos);
}
void Command::ClearScreen()
{
	CONSOLE_SCREEN_BUFFER_INFO info{ };
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hOutput, &info);
	DWORD written;
	FillConsoleOutputCharacter(hOutput, ' ', info.dwSize.X * info.dwSize.Y, COORD{ 0, 0 }, &written);
	SetCursorPosition(0, 0);
}
void Command::syntax(string command) {
	string prefix = command.substr(0, command.find_first_of(' '));
	string data = command.substr(command.find_first_of(' ') + 1,command.length());
	toUpperCase(prefix);
	vector<string> commands = getCommand();
	int pos = -1;
	for (int i = 0; i < commands.size();++i) {
		if (prefix == commands[i]) pos = i;
	}

	switch (pos)
	{
	case 0:
		echo(data); break;
	case 1:
		exit(0); break;
	case 2:
		help(data); break;
	case 7:
		ClearScreen(); break;
	default: "syntax error";
		break;
	}
}
