#include "supermarket.h"


/*
�ļ�����     function.cpp
���ߣ�       �����
���ڣ�       2021��6��18��
����������   ��ë���Ӵ�С���򣻰����۶�Ӵ�С���򣻻ָ�ԭʼ����
�޸�˵����   ����ѧϰ�ο�
�汾������   С������Ʒ����v1.0����Ȩ���У���ֹת�ء�
*/


int price_sort(int n)
{   

	int i, j;
	CMD temp;
	CMD *line;
	CMD *p = head2;

	for (i = 0; i < n - 1; i++)
	{
		
		p = head2;
		
		for (j = 0; j <n - 1 - i; j++)
		{
			
			if (p->price < p->next->price)
			{
				temp = *p;
				*p = *(p->next);
				p->next = temp.next;
				line = p->next->next;
				*(p->next) = temp;
				p->next->next = line;
			}
			p = p->next;//һֱѭ������j�������read_cmd����������һֱ�Ƕ�����һ������������������������
		}
	}
	/*p = head2;
	printf("\n%d\n",n);
	while (p != NULL)
	{
		printf("\n%f\n",p->price);
		p = p->next;
	}
	Sleep(10000);*/
	return 0;

}

//���۶�˳������
int GP_sort(int n)
{
	int i, j;
	CMD temp;
	CMD *line;
	CMD *p = head2;


	for (i = 0; i < n - 1; i++)
	{
		p = head2;
		for (j = 0; j < n - 1 - i; j++)
		{
			
			if (p->gs_profit < p->next->gs_profit)
			{
				temp = *p;//�����ṹ�����ݣ�����nextָ�򲻱�
				*p = *(p->next);
				p->next = temp.next;
				line = p->next->next;
				*(p->next) = temp;
				p->next->next = line;
			}
			p = p->next;
		}
		
	}

	return 0;
}

//ë��˳������
int gs_profit_sort(int n)
{
	int i, j;
	CMD temp;
	CMD *line;
	CMD *p = head2;


	for (i = 0; i < n - 1; i++)
	{
		p = head2;
		for (j = 0; j < n - 1 - i; j++)
		{
			//����ë���ܶ��С���򣬸ı�����ʽ���ı�˴�����
			if ((p->gs_profit * p->put_num )<(p->next->gs_profit * p->next->put_num))
			{
				temp = *p;
				*p = *(p->next);
				p->next = temp.next;
				line = p->next->next;
				*(p->next) = temp;
				p->next->next = line;
			}
			p = p->next;
		}

	}
	return 0;
}