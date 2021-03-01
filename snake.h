#pragma once
#include<windows.h>
#include<mmSystem.h>//win中与多媒体有关的大多数接口
#pragma comment(lib, "winmm.lib")//导入winmm.lib库
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
        int sc;//分数
        vector<unit>bodypot;//蛇坐标数组
        print p;//界面类
        food food1;//食物类
        int input1;
        int input0;
        int input;
        int havefood;
        int sspeed0;
        int su;
        int fc;//食物是否合法标识信号


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

