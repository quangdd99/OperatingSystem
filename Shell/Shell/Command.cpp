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
	v.push_back("EXE            Execute program.");
	return v;
}

vector<string> Command::getTutorial() {
	return tutorial;
}

vector<string> Command::getCommand() {
	return command;
}

void Command::help(string data) {
	if (data != "") {
		toUpperCase(data);
		vector<string> command = getCommand();
		for (int i = 0; i < command.size();++i) if (data == command[i]) {
			cout << getTutorial()[i] << endl;
			return;
		}
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
void Command::dir(string path){
	int cn = 0;
	string search_path = "C:\\Users\\trand";
	WIN32_FIND_DATA fd;
	HANDLE hFind = ::FindFirstFile((LPCWSTR)search_path.c_str(), &fd);
	if (hFind != INVALID_HANDLE_VALUE) {
		do {
			if (!(fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
				cout << fd.cFileName << "\t";
				cn++;
				if (cn % 5 == 0) cout << endl;
			}
		} while (::FindNextFile(hFind, &fd));
		::FindClose(hFind);
	}
	cout << endl;
}
void Command::startProgram(LPCSTR lpApplicationName){
	// additional information
	STARTUPINFOA si;
	PROCESS_INFORMATION pi;

	// set the size of the structures
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));

	// start the program up
	CreateProcessA
	(
		lpApplicationName,   // the path
		NULL,                // Command line// tham số dòng lệnh
		NULL,                   // Process handle not inheritable
		NULL,                   // Thread handle not inheritable
		FALSE,                  // Set handle inheritance to FALSE
		CREATE_NEW_CONSOLE,     // Opens file in a separate console
		NULL,           // Use parent's environment block
		NULL,           // Use parent's starting directory 
		&si,            // Pointer to STARTUPINFO structure
		&pi           // Pointer to PROCESS_INFORMATION structure
		);
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);
}
void Command::exe(string applicationName){
	startProgram(applicationName.c_str());
}
void Command::date(){
	time_t now = time(0);
	char dt[26];
	ctime_s(dt, sizeof(dt), &now);
	cout << "The local date and time is: " << dt << endl;
	tm gmtm;
	gmtime_s(&gmtm, &now);
	asctime_s(dt, sizeof dt, &gmtm);
	cout << "The UTC date and time is:" << dt << endl;
}
void Command::syntax(string command) {
	string prefix = command.substr(0, command.find_first_of(' '));
	string data = "";
	if (command.find_first_of(' ')!=-1) 
	data = command.substr(command.find_first_of(' ') + 1,command.length());
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
		cout << "Bye bye" << endl;
		exit(0); break;
	case 2:
		help(data); break;
	case 3:
		dir(data); break;
	case 4:
		date(); break;
	case 7:
		ClearScreen(); break;
	case 9:
		exe(data); break;
	default: "syntax error";
		break;
	}
}
