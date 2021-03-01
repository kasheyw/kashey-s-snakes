#pragma once
#include "unit.h"
class print :
	public unit
{
	public:
	int h;
	int w;
	void setwindow(int w,int h);//设置窗口大小
	void prin();//绘制游戏区域
	void color(int c);
	print(int w0=121,int h0=40);
	void hiden();
};