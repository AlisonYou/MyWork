#include"supermarket.h"


/*
�ļ�����     function.cpp
���ߣ�       �����
���ڣ�       2021��6��18��
����������   main����
�޸�˵����   ����ѧϰ�ο�
�汾������   С������Ʒ����v1.0����Ȩ���У���ֹת�ء�
*/



int main()
{   

	int i;//�����
    int page = 1;
	int last_head1_num=0;//��¼��һ��head1�����������֮ǰ��
	char str[15];

	MOUSEMSG mouse;

	/*��¼����*/
	while (1)
	{
		if (welcome_frame() == 1)
		{
			break;
		}

	}
	//��Ʒ����
	while (1)
	{
		IslineNULL();
	    flag1:
		create_frame();//�����
			if ((i = read_cmd()) != 0)//�ж��ļ��Ƿ������ݣ����޷���0;������head2,���ؽ�����
			{  
			 
				if ( i <= 11)//
				{

					setcmd1(i);//�����Ʒ���ݣ�picture.cpp��
				}
				if (i > 11)
				{
					setcmd2(page, i);
				}
			}
		flag2:
			if (MouseHit() == true)//�����껺��
			{
				FlushMouseMsgBuffer();
			}


			while (1)
			{
					mouse = GetMouseMsg();
					//�����Ʒ
					if (mouse.x > 0 && mouse.x < 140 && mouse.y > 70 && mouse.y < 140)//�����Ʒ
					{
						
						//����� == ���
						if (mouse.uMsg == WM_LBUTTONDOWN)
						{
							closegraph();
							last_head1_num += add_cmd(last_head1_num);//��Ӻ�����last_head1_num��¼�����Ʒ��
							break;
						}
					}

					//ɾ���ļ�
					if (mouse.x >  0 && mouse.x <  140 && mouse.y > 140 && mouse.y < 200)
					{
						if (mouse.uMsg == WM_LBUTTONDOWN)
						{
							if (InputBox(str, 15, "��������Ҫɾ������Ʒ������", NULL, NULL, 0, 0, false) == false)
							{
								goto flag2;
							}
							closegraph();
							delete_cmd(str);
							goto flag1;
						}
					}
				

					//������Ʒ
					if (mouse.x > 0 && mouse.x < 140 && mouse.y > 200 && mouse.y < 260)
					{    
				
						if (mouse.uMsg == WM_LBUTTONDOWN)
						{
							if (InputBox(str, 15, "��������Ҫ���ҵ���Ʒ��", NULL, NULL, 0, 0, false) == false)
							{
								goto flag2;
							}
							closegraph();
							search_cmd(str);
							goto flag1;
						}
					}
			

					//�޸���Ʒ��Ϣ
					if (mouse.x >  0 && mouse.x < 140 && mouse.y > 260 && mouse.y < 320)
					{
						
						if (mouse.uMsg == WM_LBUTTONDOWN)
						{
							if (InputBox(str, 15, "��������Ҫ�༭����Ʒ������", NULL, NULL, 0, 0, false) == false)
							{
								goto flag2;
							}
							closegraph();
							change_cmd(str);
							goto flag1;
						}

					}
		
				    //���а�
					if (mouse.x > 0 && mouse.x < 140 && mouse.y > 320 && mouse.y < 380)
					{
						if (mouse.uMsg == WM_LBUTTONDOWN)
						{
							closegraph();
							if (Ranking_list(i) == 1)
							{
								break;
							}
							else
							{
								exit(1);
							}
						}

					}
					//����txt�ļ�
					if (mouse.x > 0 && mouse.x <  140 && mouse.y > 500 && mouse.y < 550)
					{
						if (mouse.uMsg == WM_LBUTTONDOWN)
						{
							if (InputBox(p1, 60, "��������Ҫ����txt�ļ���ַ", "����txt�ļ�", NULL, 0, 0, false) == false)
							{
								goto flag2;
							}
							break;
						}
						
					}
					//��ʼ˳��
					if (mouse.x > 140 && mouse.x < 280 && mouse.y > 500 && mouse.y < 550)
					{
						if (mouse.uMsg == WM_LBUTTONDOWN)
						{
							closegraph();
							break;
						}

					}
					//�ۼ�˳��
					if (mouse.x > 280 && mouse.x < 415 && mouse.y > 500 && mouse.y < 550)
					{
						if (mouse.uMsg == WM_LBUTTONDOWN)
						{
						
						closegraph();
						price_sort(i);
						goto flag1;
						}
					}
					//ë��˳��
					if (mouse.x > 415 && mouse.x < 550 && mouse.y > 500 && mouse.y < 550)
					{
						if (mouse.uMsg == WM_LBUTTONDOWN)
						{
							closegraph();
							GP_sort(i);
							goto flag1;
						}
					}

					/*��һҳ*/
					if (mouse.x > 550 && mouse.x <  670 && mouse.y >500 && mouse.y < 550)//��һҳ
					{
						if (mouse.uMsg == WM_LBUTTONDOWN)
						{
							if (i <= 11)//����page--�����ڣ�=0
							{

								MessageBox(GetHWnd(), "����һҳ", "����", MB_OK | MB_ICONEXCLAMATION);
								goto flag2;
							}
							else
							{

								page--;
								if (page == 0)
								{
									page = 1;
									MessageBox(GetHWnd(), "����һҳ", "����", MB_OK | MB_ICONEXCLAMATION);
								}
								closegraph();
								goto flag1;
							}
						}
					}

					//��һҳ
					if (mouse.x > 670 && mouse.x < 790 && mouse.y > 500 && mouse.y < 550)//��һҳ
					{
						if (mouse.uMsg == WM_LBUTTONDOWN)
						{

							if (i <= 11 || (int)(i / 11) + 1 == page)
							{
								MessageBox(GetHWnd(), "����һҳ", "����", MB_OK | MB_ICONEXCLAMATION);
								goto flag2;
							}
							else
							{
								closegraph();
								page++;
								goto flag1;
							}
						}
					}
			}
		
	}
	return 0;
}