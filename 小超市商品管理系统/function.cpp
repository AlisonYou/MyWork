#include "supermarket.h"


/*
�ļ�����     function.cpp
���ߣ�       �����
���ڣ�       2021��6��18��
����������   ��ӡ�ɾ������ѯ���޸���Ʒ��Ϣ���ж���Ʒ��Ϣ�Ϸ��ԣ��ı�������ɫ�����а�...
�޸�˵����   ����ѧϰ�ο�
�汾������   С������Ʒ����v1.0����Ȩ���У���ֹת�ء�
*/


char str[10];
char  p1[] = "..\\Resource\\������Ʒ.txt";


void setcolor(int x)
{ 
	if (x >= 0 && x <= 15)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);
	}
	else
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		printf("\n\n(�ı�ʧ�ܣ�����Ӧ0 <= x <= 15)\n\n");

	}
	////SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 | 8 | 128 | 64);
	//printf("����ɫ���� ǰ����ǿ ��ɫ���� ������ǿ\n");
	//0 = ��ɫ                8 = ��ɫ����
	//	1 = ��ɫ                9 = ����ɫ        ʮ������
	//	2 = ��ɫ                10 = ����ɫ       0xa
	//	3 = ����ɫ              11 = ��ǳ��ɫ     0xb
	//	4 = ��ɫ                12 = ����ɫ       0xc
	//	5 = ��ɫ                13 = ����ɫ       0xd
	//	6 = ��ɫ                14 = ����ɫ       0xe
	//	7 = ��ɫ                15 = ����ɫ       0xf 

}





//����outtextxy���������ｫfloatת��Ϊ�ַ������
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

//�����Ʒ
int add_cmd(int n)
{       
	    int i;
		int pointnum;
		FILE *fp;
		CMD *p=NULL;
		

		if ((fp= fopen(p1, "a")) == NULL)
		{

			printf("\n���ļ�ʧ�ܣ�\n");
			exit(1);
		
		}
		system("cls");
		printf("\n\n������������ӵ���Ʒ:\n\n���	  ��Ʒ��	����(��λ)  	����  	 �ۼ�	 ������	   ������\n\n");
		printf("\n");
		pointnum=creatLine();//������ʽ��ʱ�洢��������������������
		p = head1;
		system("cls");
		printf("\n\n\n����д�뱾������.......\n\n\n");
		Sleep(500);
		//��ָ��pָ����һ�����һ��������
		for(i=1;i<=n;i++)
		{
			p = p->next;
		
		}
		while (p!= NULL)
		{   
			printf("\n\n����д��...\n\n");
			if (fprintf(fp,"\n%s %s %.2f %.2f %.2f %.2f %.2f %.2f %s\n",p->number, p->name, p->pch_price,p->price, p->get_num,p->put_num, p->odd_num,p->gs_profit, p->type) <= 0)
			{
				printf("\nд�����\n");
			}
			p = p->next;
		}
		Sleep(1000);
		fclose(fp);
		return pointnum;

}
//���������ȡtxt�ļ���ͬʱ���ؽ�����
int read_cmd()
{   
	int c;
	int i=0;
	FILE *fp;
	CMD *p;

	if ((fp = fopen(p1, "r")) == NULL)
	{
		MessageBox(GetHWnd(), "�����ļ�ʧ��:����Ʒ�ļ�!(��Ϊ���������ļ�)", "����", MB_OK | MB_ICONEXCLAMATION);
		fp = fopen(p1, "w");
		fclose(fp);
		if ((fp = fopen(p1, "r")) == NULL)
		{
			printf("\n���ļ�ʧ�ܣ�\n");
			exit(1);
		}
	}
	//����ļ��Ƿ������ݣ��������򲻽����������
	if ((c = fgetc(fp)) == EOF)
	{  
		fclose(fp);
		return 0;
	}
	else
	{  
		if (head2 != NULL)//�ļ������ݣ�head2������
		{
			p = head2;
			while (p != NULL)//or i=1 ,while(p->next != NULL) {  p=p->next;i++;}
			{   
				i++;
				p = p->next;
				
			}
			return i;
		}
		//�ļ������ݣ�head2������
		else
		{
			printf("\n����ɹ������ڶ�����...\n");//��������head2����������
			
			while (!feof(fp))
			{
				p = read_line();//����һ������ַ
				fscanf(fp, "\n%s %s %f %f %f %f %f %f %s\n",p->number, p->name, &p->pch_price, &p->price, &p->get_num, &p->put_num, &p->odd_num, &p->gs_profit, p->type);
				i++;//ͳ�ƽ�����
			}
		}
		
	}
	fclose(fp);
	return i;
}

//������Ʒ
int search_cmd(char str[])
{    
	CMD *p=head2;
	int i = 1;
	int num=1;//��ɫ
	system("cls");
	if (strcmp(str, "����") == 0)
	{
			SetPos(40, 5);
			printf("���ߣ������");
			SetPos(40, 6);
			printf("�༶����204��");
			SetPos(40, 7);
			printf("ѧ�ţ�2020081142");
			SetPos(40, 8);
			printf("ʱ�䣺2021��4��25��");
			SetPos(40, 11);
			printf("��������̼���...");
			_getch();
			return 0;
			
	}
	printf("\n\n-----------------------------------------------------------------------------------------------------------------\n\n");
	printf("\n\n���ڲ�����,���Ժ�...\n\n\n"); 
	printf("	���	��Ʒ��	  ����	  ����	   �ۼ�	    ������      ������     ʣ���� 	  ë��\n\n");
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
	printf("\n\n���ҽ�����\n\n");
	printf("�����������...");
	_getch();
	return 0;

}

