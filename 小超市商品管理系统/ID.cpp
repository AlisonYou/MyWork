#include "supermarket.h"

/*
文件名：     function.cpp
作者：       游李滨
日期：       2021年6月18日
功能描述：   比对账号密码；注册账号；忘记密码...
修改说明：   仅供学习参考
版本声明：   小超市商品管理v1.0，版权所有，禁止转载。
*/


char ID[20];//账号，作为临时账号载体，取值范围<= 19 个字符，在ID.cpp中使用
char KEY[20];//密码，作为临时密码载体,取值范围<= 19 个字符，在ID.cpp中使用
char controller_key[20] = "123456";//管理员密码，忘记密码时使用，取值范围<= 19 个字符，在ID.cpp（forget_ID）使用


int getID()
{   
	int hit_key_num=0,hit_id_num=0;//统计账号/密码是否已经输入，二者同时>0则进入验证环节
	int key_len;//统计密码长度,便于显示密码
	char id[20]="\0";//待用户输入账号，<=19个字符
	char key[20]="\0";//待用户输入密码,<=19个字符
	MOUSEMSG MOUSE;//鼠标结构体变量


	setbkcolor(WHITE);
	settextcolor(RED);
	
	
	while (1)
	{
		MOUSE = GetMouseMsg();
		
		if (MOUSE.uMsg == WM_LBUTTONDOWN)
		{
			if (MOUSE.x >= 300 && MOUSE.x <= 500 && MOUSE.y >= 350 && MOUSE.y <= 370)
			{
				hit_id_num++;//检查是否输入过账号，若已输入，返回0重置页面
				if (hit_id_num > 1)
				{
					return 0;
				}
				InputBox(id,20,"账号");
				
				
				outtextxy(310,350 , id);
			}
			if (MOUSE.x >= 300 && MOUSE.x <= 500 && MOUSE.y >= 380 && MOUSE.y <= 400)
			{   
				 hit_key_num++;//检查是否输入过密码，若已输入，返回0重置页面
				if (hit_key_num > 1)
				{
					return 0;
				}
				InputBox(key, 20, "密码");
				
				if (( key_len = strlen(key) )!= 0)//检查输入密码长度
				{
					for (int i = 0; i < key_len; i++)
					{
						outtextxy(310+i*10, 385, "*");
					}
				}
			}

			//注册
			if (MOUSE.x > 510 && MOUSE.x < 650 && MOUSE.y > 350 && MOUSE.y < 370)
			{
				closegraph();
				register_ID();
				return 0;
			}

		    //忘记
			if (MOUSE.x > 510 && MOUSE.x < 650  && MOUSE.y > 380 && MOUSE.y < 400)
			{
				closegraph();
				while (1)
				{
					if (forget_ID() == 1)
					{
						break;
					}
				}
				setcolor(7);
				SetPos(40, 11);
				printf("按任意键返回登录界面...\n");
				_getch();
				return 0;
			}
			
			
		}
		if (strlen(id) >0 && strlen(key) > 0)
		{
			if (cmpID(id, key) !=  0)
			{
				return 1; 
			}
			else
			{
				return 0;
			}
		}
	}

	return 0;
}

