#include "print.h"
#include <conio.h>
/*prent���캯��*/
print::print(int w0, int h0)
{
	w = w0;
	h = h0;
}
//���ƽ��溯��
void print::prin() {
	setwindow(w,h);

	gotoxy(w / 2 - 12, (h / 2-3));
	color(6);
	cout << "<<̰���ߴ���ս>>";
	int c0;
	while (1)
	{
		srand((int)time(0));
		c0 = 1 + rand() % 15;
		color(c0);
		gotoxy(w / 2 - 12, h / 2 - 1);
		cout << "���������ʼ��Ϸ";
		if (_kbhit())
		{
			system("cls");
			break;
		}
	}

	gotoxy(w / 2 - 12, h);
	color(7);
	cout << "��P��ͣ";

	gotoxy(4, 2);
	if (w > 92)
	{
		cout << "��Ϸ�����ҳ���		��д�ߣ�����ǿ";
	}
	else cout << "��Ϸ�����ҳ���";
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
/*��ɫ����*/
void print::color(int c)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
};


/*�������ú���*/
void print::setwindow(int w, int h) {
	system("mode con cols=200 lines=200");
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);//�õ����ھ��
	SetConsoleTitle("�ҳ�");//���ô��ڱ���
	SMALL_RECT rc = { 0,0, w, h };//{Yλ��,Xλ��,��,��}
	SetConsoleWindowInfo(hOut, true, &rc);// ���ô���λ�úʹ�С
	//system("cls");//������Ļ
};
/*���ع��*/
void print::hiden()
{
	HANDLE han = GetStdHandle(-11);
	CONSOLE_CURSOR_INFO cursor;
	cursor.bVisible = 0;
	cursor.dwSize = 1;
	SetConsoleCursorInfo(han, &cursor);
}

