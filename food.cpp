#include "food.h"
void food::srandtime()
{
	srand((int)time(0));
}
void food::createpos(int w,int h) {
		x = 4 + rand() % (w - 7);
		y = 4 + rand() % (h - 5);
};
//在prin创建图形窗口后返回输入的窗口值，把值付给食物生成的范围；
//把food函数放进snake里，吃了食物之后创建新的食物；