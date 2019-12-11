#include"Console.h"
#include"./AFXIO.h"
#include<iostream>
#include<algorithm>
#include<memory>
#include<ctime>
#include<Windows.h>
using namespace std;
void update()
{
	Console* con = Console::getInstance();
	static int screenUpdateCounter = 0;
	//一秒刷新一次显示
	if (screenUpdateCounter == 0)
		con->refresh();
	/*这里是代码开始*/
	time_t now = time(0);
	char* dt = ctime(&now);
	con->printAt(0, ColorString(dt, Color::BRIGHTYELLOW));
	/*这里是代码结束*/
	screenUpdateCounter++;
	screenUpdateCounter %= 60;
}
int main()
{
	Console* con = Console::getInstance();
	AfxIO* afxIO = AfxIO::getInstance();
	con->init();
	update();
	afxIO->CreativeResultFile();
	printf_s("%s", "success\n");
	return 0;
}