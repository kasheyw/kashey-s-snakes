#include "unit.h"
#include "food.h"
#include "snake.h"
#include "print.h"
#include "grule.h"
int main() {
	grule game0;
	int a; 
	int b;
	cout << "请输入窗口大小：" << endl;

	cin >> a >> b;
	if (a < 24)
	{
		a = 25;
	}
	if (b < 10)
	{
		b = 11;
	}
	game0.game(a,b);

}
 