#pragma once
#include <iostream>
#include <fstream>
class AfxIO {
public:
	static AfxIO* getInstance();
	void CreativeResultFile();
private:
	AfxIO(){}
	~AfxIO(){}
	static AfxIO* instance;
};