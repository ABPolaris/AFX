#include "./AFXIO.h"
#include "Console.h"
using namespace std;
AfxIO* AfxIO::instance = nullptr;
AfxIO* AfxIO::getInstance(){
	if (instance == nullptr)
		instance = new AfxIO();
	return instance;
}
void AfxIO::CreativeResultFile() {
	ofstream ResOutput("./Result.log");
	for (int i = 0; i < 7; i++) {
		ResOutput <<'0'<< endl;
	}
	ResOutput.close();
}
void AfxIO::InquireResult() {
	Console* con = Console::getInstance();
	ifstream ResInput("./Result.log");
	string cache;
	int ifRefresh;
	
	con->clear();
	ResInput >> cache;
	ifRefresh = stoi(cache);
	con->printAt(1, ColorString("total"+cache, BLUE));
	con->refresh();
	ResInput >> cache;
	con->printAt(2, ColorString("2bit Accepted"+cache, BLUE));
	con->refresh();
	ResInput >> cache;
	con->printAt(3, ColorString("2bit WrongAnswer"+cache, BLUE));
	con->refresh();
	ResInput >> cache;
	con->printAt(4, ColorString("10bit Accepted" + cache, BLUE));
	con->refresh();
	ResInput >> cache;
	con->printAt(5, ColorString("10bit WrongAnswer" + cache, BLUE));
	con->refresh();
	ResInput >> cache;
	con->printAt(6, ColorString("16bit Accepted" + cache, BLUE));
	con->refresh();
	ResInput >> cache;
	con->printAt(7, ColorString("16bit WrongAnswer" + cache, BLUE));
	con->setCursorPosition(0, 8);
	con->refresh();
	if (ifRefresh > 5005) {
		CreativeResultFile();
	}
	ResInput.close();
}
void AfxIO::RecordResult(int standNum, int rightTimes,int totalTimes) {
	int results[10];
	ifstream ResInput("./Result.log");
	string cache;
	for (int i = 0; i < 7; i++) {
		ResInput >> cache;
		results[i] = stoi(cache);
	}
	ResInput.close();
	ofstream ResOutput("./Result.log");
	results[0] += totalTimes;
	results[2 * standNum] += (totalTimes - rightTimes);
	results[2 * standNum - 1] += rightTimes;
	for (int i = 0; i < 7; i++) {
		ResOutput << results[i] << endl;
	}
	ResOutput.close();
}
void AfxIO::ScreenHelp() {
	Console* con = Console::getInstance();
	con->clear();
	con->printAt(0, ColorString("Help and About", BLUE));
	con->setCursorPosition(0, 1);
	con->refresh();
	system("pause");
}
int AfxIO::InputChoice(string inputStr) {
	if (inputStr.length() != 1) {
		return 0;
	}else{
		char inputChar = inputStr[0];
		switch (inputChar){
		case '1':
			return 1;
		break;
		case '2':
			return 2;
		break;
		case '3':
			return 3;
		break;
		case '0':
			return 4;
		break;
		case 'r':
			return 5;
		break;
		case 'q':
			return 6;
		break;
		default:
			return 0;
		break;
		}
	}
	return 0;
}