
#include "transform.h"
using namespace std;
bool transform2(char b[20])
{
	Console* con = Console::getInstance();
	int f1, a1, a2, t, p, f, s, i, l, q, x;
	char a[20];
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
		con->printAt(0, ColorString("%d", a[i], BRIGHTYELLOW));
	switch (p) {
	case 1: {
		f = a1 + a2;
		con->printAt(0, ColorString("+", BRIGHTYELLOW));
		break;
	}
	case 2: {
		f = a1 - a2;
		con->printAt(0, ColorString("-", BRIGHTYELLOW));
		break;
	}
	case 3: {
		f = a1 * a2;
		con->printAt(0, ColorString("*", BRIGHTYELLOW));
		break;
	}
	case 4: {
		f = a1 / a2;
		con->printAt(0, ColorString("/", BRIGHTYELLOW));
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
	for (i = s; i >= 0; i--)
		con->printAt(0, ColorString("%d", a[i], BRIGHTYELLOW));
	con->printAt(0, ColorString("=", BRIGHTYELLOW));
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
bool transform16(char b[20])
{
	Console* con = Console::getInstance();
	int f1, a1, a2, t, p, f, s, i, l, q, x, r;
	char a[20];
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
		con->printAt(0, ColorString("%d", a[i], BRIGHTYELLOW));
	switch (p) {
	case 1: {
		f = a1 + a2;
		con->printAt(0, ColorString("+", BRIGHTYELLOW));
		break;
	}
	case 2: {
		f = a1 - a2;
		con->printAt(0, ColorString("-", BRIGHTYELLOW));
		break;
	}
	case 3: {
		f = a1 * a2;
		con->printAt(0, ColorString("*", BRIGHTYELLOW));
		break;
	}
	case 4: {
		f = a1 / a2;
		con->printAt(0, ColorString("/", BRIGHTYELLOW));
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
	for (i = s; i >= 0; i--)
		con->printAt(0, ColorString("%d", a[i], BRIGHTYELLOW));
	con->printAt(0, ColorString("=", BRIGHTYELLOW));
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
	r = strlen(b);
	for (i = 0; i <= r - 1; i++)
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
bool transform10(int b)
{
	Console* con = Console::getInstance();
	int a1, a2, p, f;
	a1 = rand() % 999 + 1;
	a2 = rand() % 999 + 1;
	p = rand() % 4 + 1;
	con->printAt(0, ColorString("%d", a1, BRIGHTYELLOW));
	switch (p) {
	case 1: {
		f = a1 + a2;
		con->printAt(0, ColorString("+", BRIGHTYELLOW));
		break;
	}
	case 2: {
		f = a1 - a2;
		con->printAt(0, ColorString("-", BRIGHTYELLOW));
		break;
	}
	case 3: {
		f = a1 * a2;
		con->printAt(0, ColorString("*", BRIGHTYELLOW));
		break;
	}
	case 4: {
		f = a1 / a2;
		con->printAt(0, ColorString("/", BRIGHTYELLOW));
		break;
	}
	}
	con->printAt(0, ColorString("=", BRIGHTYELLOW));
	if (b == f)
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
bool transform(char b[20], int m)
{
	int p, i, r, s, k;
	Console* con = Console::getInstance();
	srand(time(0));
	p = 1;
	if (m == 2) return transform2(b);
	else if (m == 10)
	{
		r = strlen(b);
		for (i = 0; i <= r - 1; i++)
			if (b[i] >= 65) p = 0;
		if (p == 1) {
			s = 0;
			k = 0;
			while (s <= r - 1)
			{
				k = k * 10 + b[s] - 48;
				s = s + 1;
			}
			return transform10(k);
		}
		else return false;
	}
	else if (m == 16) return transform16(b);
}
