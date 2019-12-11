#include "./AFXIO.h"
using namespace std;
AfxIO* AfxIO::instance = nullptr;
AfxIO* AfxIO::getInstance()
{
	if (instance == nullptr)
		instance = new AfxIO();
	return instance;
}
void AfxIO::CreativeResultFile() {
	std::ofstream ResOutput("./Result.log");
	ResOutput << "Total:" << endl;
	ResOutput << "2bTr:" << endl;
	ResOutput << "2bFa:" << endl;
	ResOutput << "10Tr:" << endl;
	ResOutput << "10Fa:" << endl;
	ResOutput << "16Tr:" << endl;
	ResOutput << "16Fa:" << endl;
}