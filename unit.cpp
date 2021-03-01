#include "unit.h"


unit::unit(int x_0, int y_0, char c_0)
{
	x = x_0;
	y = y_0;
	pic = c_0;
}


void unit::gotoxy(int x, int y) {
	COORD pos;
	HANDLE houtput;
	pos.X = x;
	pos.Y = y;
	houtput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(houtput, pos);
};
void unit::show() {
	gotoxy(x, y);
	cout << pic;
};
void unit::erase() {
	gotoxy(x, y);
	cout << ' ';
};