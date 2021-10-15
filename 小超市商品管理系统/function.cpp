#include "supermarket.h"


/*
文件名：     function.cpp
作者：       游李滨
日期：       2021年6月18日
功能描述：   添加、删除、查询、修改商品信息；判断商品信息合法性；改变字体颜色；排行榜...
修改说明：   仅供学习参考
版本声明：   小超市商品管理v1.0，版权所有，禁止转载。
*/


char str[10];
char  p1[] = "..\\Resource\\超市商品.txt";


void setcolor(int x)
{ 
	if (x >= 0 && x <= 15)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);
	}
	else
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		printf("\n\n(改变失败！数字应0 <= x <= 15)\n\n");

	}
	////SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 | 8 | 128 | 64);
	//printf("亮白色字体 前景加强 红色背景 背景加强\n");
	//0 = 黑色                8 = 灰色　　
	//	1 = 蓝色                9 = 淡蓝色        十六进制
	//	2 = 绿色                10 = 淡绿色       0xa
	//	3 = 湖蓝色              11 = 淡浅绿色     0xb
	//	4 = 红色                12 = 淡红色       0xc
	//	5 = 紫色                13 = 淡紫色       0xd
	//	6 = 黄色                14 = 淡黄色       0xe
	//	7 = 白色                15 = 亮白色       0xf 

}





//用于outtextxy（）函数里将float转换为字符串输出
char *float_to_char(float x)
{

	sprintf(str, "%.2f", x);
	return str;

}

char *int_to_char(int x)
{

	sprintf(str, "%d", x);
	return str;

}

//添加商品
int add_cmd(int n)
{       
	    int i;
		int pointnum;
		FILE *fp;
		CMD *p=NULL;
		

		if ((fp= fopen(p1, "a")) == NULL)
		{

			printf("\n打开文件失败！\n");
			exit(1);
		
		}
		system("cls");
		printf("\n\n请输入您想添加的商品:\n\n编号	  商品名	种类(单位)  	进价  	 售价	 进货量	   销售量\n\n");
		printf("\n");
		pointnum=creatLine();//链表形式临时存储，创建链表并输入数据域
		p = head1;
		system("cls");
		printf("\n\n\n正在写入本地数据.......\n\n\n");
		Sleep(500);
		//将指针p指向上一次最后一个输出结点
		for(i=1;i<=n;i++)
		{
			p = p->next;
		
		}
		while (p!= NULL)
		{   
			printf("\n\n正在写入...\n\n");
			if (fprintf(fp,"\n%s %s %.2f %.2f %.2f %.2f %.2f %.2f %s\n",p->number, p->name, p->pch_price,p->price, p->get_num,p->put_num, p->odd_num,p->gs_profit, p->type) <= 0)
			{
				printf("\n写入错误！\n");
			}
			p = p->next;
		}
		Sleep(1000);
		fclose(fp);
		return pointnum;

}
//建立链表读取txt文件，同时返回结点个数
int read_cmd()
{   
	int c;
	int i=0;
	FILE *fp;
	CMD *p;

	if ((fp = fopen(p1, "r")) == NULL)
	{
		MessageBox(GetHWnd(), "读入文件失败:无商品文件!(已为您创建该文件)", "错误！", MB_OK | MB_ICONEXCLAMATION);
		fp = fopen(p1, "w");
		fclose(fp);
		if ((fp = fopen(p1, "r")) == NULL)
		{
			printf("\n打开文件失败！\n");
			exit(1);
		}
	}
	//检查文件是否有内容，无内容则不建立链表读入
	if ((c = fgetc(fp)) == EOF)
	{  
		fclose(fp);
		return 0;
	}
	else
	{  
		if (head2 != NULL)//文件有内容，head2有内容
		{
			p = head2;
			while (p != NULL)//or i=1 ,while(p->next != NULL) {  p=p->next;i++;}
			{   
				i++;
				p = p->next;
				
			}
			return i;
		}
		//文件有内容，head2无内容
		else
		{
			printf("\n读入成功！正在读入中...\n");//建立链表head2，读入数据
			
			while (!feof(fp))
			{
				p = read_line();//返回一个结点地址
				fscanf(fp, "\n%s %s %f %f %f %f %f %f %s\n",p->number, p->name, &p->pch_price, &p->price, &p->get_num, &p->put_num, &p->odd_num, &p->gs_profit, p->type);
				i++;//统计结点个数
			}
		}
		
	}
	fclose(fp);
	return i;
}