int cmpID(char *id, char *key)
{   
	int i=0;
	FILE *fp;
	char p[] = "..\\Resource\\账号.txt";
	if ((fp = fopen(p, "r")) == NULL)
	{
		MessageBox(GetHWnd(), "读入文件失败:无账号文件!(已为您创建该文件)", "错误！", MB_OK | MB_ICONEXCLAMATION);
		fp = fopen(p, "w");
		fclose(fp);
		if ((fp = fopen(p, "r")) == NULL)
		{
			MessageBox(GetHWnd(), "读入文件失败", "错误！", MB_OK | MB_ICONEXCLAMATION);
			fclose(fp);
			exit(1);
		}
		else
		{
			fclose(fp);
			return 0;
		}
	
	}
	while (!feof(fp))
	{
		fscanf(fp,"%s %s",ID,KEY);
		if (strcmp(ID, id) == 0)
		{
			if (strcmp(KEY, key) == 0)//账号密码正确
			{
				if (MessageBox(GetHWnd(), "登录成功！", "进入系统", MB_OK | MB_ICONASTERISK) == IDOK)
				{   
					fclose(fp);
					return 1;
				}
			}
			else//账号密码错误
			{
				if (MessageBox(GetHWnd(), "密码错误", "错误！", MB_OK | MB_ICONEXCLAMATION) == IDOK)
				{
					fclose(fp);
					return 0;
				}
			}
			i = 1;
		}
	
	}
	if (i == 0)
	{
		MessageBox(GetHWnd(), "无该账号", "错误！", MB_OK | MB_ICONEXCLAMATION);
	}
	fclose(fp);
	return 0;
}

int  register_ID()	
{
	char IDX[20];
	FILE *fp;
	char p[] = "..\\Resource\\账号.txt";


	if ((fp = fopen(p, "a+")) == NULL)
	{

		MessageBox(GetHWnd(), "读入文件失败:无账号文件!(已为您创建该文件)", "错误！", MB_OK | MB_ICONEXCLAMATION);
		fp = fopen(p, "w");
		fclose(fp);

		if ((fp = fopen(p, "a+")) == NULL)
		{
			MessageBox(GetHWnd(), "读入文件失败!", "错误！", MB_OK | MB_ICONEXCLAMATION);
			fclose(fp);
			exit(1);
		}
	}
  p1:
	system("cls");
	SetPos(40, 5);
	printf("ID:");
	scanf("%s", ID);
	while (!feof(fp))//检查注册账号是否重复
	{
		fscanf(fp,"%s",IDX);
		if (strcmp(IDX, ID) == 0)
		{   
			setcolor(4);
			SetPos(40,7);
			printf("该账号已被注册！");
			setcolor(7);
			Sleep(4000);
			goto p1;
			
		}
	}
	SetPos(40, 7);
	printf("KEY:");
	scanf("%s", KEY);
	if (fprintf(fp, "\n%s %s", ID, KEY) < 0)
	{
		setcolor(4);
		SetPos(40, 10);
		printf("注册失败!");
		Sleep(2000);
		fclose(fp);

	}
	else
	{
		SetPos(40, 10);
		printf("注册成功!\n");
		Sleep(2000);
		fclose(fp);
	}
	return 1;
}


int forget_ID()
{   
	
	char str[20];
	char search_id[20];
	FILE *fp;
	char p[] = "..\\Resource\\账号.txt";

	if ((fp = fopen(p, "r")) == NULL)//打开文本文件
	{
		MessageBox(GetHWnd(), "打开文件失败!", "错误！", MB_OK | MB_ICONEXCLAMATION);
		exit(1);
	}
	system("cls");
	setcolor(7);
	SetPos(40, 3);
	printf("请输入管理员密码:");
	scanf("%s", str);
	
	//查找账号
	if ( strcmp(controller_key, str)== 0)//管理员密码正确
	{   
		while (1)
		{   
			system("cls");
			SetPos(40, 5);
			setcolor(7);
			printf("请输入想要查询的ID：");
			SetPos(40, 7);
			printf("ID:");
			scanf("%s", search_id);
			while (!feof(fp))
			{
				fscanf(fp, "%s %s", ID, KEY);
				if (strcmp(search_id, ID) == 0)//查找成功
				{
					setcolor(5);
					SetPos(40, 9);
					printf("KEY:");
					puts(KEY);
					fclose(fp);
					return 1;

				}
			}
			SetPos(40, 9);
			setcolor(3);
			printf("无该账号!");
			rewind(fp);
			Sleep(2000);
			
		}
	}
	else//密码错误
	{
			SetPos(40, 5);
			setcolor(4);
			printf("管理员密码错误!");
			fclose(fp);
			return 1;
	}
	return 0;
}

