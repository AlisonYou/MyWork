#include"supermarket.h"


/*
文件名：     function.cpp
作者：       游李滨
日期：       2021年6月18日
功能描述：   登录界面；商品界面；排行榜界面...
修改说明：   仅供学习参考
版本声明：   小超市商品管理v1.0，版权所有，禁止转载。
*/


void create_frame()
{   
	int i;
	IMAGE img;

	initgraph(1200, 550);//800 x 600
	setbkmode(TRANSPARENT);//设置背景和文字模式透明
	settextstyle(0, 0, "黑体");
	settextcolor(RED);
	setlinecolor(RED);
	loadimage(&img, "..\\Resource\\商品背景.jpg", 1200, 500, true);//用相对路径应该放在Debug里，..\\表示上一级
	putimage(0,0, 1200, 500, &img, 0, 0);//背景图
	rectangle(0, 0, 1200, 500);//矩形框架
	fillrectangle(0, 500, 1200, 550);//下方功能区矩形框架

	//竖杠
	line(140, 10, 140, 500);//功能
	line(240, 10, 240, 500);//编号
	//商品名->售价
	for (i = 340; i <= 540; i+=100)
	{
		line(i, 0, i, 500);
	}
	//进量->毛利
	for (i = 705; i < 1200; i += 165)
	{
		line(i, 0, i, 500);
	}
	//横杠
	line(10, 70,1200, 70);
	for (i = 110; i < 500; i += 40)
	{
		line(140, i, 1200, i);
	}
	//变量
	outtextxy(60, 30, "功能");
	outtextxy(20, 100, "1.添加商品");
	line(10, 140, 140, 140);
	outtextxy(20, 160, "2.删除商品");
	line(10, 200, 140, 200);
	outtextxy(20, 220, "3.查找商品");
	line(10, 260, 140, 260);
	outtextxy(20, 280, "4.修改商品");
	line(10, 320, 140, 320);
	outtextxy(20,340,"盈利排行榜");
	line(10, 380, 140, 380);
	outtextxy(20, 515, "导入txt文件");
	line(140, 500, 140, 550);
	outtextxy(170,515,"初始顺序");
	line(280, 500, 280, 550);
	outtextxy(310,515,"售价顺序");
	line(415,500,415,550);
	outtextxy(445, 515, "毛利顺序");
	line(550, 500, 550, 550);
	outtextxy(582, 515, "上一页");
	line(670, 500, 670, 550);
	outtextxy(702, 515, "下一页");
	line(790,500,790,550);
	
	outtextxy(180, 30, "编号");
	outtextxy(260, 30, "商品名");
	outtextxy(370, 30, "进价");
	outtextxy(470, 30, "售价");
	outtextxy(600, 30, "进量");
	outtextxy(765, 30, "销量");
	outtextxy(930, 30, "剩余量");
	outtextxy(1095, 30, "毛利");
	

	//Sleep(50000);
	//closegraph();
}

int welcome_frame()
{
		TCHAR s[] = _T("欢迎使用超市商品管理系统");
		IMAGE img;

		initgraph(800, 600);	// 创建绘图窗口，分辨率 800 x 600
		setbkmode(TRANSPARENT);//设置当前设备图案填充和文字输出时的背景模式,TRANSPARENT——透明

		settextcolor(RED);
		settextstyle(0, 10, "黑体");
		setlinecolor(RGB(255,128,0));
		rectangle(0, 0, 800, 600);//非填充矩形

		loadimage(&img, "..\\Resource\\背景.jpg",800,600,true);//用相对路径应该放在Debug里，..\\表示上一级
		putimage(0, 0,800,600, &img,0,0);
		rectangle(250, 200, 600, 300);
		outtextxy(300, 250, s);

		fillrectangle(300, 350, 500, 370);//填充矩形
		outtextxy(250, 350, "账号：");
        outtextxy(510, 350, "注册账号");
		
		fillrectangle(300, 380, 500, 400);
		outtextxy(250, 380, "密码：");
		outtextxy(510,380,"忘记密码");
		outtextxy(510, 550, "作者：2020级软工204班游李滨");
		outtextxy(510, 570, "时间: 2021年4月25日");
		

		if (getID() == 1)//登录 成功
		{	
			/*enterCmd();*/
			return 1;
		}
		closegraph();
		return 0;
		

}

void setcmd1(int n)//n为结点个数，即商品个数
{
	CMD *p = head2;
	int i;//行

	for (i = 80; i <= 80 + 40 * (n - 1); i += 40)
	{

		outtextxy(160, i, p->number);
		outtextxy(250, i, p->name);
		outtextxy(360, i, float_to_char(p->pch_price));
		outtextxy(460, i, float_to_char(p->price));
		if (strcmp(p->type, "KG") == 0)
		{
			outtextxy(580, i, float_to_char(p->get_num));
			outtextxy(745, i, float_to_char(p->put_num));
			outtextxy(910, i, float_to_char(p->odd_num));
		}
		else
		{
			outtextxy(580, i, int_to_char((int)p->get_num));
			outtextxy(745, i, int_to_char((int)p->put_num));
			outtextxy(910, i, int_to_char((int)p->odd_num));
		}
		
		outtextxy(1085, i, float_to_char(p->gs_profit));

	    //单位
		outtextxy(420, i, "元");
		outtextxy(520, i, "元");
		outtextxy(1175, i, "元");
		outtextxy(678,i,p->type);
		outtextxy(845,i, p->type);
		outtextxy(1010,i, p->type);
		if (p->next == NULL)
		{
			break;
		}
		p = p->next;
	}

}

