#include "supermarket.h"

/*
�ļ�����     function.cpp
���ߣ�       �����
���ڣ�       2021��6��18��
����������   �ȶ��˺����룻ע���˺ţ���������...
�޸�˵����   ����ѧϰ�ο�
�汾������   С������Ʒ����v1.0����Ȩ���У���ֹת�ء�
*/


char ID[20];//�˺ţ���Ϊ��ʱ�˺����壬ȡֵ��Χ<= 19 ���ַ�����ID.cpp��ʹ��
char KEY[20];//���룬��Ϊ��ʱ��������,ȡֵ��Χ<= 19 ���ַ�����ID.cpp��ʹ��
char controller_key[20] = "123456";//����Ա���룬��������ʱʹ�ã�ȡֵ��Χ<= 19 ���ַ�����ID.cpp��forget_ID��ʹ��


int getID()
{   
	int hit_key_num=0,hit_id_num=0;//ͳ���˺�/�����Ƿ��Ѿ����룬����ͬʱ>0�������֤����
	int key_len;//ͳ�����볤��,������ʾ����
	char id[20]="\0";//���û������˺ţ�<=19���ַ�
	char key[20]="\0";//���û���������,<=19���ַ�
	MOUSEMSG MOUSE;//���ṹ�����


	setbkcolor(WHITE);
	settextcolor(RED);
	
	
	while (1)
	{
		MOUSE = GetMouseMsg();
		
		if (MOUSE.uMsg == WM_LBUTTONDOWN)
		{
			if (MOUSE.x >= 300 && MOUSE.x <= 500 && MOUSE.y >= 350 && MOUSE.y <= 370)
			{
				hit_id_num++;//����Ƿ�������˺ţ��������룬����0����ҳ��
				if (hit_id_num > 1)
				{
					return 0;
				}
				InputBox(id,20,"�˺�");
				
				
				outtextxy(310,350 , id);
			}
			if (MOUSE.x >= 300 && MOUSE.x <= 500 && MOUSE.y >= 380 && MOUSE.y <= 400)
			{   
				 hit_key_num++;//����Ƿ���������룬�������룬����0����ҳ��
				if (hit_key_num > 1)
				{
					return 0;
				}
				InputBox(key, 20, "����");
				
				if (( key_len = strlen(key) )!= 0)//����������볤��
				{
					for (int i = 0; i < key_len; i++)
					{
						outtextxy(310+i*10, 385, "*");
					}
				}
			}

			//ע��
			if (MOUSE.x > 510 && MOUSE.x < 650 && MOUSE.y > 350 && MOUSE.y < 370)
			{
				closegraph();
				register_ID();
				return 0;
			}

		    //����
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
				printf("����������ص�¼����...\n");
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
	char p[] = "..\\Resource\\�˺�.txt";
	if ((fp = fopen(p, "r")) == NULL)
	{
		MessageBox(GetHWnd(), "�����ļ�ʧ��:���˺��ļ�!(��Ϊ���������ļ�)", "����", MB_OK | MB_ICONEXCLAMATION);
		fp = fopen(p, "w");
		fclose(fp);
		if ((fp = fopen(p, "r")) == NULL)
		{
			MessageBox(GetHWnd(), "�����ļ�ʧ��", "����", MB_OK | MB_ICONEXCLAMATION);
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
			if (strcmp(KEY, key) == 0)//�˺�������ȷ
			{
				if (MessageBox(GetHWnd(), "��¼�ɹ���", "����ϵͳ", MB_OK | MB_ICONASTERISK) == IDOK)
				{   
					fclose(fp);
					return 1;
				}
			}
			else//�˺��������
			{
				if (MessageBox(GetHWnd(), "�������", "����", MB_OK | MB_ICONEXCLAMATION) == IDOK)
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
		MessageBox(GetHWnd(), "�޸��˺�", "����", MB_OK | MB_ICONEXCLAMATION);
	}
	fclose(fp);
	return 0;
}

int  register_ID()	
{
	char IDX[20];
	FILE *fp;
	char p[] = "..\\Resource\\�˺�.txt";


	if ((fp = fopen(p, "a+")) == NULL)
	{

		MessageBox(GetHWnd(), "�����ļ�ʧ��:���˺��ļ�!(��Ϊ���������ļ�)", "����", MB_OK | MB_ICONEXCLAMATION);
		fp = fopen(p, "w");
		fclose(fp);

		if ((fp = fopen(p, "a+")) == NULL)
		{
			MessageBox(GetHWnd(), "�����ļ�ʧ��!", "����", MB_OK | MB_ICONEXCLAMATION);
			fclose(fp);
			exit(1);
		}
	}
  p1:
	system("cls");
	SetPos(40, 5);
	printf("ID:");
	scanf("%s", ID);
	while (!feof(fp))//���ע���˺��Ƿ��ظ�
	{
		fscanf(fp,"%s",IDX);
		if (strcmp(IDX, ID) == 0)
		{   
			setcolor(4);
			SetPos(40,7);
			printf("���˺��ѱ�ע�ᣡ");
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
		printf("ע��ʧ��!");
		Sleep(2000);
		fclose(fp);

	}
	else
	{
		SetPos(40, 10);
		printf("ע��ɹ�!\n");
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
	char p[] = "..\\Resource\\�˺�.txt";

	if ((fp = fopen(p, "r")) == NULL)//���ı��ļ�
	{
		MessageBox(GetHWnd(), "���ļ�ʧ��!", "����", MB_OK | MB_ICONEXCLAMATION);
		exit(1);
	}
	system("cls");
	setcolor(7);
	SetPos(40, 3);
	printf("���������Ա����:");
	scanf("%s", str);
	
	//�����˺�
	if ( strcmp(controller_key, str)== 0)//����Ա������ȷ
	{   
		while (1)
		{   
			system("cls");
			SetPos(40, 5);
			setcolor(7);
			printf("��������Ҫ��ѯ��ID��");
			SetPos(40, 7);
			printf("ID:");
			scanf("%s", search_id);
			while (!feof(fp))
			{
				fscanf(fp, "%s %s", ID, KEY);
				if (strcmp(search_id, ID) == 0)//���ҳɹ�
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
			printf("�޸��˺�!");
			rewind(fp);
			Sleep(2000);
			
		}
	}
	else//�������
	{
			SetPos(40, 5);
			setcolor(4);
			printf("����Ա�������!");
			fclose(fp);
			return 1;
	}
	return 0;
}

