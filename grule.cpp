#include "grule.h"
void grule::game(int w,int h)
{
	snake s0;
	s0.p.w = w;
	s0.p.h = h;
	s0.move();
}





//蛇不能撞墙；
//蛇不能撞自己
//吃食物加分并生成新的食物；食物不能出现在蛇身上
//游戏结束显示分数，判断是否重开和退出；