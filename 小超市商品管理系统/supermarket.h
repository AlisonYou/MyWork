#pragma once
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<windows.h>
#include<graphics.h>//Easy-X图形
#include<time.h>


typedef struct commodit
{
	char type[9]="KG";//种类
	char number[10];//编号
	char name[15];//商品名
	float  pch_price;//进价
	float  price;//售价
	float  get_num;//进货量(kg)
	float  put_num;//销售量(kg)
	float  odd_num;//剩余量
	float gs_profit;//毛利
	struct commodit *next;

}CMD;

extern CMD *head1; //输出
extern CMD *head2;//输入
extern char str[10];//float->char[]载体
extern char p1[];//txt文件地址



//设置光标位置
extern void SetPos(int x, int y);


//picture      图形
void create_frame();//商品展示框架
int welcome_frame();//进入界面框架
void setcmd1(int n);//n<=11,结点数
void setcmd2(int page,int n);//n>=11
void picture_list();

//GetID      验证账号
int getID();//读入ID，KEY
int cmpID(char *id, char *key);//对比账号信息
int register_ID();//注册账号
int forget_ID();//忘记密码


//line   链表专区
int creatLine();//建立head1链表赋值
CMD* read_line();//建立读入链表head2
void freeList(CMD *head);


//function     功能专区
char *float_to_char(float x);
char *int_to_char(int x);
int change_cmd(char str[]);//编辑
int add_cmd(int n);//添加商品
int read_cmd();//从txt读取内容->head2
int search_cmd(char str[]);//查找商品
int delete_cmd(char str[]);//删除商品
void IslineNULL();
void write_head2();//将head2写入文件
int Ranking_list(int n);//排行榜
int  enterCmd();
int check_legal(CMD *p);//检查head1数据域输入是否合法


//sort    排序专区
int price_sort(int n);
int GP_sort(int n);
int gs_profit_sort(int n);


extern void setcolor(int x);/*
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 128 | 64);
printf("亮白色字体 前景加强 红色背景 背景加强\n");
    0= 黑色                8 = 灰色　　
	1 = 蓝色                9 = 淡蓝色        十六进制
	2 = 绿色                10 = 淡绿色       0xa
	3 = 湖蓝色              11 = 淡浅绿色     0xb
	4 = 红色                12 = 淡红色       0xc
	5 = 紫色                13 = 淡紫色       0xd
	6 = 黄色                14 = 淡黄色       0xe
	7 = 白色                15 = 亮白色       0xf*/





