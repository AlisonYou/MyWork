#include"supermarket.h"


/*
�ļ�����     function.cpp
���ߣ�       �����
���ڣ�       2021��6��18��
����������   �޸Ĺ������
�޸�˵����   ����ѧϰ�ο�
�汾������   С������Ʒ����v1.0����Ȩ���У���ֹת�ء�
*/


void SetPos(int x, int y)//���ù��λ��(���������ʾ�Ŀ�ʼλ��)
{
	/*  COORD��Windows API�ж����һ�ֽṹ��
	 *	typedef struct _COORD
	 *	{
	 *		SHORT X;
	 *		SHORT Y;
	 *	} COORD;
	 *
	 */
	COORD pos = { (SHORT)x,(SHORT)y };
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);//��� ��׼����ľ��
	SetConsoleCursorPosition(output, pos); //���ÿ���̨���λ�� 
}