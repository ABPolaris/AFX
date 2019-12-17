#pragma once
#include <iostream>
#include <fstream>
#include <string>
class AfxIO {
public:
	static AfxIO* getInstance();
	void CreativeResultFile(bool force);
	void InquireResult();
	void RecordResult(int standNum,int rightTimes,int totalTimes);
	void ScreenHelp();
	//void RefreshResultFile();
	bool ScreenMenu(int* yy);
	int InputNumber(std::string inputNum);
	int InputChoice(std::string inputStr);
private:
	AfxIO(){}
	~AfxIO(){}
	static AfxIO* instance;
};
