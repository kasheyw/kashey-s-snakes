#pragma once
#include<windows.h>
#include<mmSystem.h>//win�����ý���йصĴ�����ӿ�
#pragma comment(lib, "winmm.lib")//����winmm.lib��
#include <vector>
#include "food.h"
class snake :
    public food
{
public:
        int sx;
        int sy;
        int slen;
        int sspeed;
        //DIR sdir;
        int sc;//����
        vector<unit>bodypot;//����������
        print p;//������
        food food1;//ʳ����
        int input1;
        int input0;
        int input;
        int havefood;
        int sspeed0;
        int su;
        int fc;//ʳ���Ƿ�Ϸ���ʶ�ź�


        snake(int x = 5, int y = 4, int len = 2, int speed = 500,char pic = '#');//,int havefood0=0, int fc0=0,int input=77,int su0=0
        ~snake();
        void showsnake();
        void killsnake();
        void move();

        /**********************************************/
        void moveset();
        void creatfood();
        void restar();
};

