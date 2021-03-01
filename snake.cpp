#include "snake.h"
#include <windows.h>
#include <conio.h>
#include <time.h>



snake::snake(int x, int y, int len, int speed, char pic)//, int havefood0, int fc0,int input0=77,int su0=0
{
	sx = x;
	sy = y;
	slen = len;
	sspeed = speed;
	//havefood = havefood0;
	//fc = fc0;
	//input = input0;
	//su = su0;

};

snake::~snake()
{

};
//画出蛇
void snake::showsnake()
{
	for (int i = 0; i < slen; i++)
	{
		/*x = 1 + rand() % (254);
		color(x);*/
		if (x < 16 || x>255)
		{
			x = 17;
		}
		color(x);
		bodypot[i].show();
		color(7);
	}
};

void snake::killsnake()
{
	/*color(0);*/
	bodypot[slen - 1].erase();
};

void snake::move()
{

	hiden();
	srandtime();
	/*初始化数值*/

	moveset();
	gotoxy(p.w / 2 - 12, p.h);
	color(112);
	cout << "按P暂停";






	while (1)
	{
		creatfood();
		/*killsnake();*/
		//判断蛇头是否吃到食物
		if (bodypot[0].x == food1.x && bodypot[0].y == food1.y)
		{
			havefood = 0;
			/*Sleep(20);*/
			for (int i = 0; i < slen; i++)
			{
				x = 1 + rand() % (254);
				color(x);
			
				bodypot[i].show();
				Sleep(30);
			}
			slen += 1;
			sc += 10;
		}
		//判断是否咬到身体
		for (int i = 5; i < slen; i++)
		{
			//cout << bodypot[1].x << endl << bodypot[0].x ;
			if (bodypot[i].x == bodypot[0].x && bodypot[i].y == bodypot[0].y)
			{
				gotoxy(p.w / 2-12, p.h / 2);
				cout << "YOU BITE YOURSELF,Delicious?";

				while (1)
				{
					x = 4 + rand() % (p.w - 7);
					y = 4 + rand() % (p.h - 5);
					gotoxy(x,y);
					x = 1 + rand() % 14;
					color(x);
					cout << "憨憨";
					gotoxy(p.w / 2 - 12, (p.h / 2) - 1);
					cout << "按空格键重新开始";
					/**************************/
					if (_kbhit()) {
						input1 = _getch();
					}
					if (input1 == 32)
					{
						restar();
						break;
					}
					/**************************/
					Sleep(100);
				}
			}
		}

		//判断蛇是否撞墙
		for (int i = 0; i < slen; i++)
		{
			if (bodypot[i].x == 3 || bodypot[i].x == p.w - 4 || bodypot[i].y == 3 || bodypot[i].y == p.h - 1)
			{
				gotoxy((p.w)/2-12, (p.h)/2);
				cout << "YOU BITE WALL，BE CAREFUAL";
			/*	gotoxy(1, 1);
				cout << "w=" << (p.w) / 2 << "  " << "h=" << (p.h) / 2;*/
				while (1)
				{
					x = 4 + rand() % (p.w - 7);
					y = 4 + rand() % (p.h - 5);
					gotoxy(x, y);
					x = 1 + rand() % 14;
					color(x);
					if (sc > 250)
					{
						cout << "牛逼";
						gotoxy(p.w / 2 - 12, (p.h / 2) - 1);
						cout << "按空格键重新开始";
					}
					if (sc <= 250)
					{
						cout << "菜逼";
						gotoxy(p.w / 2 - 12, (p.h / 2) - 1);
						cout << "按空格键重新开始";

					}
					/**************************/
					if (_kbhit()) {
						input1 = _getch();
					}
					if (input1 == 32)
					{
						restar();
						break;
					}
					/**************************/
					Sleep(100);
				}
			}
		}

		//移动后的坐标更新
		for (int i = slen - 1; i > 0; i--)
		{
			bodypot[i] = bodypot[i - 1];
		}



		//输入是否合法判断
		/*
		119	97	115	100	WASD
		72	75	80	77	↑←↓→
		*/
		input0 = input;//备份上次输入
		//判断是否有按键按下
		if (_kbhit()) {
			input1 = _getch();

			//解决按键后延迟问题：方向键会返回两个值********
			if (input1 == 112)
			{
				gotoxy(p.w / 2 - 12, p.h);
				color(112);
				cout << "按P取消暂停";

				while (1)
				{
					input1 = input;
					input1 = _getch();
					if (input1 == 112)
					{
						break;
					}
				}
				gotoxy(p.w / 2 - 12, p.h);
				color(112);
				cout << "按P暂停    ";
			}
			if (input1 == 224)
			{
				input1 = _getch();
			}



			switch (input0)
			{
			case 72://上
				if (input1 == 75 || input1 == 77)
				{
					input = input1;
				}
				break;

			case 75://左
				if (input1 == 72 || input1 == 80)
				{
					input = input1;
				}
				break;
			case 80://下
				if (input1 == 75 || input1 == 77)
				{
					input = input1;
				}
				break;
			case 77://右
				if (input1 == 72 || input1 == 80)
				{
					input = input1;
				}
			default:
				break;
			}
		}

		//蛇头坐标变化（case）：
		//W119   A97   S115	D100 WASD
		switch (input)
		{
		case 72://上
			bodypot[0].y -= 1;
			break;
		case 75://左
			bodypot[0].x -= 1;
			break;
		case 80://下
			bodypot[0].y += 1;
			break;
		case 77://右
			bodypot[0].x += 1;
		default:
			break;
		}
     

		/*绘制得分*/
		gotoxy(p.w-15, 2);
		color(6);
		cout << "得分："<<sc;


		//速度变化
		if (sspeed >=40)
		{
			sspeed = sspeed0 - 20 * (sc / 10);
			gotoxy(1, 1);
			if (sspeed < sspeed0)
			{
				cout << "SPEED UP ";
			}
			su = sc / 10;
			for (int i = 0; i < su; i++)
			{
				cout << "I";
			}
		}
		if (su >= 9)
		{
			gotoxy(10, 1);
			color(79);
			cout << "MAX!!!";
			color(7);
			cout << "---";
		}


		//增加长度
		color(7);
		unit unitpot(bodypot[slen-1].x, bodypot[slen-1].y, '@');
		bodypot.push_back(unitpot);
		showsnake();
		Sleep(sspeed);
		killsnake();
		}
};



