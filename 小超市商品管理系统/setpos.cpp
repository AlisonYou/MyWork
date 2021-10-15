#include"supermarket.h"


/*
文件名：     function.cpp
作者：       游李滨
日期：       2021年6月18日
功能描述：   修改光标坐标
修改说明：   仅供学习参考
版本声明：   小超市商品管理v1.0，版权所有，禁止转载。
*/


void SetPos(int x, int y)//设置光标位置(就是输出显示的开始位置)
{
	/*  COORD是Windows API中定义的一种结构体
	 *	typedef struct _COORD
	 *	{
	 *		SHORT X;
	 *		SHORT Y;
	 *	} COORD;
	 *
	 */
	COORD pos = { (SHORT)x,(SHORT)y };
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);//获得 标准输出的句柄
	SetConsoleCursorPosition(output, pos); //设置控制台光标位置 
}