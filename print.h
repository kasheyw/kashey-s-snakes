#pragma once
#include "unit.h"
class print :
	public unit
{
	public:
	int h;
	int w;
	void setwindow(int w,int h);//���ô��ڴ�С
	void prin();//������Ϸ����
	void color(int c);
	print(int w0=121,int h0=40);
	void hiden();
};