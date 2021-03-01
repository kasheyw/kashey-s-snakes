#include "print.h"
#include <conio.h>
/*prent构造函数*/
print::print(int w0, int h0)
{
	w = w0;
	h = h0;
}
//绘制界面函数
void print::prin() {
	setwindow(w,h);

	gotoxy(w / 2 - 12, (h / 2-3));
	color(6);
	cout << "<<贪吃蛇大作战>>";
	int c0;
	while (1)
	{
		srand((int)time(0));
		c0 = 1 + rand() % 15;
		color(c0);
		gotoxy(w / 2 - 12, h / 2 - 1);
		cout << "按任意键开始游戏";
		if (_kbhit())
		{
			system("cls");
			break;
		}
	}

	gotoxy(w / 2 - 12, h);
	color(7);
	cout << "按P暂停";

	gotoxy(4, 2);
	if (w > 92)
	{
		cout << "游戏名：乱吃蛇		编写者：严自强";
	}
	else cout << "游戏名：乱吃蛇";
	color(7);

	for (int y = 1; y <= h-1; y++)
	{
		for (int x = 3; x <= w-3; x++)
		{
			gotoxy(x, y);
			if (x==3 || x == w-3)
			{
				cout<<'|';
			}
			else if (y == 3 || y == 1 || y == h-1)
			{
				cout<<'-';
			}
		}
	}
};
/*颜色函数*/
void print::color(int c)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
};


/*窗口设置函数*/
void print::setwindow(int w, int h) {
	system("mode con cols=200 lines=200");
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);//得到窗口句柄
	SetConsoleTitle("乱吃");//设置窗口标题
	SMALL_RECT rc = { 0,0, w, h };//{Y位置,X位置,宽,高}
	SetConsoleWindowInfo(hOut, true, &rc);// 重置窗口位置和大小
	//system("cls");//清理屏幕
};
/*隐藏光标*/
void print::hiden()
{
	HANDLE han = GetStdHandle(-11);
	CONSOLE_CURSOR_INFO cursor;
	cursor.bVisible = 0;
	cursor.dwSize = 1;
	SetConsoleCursorInfo(han, &cursor);
}

