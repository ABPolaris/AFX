#pragma once
#include <iostream>
#include <fstream>
class AfxIO {
public:
	static AfxIO* getInstance();
	void CreativeResultFile();
	void InquireResult();
	void CheckFile();
private:
	AfxIO(){}
	~AfxIO(){}
	static AfxIO* instance;
	int bAccept, bWrong;
	int tAccept, tWrong;
	int hAccept, hWrong;

};
