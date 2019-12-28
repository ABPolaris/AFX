
#include "transform.h"
using namespace std;
bool transform2()
{
	
	Console* con = Console::getInstance();
	con->clear();
	int f1, a1, a2, t, p, f, s, i, l, q, x;
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
	l = 1;
	cin >>b;
	for (i = s; i >= 0; i--)
		if (a[i] != b[s - i]) { l = 0; break; }
	if (l == 1)
	{
		con->printAt(1, ColorString("true\n", RED));
		return true;
	}
	else
	{
		con->printAt(1, ColorString("false\n", RED));
		return false;
	}
}
//con->printAt(0, ColorString("错误\n", RED));
//16进制
bool transform16()
{
	Console* con = Console::getInstance();
	con->clear();
	int f1, a1, a2, t, p, f, s, i, l, q, x,rt;
	char a[20];
	string b;
	string r = "";
	q = pow(2, 10) - 1;
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
	r = "";
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
	l = 1;
	cin >> b;
	rt = b.length();
	for (i = 0; i <= rt - 1; i++)
		if ((b[i] >= 'a') && (b[i] <= 'z'))
			b[i] = b[i] - 32;
    for (i = s; i >= 0; i--)
		if (a[i] != b[s - i]) { l = 0; break; }
	if (l == 1)
	{
		con->printAt(1, ColorString("true\n", RED));
		return true;
	}
	else
	{
		con->printAt(1, ColorString("false\n", RED));
		return false;
	}
}
//10进制
bool transform10()
{
	Console* con = Console::getInstance();
	con->clear();
	int a1, a2, p, f, s, t, l,pt,b;
	stringstream ss;
	string r="",r1="";
	a1 = rand() % 999 + 1;
	a2 = rand() % 999 + 1;
	p = rand() % 4 + 1;
	ss << a1;
	ss >> r;
	con->printAt(0, ColorString(r, Color::BRIGHTYELLOW));
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
	ss << a2;
	ss >> r1;
	r = r + r1+"=";
	con->printAt(0, ColorString(r, BRIGHTYELLOW));
	con->refresh();
	if (scanf("%d", &b) == 0) pt = 0; else pt = 1;
	if ((b == f) && (pt==1))
	{
		con->printAt(1, ColorString("true\n", RED));
		return true;
	}
	else
	{
		con->printAt(1, ColorString("false\n", RED));
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
