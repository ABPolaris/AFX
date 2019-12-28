#include "./AFXIO.h"
#include "Console.h"
using namespace std;
AfxIO* AfxIO::instance = nullptr;
AfxIO* AfxIO::getInstance(){
	if (instance == nullptr)
		instance = new AfxIO();
	return instance;
}
void AfxIO::CreativeResultFile(bool force) {
	bool ifFileAppear;
	ifstream ResTest("./Result.log");
	ifFileAppear = ResTest.is_open();
	ResTest.close();
	if (force) {
		ofstream ResOutput("./Result.log");
		for (int i = 0; i < 7; i++) {
			ResOutput << '0' << endl;
		}
		ResOutput.close();
	}
	else if (ifFileAppear) {
		return;
	}
	else {
		ofstream ResOutput("./Result.log");
		for (int i = 0; i < 7; i++) {
			ResOutput << '0' << endl;
		}
		ResOutput.close();
	}
	
}
void AfxIO::InquireResult() {
	Console* con = Console::getInstance();
	ifstream ResInput("./Result.log");
	string cache,resNum[9];
	bool ifNumber=true;
	con->clear();
	int ifRefresh;

	for (int i = 0; i < 7; i++) {
		ResInput >> cache;
		ifNumber = true;
		for (int j = 0; j < cache.length(); j++) {
			if (cache[j] > '9' || cache[j] < '0') {
				ifNumber = false;
			}
		}
		if (ifNumber) {
			resNum[i] = cache;
		}
		else {
			con->printAt(1, ColorString("错误\n", RED));
			con->printAt(2, ColorString("答案文件损坏\n", RED));
			con->printAt(3, ColorString("初始化答案文件中\n", WHITE));
			CreativeResultFile(true);
			con->setCursorPosition(0, 4);
			con->refresh();
			system("pause");
			return;
		}
	}
	ifRefresh = stoi(resNum[0]);

	con->printAt(0, ColorString("答题情况", WHITE));
	con->printAt(1, ColorString("    答题总数", CYAN));
	con->printAt(1, ColorString(resNum[0], BRIGHTBLUE));
	con->printAt(2, ColorString("    二进制计算正确次数", CYAN));
	con->printAt(2, ColorString(resNum[1], BRIGHTBLUE));
	con->printAt(3, ColorString("    二进制计算错误次数", CYAN));
	con->printAt(3, ColorString(resNum[2], BRIGHTBLUE));
	con->printAt(4, ColorString("    十进制计算正确次数", CYAN));
	con->printAt(4, ColorString(resNum[3], BRIGHTBLUE));
	con->printAt(5, ColorString("    十进制计算错误次数", CYAN));
	con->printAt(5, ColorString(resNum[4], BRIGHTBLUE));
	con->printAt(6, ColorString("    十六进制计算正确次数", CYAN));
	con->printAt(6, ColorString(resNum[5], BRIGHTBLUE));
	con->printAt(7, ColorString("    十六进制计算错误次数", CYAN));
	con->printAt(7, ColorString(resNum[6], BRIGHTBLUE));
	con->setCursorPosition(0, 17);
	con->refresh();
	system("pause");
	if (ifRefresh > 5005) {
		con->clear();
		con->printAt(0, ColorString("答题记录已重置", WHITE));
		con->setCursorPosition(0, 17);
		con->refresh();
		system("pause");
		CreativeResultFile(true);
	}
	ResInput.close();
}
void AfxIO::RecordResult(int standNum, int rightTimes,int totalTimes) {
	Console* con = Console::getInstance();
	int results[10];
	if (standNum == 2) {
		standNum = 1;
	}
	else if (standNum == 10) {
		standNum = 2;
	}
	else if (standNum == 16) {
		standNum = 3;
	}
	ifstream ResInput("./Result.log");
	string cache;
	for (int i = 0; i < 7; i++) {
		ResInput >> cache;
		results[i] = stoi(cache);
	}
	ResInput.close();
	ofstream ResOutput("./Result.log");
	results[0] += totalTimes;
	if (results[0] > 5005) {
		con->clear();
		con->printAt(0, ColorString("答题记录已重置", WHITE));
		con->refresh();
		system("pause");
		CreativeResultFile(true);
	}
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
	con->printAt(0, ColorString("Help and About", WHITE));
	con->printAt(1, ColorString("There is a number before every feature", BRIGHTWHITE));
	con->printAt(2, ColorString("Type in it and start the feature\n", BRIGHTWHITE));
	con->printAt(3, ColorString("---\n", BRIGHTWHITE));
	con->printAt(4, ColorString("There are 7 questions in every feature\n", WHITE));
	con->printAt(5, ColorString("You can answer twice\n", WHITE));
	con->printAt(6, ColorString("---\n", WHITE));
	con->printAt(7, ColorString("programmers：\n", CYAN));
	con->printAt(8, ColorString("AkiPolaris\n", BRIGHTBLUE));
	con->printAt(9, ColorString("+1s +1s +1s +1s\n", BRIGHTBLUE));
	con->printAt(10, ColorString("傅文昊\n", BLUE));
	con->setCursorPosition(0, 17);
	con->refresh();
	system("pause");
}
bool AfxIO::ScreenMenu(int* yy) {
	Console* con = Console::getInstance();
	con->printAt(0, ColorString("主菜单\n", WHITE));
	con->printAt(1, ColorString("1. 2进制算数答题\n", BRIGHTCYAN));
	con->printAt(2, ColorString("2. 10进制算数答题\n", BRIGHTCYAN));
	con->printAt(3, ColorString("3. 16进制算数答题\n", BRIGHTCYAN));
	con->printAt(4, ColorString("0. 帮助和关于\n", BRIGHTCYAN));
	con->printAt(5, ColorString("r. 查看答题情况\n", BRIGHTCYAN));
	con->printAt(6, ColorString("q. 退出程序\n", BRIGHTCYAN));
	con->setCursorPosition(0, 17);
	con->refresh();
	string inputStr;
	int inputNum;
	cin >> inputStr;
	inputNum = (InputChoice(inputStr));
	switch (inputNum)
	{
	case 1:
		*yy = 2;
		return true;
		break;
	case 2:
		*yy = 10;
		return true;
		break;
	case 3:
		*yy = 16;
		return true;
		break;
	case 4:
		ScreenHelp();
		return true;
		break;
	case 5:
		InquireResult();
		return true;
		break;
	case 6:
		return false;
		break;
	default:
		con->clear();
		con->printAt(0, ColorString("错误\n", RED));
		con->printAt(1, ColorString("非法输入\n", RED));
		con->printAt(2, ColorString("2s后返回主菜单\n", WHITE));
		con->refresh();
		Sleep(2001);
		return true;
		break;
	}
	return true;
}

int AfxIO::InputNumber(std::string inputNum)
{
	bool ifNumber = true;
	int returnNum;
	for (int j = 0; j < inputNum.length(); j++) {
		if (inputNum[j] > '9' || inputNum[j] < '0') {
			ifNumber = false;
		}
	}
	returnNum = stoi(inputNum);
	return returnNum;
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