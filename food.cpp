#include "food.h"
void food::srandtime()
{
	srand((int)time(0));
}
void food::createpos(int w,int h) {
		x = 4 + rand() % (w - 7);
		y = 4 + rand() % (h - 5);
};
//��prin����ͼ�δ��ں󷵻�����Ĵ���ֵ����ֵ����ʳ�����ɵķ�Χ��
//��food�����Ž�snake�����ʳ��֮�󴴽��µ�ʳ