#pragma once
#include<iostream>
#include<Windows.h>
#include <vector>
#include <time.h>
using namespace std;

class unit {
public:

	unit(int x_0=0, int y_0=0, char c_0='$');

	int x;
	int y;
	char pic;
	void gotoxy(int x, int y);
	void show();
	void erase();
};