//查找商品
int search_cmd(char str[])
{    
	CMD *p=head2;
	int i = 1;
	int num=1;//颜色
	system("cls");
	if (strcmp(str, "作者") == 0)
	{
			SetPos(40, 5);
			printf("作者：游李滨");
			SetPos(40, 6);
			printf("班级：软工204班");
			SetPos(40, 7);
			printf("学号：2020081142");
			SetPos(40, 8);
			printf("时间：2021年4月25日");
			SetPos(40, 11);
			printf("按任意键盘继续...");
			_getch();
			return 0;
			
	}
	printf("\n\n-----------------------------------------------------------------------------------------------------------------\n\n");
	printf("\n\n正在查找中,请稍后...\n\n\n"); 
	printf("	编号	商品名	  种类	  进价	   售价	    进货量      销售量     剩余量 	  毛利\n\n");
	while (p != NULL)
	{
		if (strstr(p->name, str) != NULL || strstr(p->number,str)!=NULL)
		{   
			setcolor(num);
			printf("\n\n%d :",i);
			printf("%8s %8s %8s %8.2f %8.2f %11.2f %10.2f %10.2f %13.2f\n\n", p->number, p->name,p->type, p->pch_price, p->price, p->get_num, p->put_num, p->odd_num, p->gs_profit);
		    i++;
			num++;
			if (num == 16)
			{
				num = 1;
			}
	
		}
		
		p = p->next;
	}
	setcolor(7);
	printf("\n\n---------------------------------------------------------------------------------------------------------------\n\n");
	printf("\n\n查找结束！\n\n");
	printf("按任意键返回...");
	_getch();
	return 0;

}

//删除商品
int delete_cmd(char str[])
{   
	int i = 0;
	CMD *p = head2,*tail=NULL;
	

	
	system("cls");
	printf("\n\n正在查找中....\n\n");
	if (head2 == NULL)
	{
		printf("\nhead2为空！\n");
		printf("\n任意键结束...\n");
		_getch();
		return 0;
		
	}
	while (p != NULL)
	{    
		
		if (strcmp(p->name, str) == 0 || strcmp(p->number,str) == 0)
		{
			if (p == head2)
			{
				head2 = p->next;
				tail = head2;
				free(p);
				p = tail;

			}
			else
			{
				tail->next = p->next;
				free(p);
				p = tail->next;
			}
			i++;
		}
		else
		{  
			tail = p;
			p = p->next;
		}
		
	}
	if (i == 0)
	{   
		setcolor(4);
		printf("\n\n输入错误！无该商品！\n\n");
		printf("按任意键继续...");
		_getch();
		return 0;
	}
	else
	{
		printf("\n\n共找到%d个结果\n\n正在删除中..\n\n", i);
	}
	write_head2();
	setcolor(9);
	printf("\n\n删除完成!\n\n");
	printf("按任意键继续...");
	_getch();
	setcolor(7);
	return 1;
}

