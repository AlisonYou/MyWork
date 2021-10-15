#pragma once
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<windows.h>
#include<graphics.h>//Easy-Xͼ��
#include<time.h>


typedef struct commodit
{
	char type[9]="KG";//����
	char number[10];//���
	char name[15];//��Ʒ��
	float  pch_price;//����
	float  price;//�ۼ�
	float  get_num;//������(kg)
	float  put_num;//������(kg)
	float  odd_num;//ʣ����
	float gs_profit;//ë��
	struct commodit *next;

}CMD;

extern CMD *head1; //���
extern CMD *head2;//����
extern char str[10];//float->char[]����
extern char p1[];//txt�ļ���ַ



//���ù��λ��
extern void SetPos(int x, int y);


//picture      ͼ��
void create_frame();//��Ʒչʾ���
int welcome_frame();//���������
void setcmd1(int n);//n<=11,�����
void setcmd2(int page,int n);//n>=11
void picture_list();

//GetID      ��֤�˺�
int getID();//����ID��KEY
int cmpID(char *id, char *key);//�Ա��˺���Ϣ
int register_ID();//ע���˺�
int forget_ID();//��������


//line   ����ר��
int creatLine();//����head1����ֵ
CMD* read_line();//������������head2
void freeList(CMD *head);


//function     ����ר��
char *float_to_char(float x);
char *int_to_char(int x);
int change_cmd(char str[]);//�༭
int add_cmd(int n);//�����Ʒ
int read_cmd();//��txt��ȡ����->head2
int search_cmd(char str[]);//������Ʒ
int delete_cmd(char str[]);//ɾ����Ʒ
void IslineNULL();
void write_head2();//��head2д���ļ�
int Ranking_list(int n);//���а�
int  enterCmd();
int check_legal(CMD *p);//���head1�����������Ƿ�Ϸ�


//sort    ����ר��
int price_sort(int n);
int GP_sort(int n);
int gs_profit_sort(int n);


extern void setcolor(int x);/*
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 128 | 64);
printf("����ɫ���� ǰ����ǿ ��ɫ���� ������ǿ\n");
    0= ��ɫ                8 = ��ɫ����
	1 = ��ɫ                9 = ����ɫ        ʮ������
	2 = ��ɫ                10 = ����ɫ       0xa
	3 = ����ɫ              11 = ��ǳ��ɫ     0xb
	4 = ��ɫ                12 = ����ɫ       0xc
	5 = ��ɫ                13 = ����ɫ       0xd
	6 = ��ɫ                14 = ����ɫ       0xe
	7 = ��ɫ                15 = ����ɫ       0xf*/





