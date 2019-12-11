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
	//con->resize(60, 18);
}
void update() {
	Console* con = Console::getInstance();
	static int screenUpdateCounter = 0;
	//һ��ˢ��һ����ʾ
	if (screenUpdateCounter == 0)
		con->refresh();
	/*�����Ǵ��뿪ʼ*/
	time_t now = time(0);
	char* dt = ctime(&now);
	con->printAt(0, ColorString(dt, Color::BRIGHTYELLOW));
	/*�����Ǵ������*/
	screenUpdateCounter++;
	screenUpdateCounter %= 60;
}
int main()
{
	//��ʼ��
	Console* con = Console::getInstance();
	AfxIO* afxIO = AfxIO::getInstance();
	OrangeCuiInit();
	afxIO->CreativeResultFile();
	con->printAt(0, ColorString("Create Success\n",Color::BRIGHTBLUE));
	con->refresh();


	//con->setCursorPosition(1, 18);
	//afxIO->InquireResult();
	system("pause");
	return 0;
}