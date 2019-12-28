
#include "transform.h"
using namespace std;
bool transform2()
{
	
	Console* con = Console::getInstance();
	con->clear();
	int f1, a1, a2, t, p, f, s, i, l, q, x , h=0;
	char a[20];
	string r = "";
	string b;
	q = (int)pow(2, 10) - 1;
	a1 = rand() % q + 1;
	a2 = rand() % q + 1;
	p = rand() % 4 + 1;
	f1 = a1;
	s = -1;
	while (f1 != 0)
	{
		t = f1 % 2;
		s = s + 1;
		a[s] = 48 + t;
		f1 = f1 / 2;
	}
	for (i = s; i >= 0; i--)
		r = r + a[i];
	switch (p) {
	case 1: {
		f = a1 + a2;
		r = r + "+";
		break;
	}
	case 2: {
		f = a1 - a2;
		r = r + "-";
		break;
	}
	case 3: {
		f = a1 * a2;
		r = r + "*";
		break;
	}
	case 4: {
		f = a1 / a2;
		r = r + "/";
		break;
	}
	}
	con->refresh();
	f1 = a2;
	s = -1;
	while (f1 != 0)
	{
		t = f1 % 2;
		s = s + 1;
		a[s] = 48 + t;
		f1 = f1 / 2;
	}
	l = 1;
	for (i = s; i >= 0; i--)
		r = r + a[i];
	r = r + "=";
	con->printAt(0, ColorString(r, BRIGHTYELLOW));
	con->refresh();
	x = f;
	if (f < 0) f = -f;
	s = -1;
	while (f != 0)
	{
		t = f % 2;
		s = s + 1;
		a[s] = 48 + t;
		f = f / 2;
	}
	if (x < 0) { s = s + 1; a[s] = '-'; }
	L1:l = 1;
	cin >>b;
	for (i = s; i >= 0; i--)
		if (a[i] != b[s - i]) { l = 0; break; }
	if (l == 1)
	{
		con->clear();
		con->printAt(1, ColorString("true\n", RED));
		con->refresh();
		system("pause");
		return true;
	}
	else
	{
		con->printAt(1, ColorString("false\n", RED));
		con->refresh();
		h = h + 1;
		if (h == 2)
		{
			r="";
			for (i = s; i >= 0; i--)
				r = r + a[i];
			con->clear();
			con->printAt(0, ColorString(r, BRIGHTYELLOW));
			con->refresh();
		}
		else 
			goto L1;
		system("pause");
		return false;
	}
}
//con->printAt(0, ColorString("错误\n", RED));
//16进制
bool transform16()
{
	Console* con = Console::getInstance();
	con->clear();
	int f1, a1, a2, t, p, f, s, i, l,h=0;
	char a[8], b[8], t1, t2;
	string r="";
	a1 = rand() % 0xff + 0x1;
	a2 = rand() % 0xff + 0x1;
	p = rand() % 4 + 1;
	f1 = a1;
	s = -1;
	while (f1 != 0)
	{
		t = f1 % 16;
		s = s + 1;
		if (t > 9) a[s] = 55 + t; else a[s] = 48 + t;
		f1 = f1 / 16;
	}
	for (i = s; i >= 0; i--)
		r=r+a[i];
	switch (p) {
	case 1: {
		f = a1 + a2;
		r=r+"+";
		break;
	}
	case 2: {
		f = a1 - a2;
		r=r+ "-";
		break;
	}
	case 3: {
		f = a1 * a2;
		r=r+ "*";
		break;
	}
	case 4: {
		f = a1 / a2;
		r=r+ "/";
		break;
	}
	}
	f1 = a2;
	s = -1;
	while (f1 != 0)
	{
		t = f1 % 16;
		s = s + 1;
		if (t > 9) a[s] = 55 + t; else a[s] = 48 + t;
		f1 = f1 / 16;
	}
	l = 1;
	for (i = s; i >= 0; i--)
		r=r+ a[i];
	r=r+"=";
	con->printAt(0, ColorString(r, BRIGHTYELLOW));
	con->refresh();
	s = -1;
	while (f != 0)
	{
		t = f % 16;
		s = s + 1;
		if (t > 9) a[s] = 55 + t; else a[s] = 48 + t;
		f = f / 16;
	}
	L2:l = 1;
	cin >> b;
	for (i = s; i >= 0; i--)
		if (a[i] != b[s - i]) { l = 0; break; }
	if (l == 1)
	{
		con->clear();
		con->printAt(1, ColorString("true\n", RED));
		con->refresh();
		system("pause");
		return true;
	}
	else
	{
		con->printAt(1, ColorString("false\n", RED));
		con->refresh();
		h = h + 1;
		if (h == 2)
		{
			r = "";
			for (i = s; i >= 0; i--)
				r = r + a[i];
			con->clear();
			con->printAt(0, ColorString(r, BRIGHTYELLOW));
			con->refresh();
		}
		else
			goto L2;
		system("pause");
		return false;
	}
}
//10进制
bool transform10()
{
	Console* con = Console::getInstance();
	con->clear();
	int a1, a2, p, f, s, t, l,pt,h=0;
	stringstream ss,ss1,ss2,ss3;
	string r="",r1="",r2="",r3="",b;
	a1 = rand() % 999 + 1;
	a2 = rand() % 999 + 1;
	p = rand() % 4 + 1;
	ss << a1;
	ss >> r;
	switch (p) {
	case 1: {
		f = a1 + a2;
		r = r + "+";
		break;
	}
	case 2: {
		f = a1 - a2;
		r = r + "-";
		break;
	}
	case 3: {
		f = a1 * a2;
		r = r + "*";
		break;
	}
	case 4: {
		f = a1 / a2;
		r = r + "/";
		break;
	}
	}
	ss1 << a2;
	ss1 >> r1;
	r = r + r1;
	r=  r + "=";
	con->printAt(0, ColorString(r, BRIGHTYELLOW));
	//con->printAt(0, ColorString(r, BRIGHTYELLOW));
	con->refresh();
	ss3 << f;
	ss3 >> r3;
    L3:cin>>b;
	if (b == r3)
	{
		con->clear();
		con->printAt(1, ColorString("true\n", RED));
		con->refresh();
		system("pause");
		return true;
	}
	else
	{
		con->printAt(1, ColorString("false\n", RED));
		con->refresh();
		h = h + 1;
		if (h == 2) {
			con->clear();
			con->printAt(0, ColorString(r3, BRIGHTYELLOW));
			con->refresh();
		}
		else
			goto L3;
		system("pause");
		return false;
	}
}
bool transform(int m)
{
	int p, i, r, s, k,l;
	Console* con = Console::getInstance();
	srand(time(0));
	if (m == 2) {
	      return transform2();
	}
	else if (m == 10) return transform10();
	else if (m == 16) return transform16();
}