void setcmd2(int page,int n)
{   
	int i;
	CMD *p = head2;

	for (i = 1; i <= (page - 1) * 11; i++)
	{
		p=p->next;
	}
	if ((int)(n / 11 + 1) > page)
	{
		for (i = 80; i <= 80 + 40 * 10; i += 40)
		{

			outtextxy(180, i, p->number);
			outtextxy(250, i, p->name);
			outtextxy(340, i, float_to_char(p->pch_price));
			outtextxy(420, i, float_to_char(p->price));
			outtextxy(500, i, float_to_char(p->get_num));
			outtextxy(580, i, float_to_char(p->put_num));
			outtextxy(660, i, float_to_char(p->odd_num));
			outtextxy(740, i, float_to_char(p->gs_profit));

			//单位
			outtextxy(420, i, "元");
			outtextxy(520, i, "元");
			outtextxy(1175, i, "元");
			outtextxy(678, i, p->type);
			outtextxy(845, i, p->type);
			outtextxy(1010, i, p->type);
			p = p->next;
		}
	}
	if ((int)(n / 11 + 1) == page)
	{

		for (i = 80; i <= 80 + 40 * (n-11*page+10); i += 40)
		{

			outtextxy(180, i, p->number);
			outtextxy(250, i, p->name);
			outtextxy(340, i, float_to_char(p->pch_price));
			outtextxy(420, i, float_to_char(p->price));
			outtextxy(500, i, float_to_char(p->get_num));
			outtextxy(580, i, float_to_char(p->put_num));
			outtextxy(660, i, float_to_char(p->odd_num));
			outtextxy(740, i, float_to_char(p->gs_profit));
			//单位
			outtextxy(420, i, "元");
			outtextxy(520, i, "元");
			outtextxy(1175, i, "元");
			outtextxy(678, i, p->type);
			outtextxy(845, i, p->type);
			outtextxy(1010, i, p->type);
			p = p->next;
		}

	}

}


#define M 500
#define N 700
void picture_list()
{  
	
	int i;
	int k=1;
	int m = 150;
	int n = 50;
	IMAGE img;
	CMD   *p = head2;

	initgraph(M, N);
	loadimage(&img, "..\\Resource\\排行榜2.png", M, N, true);//用相对路径应该放在Debug里，..\\表示上一级
	putimage(0, 0, M, N, &img, 0, 0);

	setbkmode(TRANSPARENT);//透明背景

	//标题
	settextstyle(60, 28, "华文行楷", 0,0, 0, false, false, false);
	settextcolor(RGB(128, 73, 241));
	outtextxy(120, 30, "排行榜");
	//内容
	settextstyle(23, 13, "楷书",0,0,400,false,false,false);
	outtextxy(60,115,"排名");
	outtextxy(145, 115, "商品名");
	outtextxy(305, 115, "毛利总额");

	//商品框
	for (i = m; i <= n * 8 + m; i += n)
	{
		solidrectangle(50, i, 450, i + n - 10);
	}


	//商品显示
	settextstyle(20, 15, "楷书");
	settextcolor(BLACK);
	for (i = 160; i <= 560; i += 50)
	{  
		if(p==NULL)
		{ 
			break;
		}
		outtextxy(80, i, int_to_char(k));//序号
		outtextxy(150, i, p->name);//商品名
		outtextxy(300, i, float_to_char((p->gs_profit * p->put_num)));//毛利
		outtextxy(420,i,"元");
		if (p->next == NULL)
		{
			break;
		}
		k++;
		p = p->next;
	}


	//返回功能键
	settextcolor(WHITE);
	settextstyle(35, 25, "楷体");
	setfillcolor(RGB(128, 73, 241));
	solidrectangle(150, 610, 350, 660);
	outtextxy(200, 615, "返回");

}

//登录、主界面间——缓冲界面
int  enterCmd()
{
	int i;
	int j;
	int a;
	initgraph(400, 100);
	BeginBatchDraw();
	setbkcolor(WHITE);
	setlinecolor(BLACK);
	rectangle(50, 20, 350, 80);
	cleardevice();
	settextcolor(BLACK);
	//setbkmode(TRANSPARENT);
	setfillcolor(GREEN);
	srand((unsigned)time(NULL));
	a = rand() % 200 + 50;
	settextstyle(0, 0, "华文琥珀");
	outtextxy(50, 10, "正在读入中，请耐心等候...");
	for (i = 50, j = 0; i <= 350; i++)
	{
		if (i == a)
		{
			Sleep(2000);
		}
		solidrectangle(50, 40, i, 60);
		/*outtextxy(352,40, "%");*/

		outtextxy(360, 40, int_to_char(j));
		if ((i - 50) % 3 == 0)
		{
			j++;
		}
		FlushBatchDraw();
		Sleep(6);
		/*	if (i == 350)
			{
				i = 50;
				j = 0;
				cleardevice();

			}*/
	}
	EndBatchDraw();
	MessageBox(GetHWnd(), "读入完成!", "成功！", MB_OK | MB_ICONASTERISK);


	return 0;
}