//编辑商品
int change_cmd(char str[])
{
	CMD *p = head2,temp,t;
	int num=0;
	system("cls");
	printf("\n--------------------------------------------------------------------------------------------\n");
	while (p != NULL)
	{
		if (strcmp(p->name, str) == 0 || strcmp(p->number, str) == 0)
		{   
			printf("\n\n编号	商品名		种类		 进价	  售价	    进货量      销售量\n\n");
			setcolor(7);
			if (scanf("%s %s %s %f %f %f %f",temp.number, temp.name, temp.type, &temp.pch_price, &temp.price, &temp.get_num, &temp.put_num) != 7)
			{
				printf("\n\n输入数据域失败！\n\n");
				printf("按任意键继续...");
				_getch();
				return 0;
			}
			temp.odd_num = temp.get_num - temp.put_num;
			temp.gs_profit = temp.price - temp.pch_price;

			//判断合法性
			if (check_legal(&temp) == 0)
			{
				return 0;
			}
			//如何合法，将temp赋值给*p;
			t = *p;// t 存储 P 的 next
			*p = temp;
			p->next = t.next;
			num++;
		}
		p = p->next;
	}
	
	if (num == 0)
	{  
		system("cls");
		printf("\n--------------------------------------------------------------------------------------------\n");
		setcolor(4);
		printf("\n输入错误！无该商品！\n");
		setcolor(7);	
		printf("\n--------------------------------------------------------------------------------------------\n");
		printf("按任意键继续...");
		
		_getch();
		return 0;
	}
	printf("\n--------------------------------------------------------------------------------------------\n");
	write_head2();
	setcolor(9);
	printf("\n\n编辑完成!\n\n");
	printf("按任意键继续...");
	_getch();
	return 1;

}

void IslineNULL()
{
	if (head2 != NULL)//用于更新商品信息后清除head2并重建；
	{
		freeList(head2);
	}

}

//head2写入文本文件
void write_head2()
{
	FILE *fp;
	CMD *p = head2;
	if ((fp = fopen(p1, "w+")) == NULL)
	{
		printf("打开商品文件失败！");
		exit(1);
	}
	while (p != NULL)
	{
		if (fprintf(fp, "\n%s %s %.2f %.2f %.2f %.2f %.2f %.2f %s\n", p->number, p->name, p->pch_price, p->price, p->get_num, p->put_num, p->odd_num, p->gs_profit, p->type) <= 0)
		{
			printf("\n写入错误！\n");
			exit(1);
		}
		p = p->next;
	}
	fclose(fp);
}


int Ranking_list(int n)//排行榜
{   
	int k = 0;//k=1触发变色，k=0变回原样,用于按钮处解决闪屏
	MOUSEMSG mouse;

	gs_profit_sort(n);//排序
	picture_list();//排行榜界面
	while (1)
	{
		mouse = GetMouseMsg();
		 
			//返回键
			if (mouse.x > 150 && mouse.x < 350 && mouse.y > 610 && mouse.y < 660 )
			{ 
				setbkcolor(RED);
				clearrectangle(150, 610, 350, 660);
				outtextxy(200, 615, "返回");
				k = 1;
				if (mouse.uMsg == WM_LBUTTONDOWN )
				{
					closegraph();
					return 1;
				}

			}
			else
			{   
				if (k == 1)
				{
					setbkcolor(RGB(128, 73, 241));
					clearrectangle(150, 610, 350, 660);
					outtextxy(200, 615, "返回");
					k = 0;
				}
				else
				{
					continue;
				}
			}

	}
	return 0;
	
}




//判断输入的商品信息是否合法
int check_legal(CMD *p)
{
	char answer[4];
	CMD *p2 = head2;;
	
	//商品名以及编号是否重合
	while (p2 != NULL)
	{
		
		if (strcmp(p2->name, p->name) == 0 || strcmp(p2->number, p->number) == 0)
		{
			MessageBox(GetHWnd(), "商品名或编号输入不合法!", "错误！", MB_OK | MB_ICONEXCLAMATION);
			return 0;
		}
		p2 = p2->next;
	}
	//剩余量<0
	if (p->odd_num < 0)
	{
		MessageBox(GetHWnd(), "剩余量不合法!", "错误！", MB_OK | MB_ICONEXCLAMATION);
		return 0;
	}
	//毛利<0
	if (p->gs_profit < 0)
	{
		setcolor(4);
		printf("\n警告！该商品毛利为负！\n");
		setcolor(7);
		printf("\n是否忽略警告？（yes / no）:");
		scanf("%s",answer);
		if (strcmp(answer, "no") == 0)
		{
			return 0;
		}
		return 1;
	}
    
	

	return 1;
}