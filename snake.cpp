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
//������
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
	/*��ʼ����ֵ*/

	moveset();
	gotoxy(p.w / 2 - 12, p.h);
	color(112);
	cout << "��P��ͣ";






	while (1)
	{
		creatfood();
		/*killsnake();*/
		//�ж���ͷ�Ƿ�Ե�ʳ��
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
		//�ж��Ƿ�ҧ������
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
					cout << "����";
					gotoxy(p.w / 2 - 12, (p.h / 2) - 1);
					cout << "���ո�����¿�ʼ";
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

		//�ж����Ƿ�ײǽ
		for (int i = 0; i < slen; i++)
		{
			if (bodypot[i].x == 3 || bodypot[i].x == p.w - 4 || bodypot[i].y == 3 || bodypot[i].y == p.h - 1)
			{
				gotoxy((p.w)/2-12, (p.h)/2);
				cout << "YOU BITE WALL��BE CAREFUAL";
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
						cout << "ţ��";
						gotoxy(p.w / 2 - 12, (p.h / 2) - 1);
						cout << "���ո�����¿�ʼ";
					}
					if (sc <= 250)
					{
						cout << "�˱�";
						gotoxy(p.w / 2 - 12, (p.h / 2) - 1);
						cout << "���ո�����¿�ʼ";

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

		//�ƶ�����������
		for (int i = slen - 1; i > 0; i--)
		{
			bodypot[i] = bodypot[i - 1];
		}



		//�����Ƿ�Ϸ��ж�
		/*
		119	97	115	100	WASD
		72	75	80	77	��������
		*/
		input0 = input;//�����ϴ�����
		//�ж��Ƿ��а�������
		if (_kbhit()) {
			input1 = _getch();

			//����������ӳ����⣺������᷵������ֵ********
			if (input1 == 112)
			{
				gotoxy(p.w / 2 - 12, p.h);
				color(112);
				cout << "��Pȡ����ͣ";

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
				cout << "��P��ͣ    ";
			}
			if (input1 == 224)
			{
				input1 = _getch();
			}



			switch (input0)
			{
			case 72://��
				if (input1 == 75 || input1 == 77)
				{
					input = input1;
				}
				break;

			case 75://��
				if (input1 == 72 || input1 == 80)
				{
					input = input1;
				}
				break;
			case 80://��
				if (input1 == 75 || input1 == 77)
				{
					input = input1;
				}
				break;
			case 77://��
				if (input1 == 72 || input1 == 80)
				{
					input = input1;
				}
			default:
				break;
			}
		}

		//��ͷ����仯��case����
		//W119   A97   S115	D100 WASD
		switch (input)
		{
		case 72://��
			bodypot[0].y -= 1;
			break;
		case 75://��
			bodypot[0].x -= 1;
			break;
		case 80://��
			bodypot[0].y += 1;
			break;
		case 77://��
			bodypot[0].x += 1;
		default:
			break;
		}
     

		/*���Ƶ÷�*/
		gotoxy(p.w-15, 2);
		color(6);
		cout << "�÷֣�"<<sc;


		//�ٶȱ仯
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


		//���ӳ���
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
	input = 77;//������ʼ����Ϊ���ң�
		/*
		119	97	115	100	WASD
		72	75	80	77	��������
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
	  fc = 0;//��ʼ��ʳ��Ϸ��ź�
//�����Ƿ�Ϸ��Լ��Ƿ���Ҫ����
	while (1)
	{
		if (havefood != 0)//�����Ƿ����
		{
			break;//��������ֱ���������ɻ���
		}
		food1.createpos(p.w, p.h);
		for (int i = 0; i < slen; i++)
		{
			if (bodypot[i].x == food1.x && bodypot[i].y == food1.y)
			{
				fc += 1;
			}
		}
		if (fc == 0)//��ȡ������Ϸ�
		{
			havefood = 1;//���ܴ���
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
	system("cls");//������Ļ
	color(7);
	bodypot.clear();//�������
	moveset();
}