//ɾ����Ʒ
int delete_cmd(char str[])
{   
	int i = 0;
	CMD *p = head2,*tail=NULL;
	

	
	system("cls");
	printf("\n\n���ڲ�����....\n\n");
	if (head2 == NULL)
	{
		printf("\nhead2Ϊ�գ�\n");
		printf("\n���������...\n");
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
		printf("\n\n��������޸���Ʒ��\n\n");
		printf("�����������...");
		_getch();
		return 0;
	}
	else
	{
		printf("\n\n���ҵ�%d�����\n\n����ɾ����..\n\n", i);
	}
	write_head2();
	setcolor(9);
	printf("\n\nɾ�����!\n\n");
	printf("�����������...");
	_getch();
	setcolor(7);
	return 1;
}

//�༭��Ʒ
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
			printf("\n\n���	��Ʒ��		����		 ����	  �ۼ�	    ������      ������\n\n");
			setcolor(7);
			if (scanf("%s %s %s %f %f %f %f",temp.number, temp.name, temp.type, &temp.pch_price, &temp.price, &temp.get_num, &temp.put_num) != 7)
			{
				printf("\n\n����������ʧ�ܣ�\n\n");
				printf("�����������...");
				_getch();
				return 0;
			}
			temp.odd_num = temp.get_num - temp.put_num;
			temp.gs_profit = temp.price - temp.pch_price;

			//�жϺϷ���
			if (check_legal(&temp) == 0)
			{
				return 0;
			}
			//��κϷ�����temp��ֵ��*p;
			t = *p;// t �洢 P �� next
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
		printf("\n��������޸���Ʒ��\n");
		setcolor(7);	
		printf("\n--------------------------------------------------------------------------------------------\n");
		printf("�����������...");
		
		_getch();
		return 0;
	}
	printf("\n--------------------------------------------------------------------------------------------\n");
	write_head2();
	setcolor(9);
	printf("\n\n�༭���!\n\n");
	printf("�����������...");
	_getch();
	return 1;

}

void IslineNULL()
{
	if (head2 != NULL)//���ڸ�����Ʒ��Ϣ�����head2���ؽ���
	{
		freeList(head2);
	}

}

//head2д���ı��ļ�
void write_head2()
{
	FILE *fp;
	CMD *p = head2;
	if ((fp = fopen(p1, "w+")) == NULL)
	{
		printf("����Ʒ�ļ�ʧ�ܣ�");
		exit(1);
	}
	while (p != NULL)
	{
		if (fprintf(fp, "\n%s %s %.2f %.2f %.2f %.2f %.2f %.2f %s\n", p->number, p->name, p->pch_price, p->price, p->get_num, p->put_num, p->odd_num, p->gs_profit, p->type) <= 0)
		{
			printf("\nд�����\n");
			exit(1);
		}
		p = p->next;
	}
	fclose(fp);
}


int Ranking_list(int n)//���а�
{   
	int k = 0;//k=1������ɫ��k=0���ԭ��,���ڰ�ť���������
	MOUSEMSG mouse;

	gs_profit_sort(n);//����
	picture_list();//���а����
	while (1)
	{
		mouse = GetMouseMsg();
		 
			//���ؼ�
			if (mouse.x > 150 && mouse.x < 350 && mouse.y > 610 && mouse.y < 660 )
			{ 
				setbkcolor(RED);
				clearrectangle(150, 610, 350, 660);
				outtextxy(200, 615, "����");
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
					outtextxy(200, 615, "����");
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




//�ж��������Ʒ��Ϣ�Ƿ�Ϸ�
int check_legal(CMD *p)
{
	char answer[4];
	CMD *p2 = head2;;
	
	//��Ʒ���Լ�����Ƿ��غ�
	while (p2 != NULL)
	{
		
		if (strcmp(p2->name, p->name) == 0 || strcmp(p2->number, p->number) == 0)
		{
			MessageBox(GetHWnd(), "��Ʒ���������벻�Ϸ�!", "����", MB_OK | MB_ICONEXCLAMATION);
			return 0;
		}
		p2 = p2->next;
	}
	//ʣ����<0
	if (p->odd_num < 0)
	{
		MessageBox(GetHWnd(), "ʣ�������Ϸ�!", "����", MB_OK | MB_ICONEXCLAMATION);
		return 0;
	}
	//ë��<0
	if (p->gs_profit < 0)
	{
		setcolor(4);
		printf("\n���棡����Ʒë��Ϊ����\n");
		setcolor(7);
		printf("\n�Ƿ���Ծ��棿��yes / no��:");
		scanf("%s",answer);
		if (strcmp(answer, "no") == 0)
		{
			return 0;
		}
		return 1;
	}
    
	

	return 1;
}