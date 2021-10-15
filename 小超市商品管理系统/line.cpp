#include "supermarket.h"

/*
�ļ�����     function.cpp
���ߣ�       �����
���ڣ�       2021��6��18��
����������   ��������head1����ȡtxt�ļ�����������head2;��ȡ����head2������...
�޸�˵����   ����ѧϰ�ο�
�汾������   С������Ʒ����v1.0����Ȩ���У���ֹת�ء�
*/


CMD *head1 = NULL;//����1�����ڴ洢��Ӻ����Ʒ��Ϣ��������ȫ�ļ�����line.cpp��creakLine����picture.cpp(setcmd1\2)��ʹ��
CMD *head2 = NULL;//����2�����ڶ�ȡ���洢������Ʒ��Ϣ,������ȫ�ļ�,��function.cpp������line.cpp��read_line���ȶദ����

//**********************************************************************************
int creatLine()
{
	CMD *p, *tail = NULL;
	int ch;
	int i = 1;
	while (1)
	{
		printf("\n%d :", i);
		//β�巨
		p = (CMD *)malloc(sizeof(CMD));
		if (p == NULL)
		{
			printf("�����ڴ�ʧ�ܣ�\n");
			exit(1);
		}
		p->next = NULL;
		if (head1 == NULL)
		{
			head1 = p;
		}
		else
		{
			tail = head1;
			while (tail->next != NULL)
			{
				tail = tail->next;
			}
			tail->next = p;
		}
		//����������

		if (scanf("%s %s %s %f %f %f %f",p->number, p->name, p->type,&p->pch_price, &p->price, &p->get_num, &p->put_num) != 7)
		{
			printf("\n\n����������ʧ�ܣ�\n\n");
		}
		p->odd_num = p->get_num - p->put_num;
		p->gs_profit = p->price - p->pch_price;
		//�����Ʒ�Ƿ�Ϸ�
		if (check_legal(p) == 0)
		{
			
			if (head1->next == NULL)
			{
				head1 = NULL;
				free(p);
				break;

			}
			else
			{
				tail->next = NULL;
				free(p);
				break;
			}
		}
		//�жϽ������
		printf("\n\n�Ƿ�������� ����1  ���� �� 0  ���� ) ��");
		scanf("%d", &ch);
		if (ch == 0)
		{  
			break;
		}
		printf("\n\n");
		i++;
	}
	return i;
}
//*************************************************************************

CMD * read_line()
{
	CMD *p,*tail;
	//β��˳��������ݽ���head2
	p = (CMD *)malloc(sizeof(CMD));
	if (p == NULL)
	{
		printf("����ʧ�ܣ�\n");
		exit(1);
	}
	p->next = NULL;
	if (head2 == NULL)
	{
			head2 = p;
	}
	else
	{
		tail = head2;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = p;
	}
	return p;

}

void freeList(CMD *head)//ɾ�����
{
	CMD *p = head;
	CMD *t;
	while (p != NULL)
	{
		t = p->next; //�ݴ���һ�����ĵ�ַ
		free(p);
		p = t;
	}
	head2 = NULL;

}