void snake::moveset()
{
	p.prin();
	input = 77;//给出初始方向，为向右；
		/*
		119	97	115	100	WASD
		72	75	80	77	↑←↓→
		*/
	havefood = 0;
	sspeed = 200;
	sspeed0 = sspeed;
	su = 0;
	fc = 0;
	slen = 2;
	sc = 0;
	for (int i = 0; i < slen; i++)
	{
		unit unitpot(sx, sy, '+');
		bodypot.push_back(unitpot);
		bodypot[i].x = sx - i;
		//gotoxy(1, 30+i);
		//cout << i << "  " << bodypot[i].x;
	}
}

void snake::creatfood()
{
	  fc = 0;//初始化食物合法信号
//青蛙是否合法以及是否需要创建
	while (1)
	{
		if (havefood != 0)//青蛙是否存在
		{
			break;//若存在则直接跳出生成环节
		}
		food1.createpos(p.w, p.h);
		for (int i = 0; i < slen; i++)
		{
			if (bodypot[i].x == food1.x && bodypot[i].y == food1.y)
			{
				fc += 1;
			}
		}
		if (fc == 0)//获取的坐标合法
		{
			havefood = 1;//青蛙存在
			color(39);
			food1.show();
			color(7);
			break;
		}
		else 
		{
			fc = 0;
		}
	}
}


void snake::restar()
{
	system("cls");//清理屏幕
	color(7);
	bodypot.clear();//清空数组
	moveset();
}