/*
BSD 3-Clause License

Copyright (c) 2020, ABPolaris
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its
   contributors may be used to endorse or promote products derived from
   this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/

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
				totalRight += (transform(userChoice) ? 1 : 0);
				totalTest++;
			}
			afxIO->RecordResult(userChoice, totalRight, totalTest);
		}
	}
	return 0;
}