#include"Console.h"
#include"./transform.h"
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
int main()
{
	//³õÊ¼»¯
	Console* con = Console::getInstance();
	AfxIO* afxIO = AfxIO::getInstance();
	OrangeCuiInit();
	afxIO->CreativeResultFile(false);
	con->printAt(0, ColorString("Initialization Success\n",Color::BRIGHTBLUE));
	con->setCursorPosition(0, 17);
	con->refresh();
	system("pause");

	bool cycles = true;
	while (cycles) {
		int userChoice = 0;
		con->clear();
		cycles = afxIO->ScreenMenu(&userChoice);
		if (userChoice) {
			int totalTest = 0, totalRight = 0;
			for (int i = 0; i < 7; i++) {
				string InputCache;
				cin >> InputCache;
				totalRight += (transform(InputCache,userChoice) ? 1 : 0);
				totalTest++;
			}
			afxIO->RecordResult(userChoice, totalRight, totalTest);
		}
	}
	return 0;
}