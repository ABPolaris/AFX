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
	ResOutput << "Total:1" << endl;
	ResOutput << "2bAc:1" << endl;
	ResOutput << "2bWr:0" << endl;
	ResOutput << "10Ac:0" << endl;
	ResOutput << "10Wr:0" << endl;
	ResOutput << "16Ac:0" << endl;
	ResOutput << "16Wr:0" << endl;
	ResOutput.close();
}
void CheckFile() {

}
void AfxIO::InquireResult() {
	ifstream ResInput("./Result.log");
	for (int i = 0; i <= 6; i++) {
		string cache;
		ResInput >> cache;
		cout << cache;
	}
	
	ResInput.close();
}