#include"Console.h"
#include"./AFXIO.h"
#include<iostream>
#include<algorithm>
#include<memory>
#include<ctime>
#include<Windows.h>
using namespace std;
void OrangeCuiInit() {
	Console* con = Console::getInstance();
	con->init();
	con->resize(60, 18);
	con->refresh();
}
bool ScreenMenu(int *yy) {
	Console* con = Console::getInstance();
	AfxIO* afxIO = AfxIO::getInstance();
	con->printAt(0, ColorString("���˵�\n", GREEN));
	con->printAt(1, ColorString("1. 2��������\n", RED));
	con->printAt(2, ColorString("2. 10��������\n", RED));
	con->printAt(3, ColorString("3. 16��������\n", RED));
	con->printAt(4, ColorString("0. ����\n", RED));
	con->printAt(5, ColorString("r. �鿴�������\n", RED));
	con->printAt(6, ColorString("q. �˳�����\n", RED)); con->refresh();
	con->setCursorPosition(0, 17);
	string inputStr;
	int inputNum;
	cin >> inputStr;
	inputNum = (afxIO->InputChoice(inputStr));
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
		afxIO->ScreenHelp();
		return true;
		break;
	case 5:
		afxIO->InquireResult();
		system("pause");
		return true;
		break;
	case 6:
		return false;
		break;
	default:
		con->clear();
		con->printAt(1, ColorString("�Ƿ�����\n", RED));
		con->printAt(2, ColorString("2s�󷵻����˵�\n", WHITE));
		con->refresh();
		Sleep(2001);
		return true;
		break;
	}
	return true;
}
int main()
{
	//��ʼ��
	Console* con = Console::getInstance();
	AfxIO* afxIO = AfxIO::getInstance();
	OrangeCuiInit();
	afxIO->CreativeResultFile();
	con->printAt(0, ColorString("Initialization Success\n",Color::BRIGHTBLUE));
	con->setCursorPosition(0, 17);
	con->refresh();
	system("pause");

	bool cycles = true;
	while (cycles) {
		int userChoice = 0;
		con->clear();
		cycles = ScreenMenu(&userChoice);
		if (userChoice) {
			int totalTest = 0, totalRight = 0;
			for (int i = 0; i < 7; i++) {
				totalRight += (1 ? 1 : 0);
				totalTest++;
			}
			afxIO->RecordResult(userChoice, totalRight, totalTest);
		}
	}
	return 0;
}