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
			con->clear();
			con->printAt(1, ColorString("����\n", RED));
			con->printAt(2, ColorString("���ļ���\n", RED));
			con->printAt(3, ColorString("��ʼ�����ļ���\n", WHITE));
			CreativeResultFile(true);
			con->setCursorPosition(0, 4);
			con->refresh();
			system("pause");
			return;
		}
	}
	ifRefresh = stoi(resNum[0]);
	
	con->clear();
	con->printAt(1, ColorString("�������", WHITE));
	con->printAt(1, ColorString("��������"+resNum[0], CYAN));
	con->printAt(2, ColorString("�����Ƽ���-��ȷ����"+ resNum[1], CYAN));
	con->printAt(3, ColorString("�����Ƽ���-�������"+ resNum[2], CYAN));
	con->printAt(4, ColorString("ʮ���Ƽ���-��ȷ����" + resNum[3], CYAN));
	con->printAt(5, ColorString("ʮ���Ƽ���-�������" + resNum[4], CYAN));
	con->printAt(6, ColorString("ʮ�����Ƽ���-��ȷ����" + resNum[5], CYAN));
	con->printAt(7, ColorString("ʮ�����Ƽ���-�������" + resNum[6], CYAN));
	con->setCursorPosition(0, 8);
	con->refresh();
	if (ifRefresh > 5005) {
		CreativeResultFile(true);
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
	con->printAt(0, ColorString("Help and About", WHITE));
	con->setCursorPosition(0, 1);
	con->refresh();
	system("pause");
}
bool AfxIO::ScreenMenu(int* yy) {
	Console* con = Console::getInstance();
	con->printAt(0, ColorString("���˵�\n", WHITE));
	con->printAt(1, ColorString("1. 2��������\n", BRIGHTCYAN));
	con->printAt(2, ColorString("2. 10��������\n", BRIGHTCYAN));
	con->printAt(3, ColorString("3. 16��������\n", BRIGHTCYAN));
	con->printAt(4, ColorString("0. �����͹���\n", BRIGHTCYAN));
	con->printAt(5, ColorString("r. �鿴�������\n", BRIGHTCYAN));
	con->printAt(6, ColorString("q. �˳�����\n", BRIGHTCYAN));
	con->setCursorPosition(0, 17);
	con->refresh();
	string inputStr;
	int inputNum;
	cin >> inputStr;
	inputNum = (InputChoice(inputStr));
	switch (inputNum)
	{
	case 1:
		*yy = 1;
		return true;
		break;
	case 2:
		*yy = 2;
		return true;
		break;
	case 3:
		*yy = 3;
		return true;
		break;
	case 4:
		ScreenHelp();
		return true;
		break;
	case 5:
		InquireResult();
		system("pause");
		return true;
		break;
	case 6:
		return false;
		break;
	default:
		con->clear();
		con->printAt(0, ColorString("����\n", RED));
		con->printAt(1, ColorString("�Ƿ�����\n", RED));
		con->printAt(2, ColorString("2s�󷵻����˵�\n", WHITE));
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