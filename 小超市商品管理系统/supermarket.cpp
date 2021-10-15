#include"supermarket.h"


/*
文件名：     function.cpp
作者：       游李滨
日期：       2021年6月18日
功能描述：   main函数
修改说明：   仅供学习参考
版本声明：   小超市商品管理v1.0，版权所有，禁止转载。
*/



int main()
{   

	int i;//结点数
    int page = 1;
	int last_head1_num=0;//记录上一次head1结点个数（添加之前）
	char str[15];

	MOUSEMSG mouse;

	/*登录界面*/
	while (1)
	{
		if (welcome_frame() == 1)
		{
			break;
		}

	}
	//商品界面
	while (1)
	{
		IslineNULL();
	    flag1:
		create_frame();//画框架
			if ((i = read_cmd()) != 0)//判断文件是否有内容，若无返回0;有则建立head2,返回结点个数
			{  
			 
				if ( i <= 11)//
				{

					setcmd1(i);//输出商品内容（picture.cpp）
				}
				if (i > 11)
				{
					setcmd2(page, i);
				}
			}
		flag2:
			if (MouseHit() == true)//清除鼠标缓存
			{
				FlushMouseMsgBuffer();
			}


			while (1)
			{
					mouse = GetMouseMsg();
					//添加商品
					if (mouse.x > 0 && mouse.x < 140 && mouse.y > 70 && mouse.y < 140)//添加商品
					{
						
						//鼠标点击 == 左键
						if (mouse.uMsg == WM_LBUTTONDOWN)
						{
							closegraph();
							last_head1_num += add_cmd(last_head1_num);//添加函数，last_head1_num记录添加商品数
							break;
						}
					}

					//删除文件
					if (mouse.x >  0 && mouse.x <  140 && mouse.y > 140 && mouse.y < 200)
					{
						if (mouse.uMsg == WM_LBUTTONDOWN)
						{
							if (InputBox(str, 15, "请输入想要删除的商品名或编号", NULL, NULL, 0, 0, false) == false)
							{
								goto flag2;
							}
							closegraph();
							delete_cmd(str);
							goto flag1;
						}
					}
				

					//查找商品
					if (mouse.x > 0 && mouse.x < 140 && mouse.y > 200 && mouse.y < 260)
					{    
				
						if (mouse.uMsg == WM_LBUTTONDOWN)
						{
							if (InputBox(str, 15, "请输入想要查找的商品名", NULL, NULL, 0, 0, false) == false)
							{
								goto flag2;
							}
							closegraph();
							search_cmd(str);
							goto flag1;
						}
					}
			

					//修改商品信息
					if (mouse.x >  0 && mouse.x < 140 && mouse.y > 260 && mouse.y < 320)
					{
						
						if (mouse.uMsg == WM_LBUTTONDOWN)
						{
							if (InputBox(str, 15, "请输入想要编辑的商品名或编号", NULL, NULL, 0, 0, false) == false)
							{
								goto flag2;
							}
							closegraph();
							change_cmd(str);
							goto flag1;
						}

					}
		
				    //排行榜
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
					//导入txt文件
					if (mouse.x > 0 && mouse.x <  140 && mouse.y > 500 && mouse.y < 550)
					{
						if (mouse.uMsg == WM_LBUTTONDOWN)
						{
							if (InputBox(p1, 60, "请输入想要导入txt文件地址", "导入txt文件", NULL, 0, 0, false) == false)
							{
								goto flag2;
							}
							break;
						}
						
					}
					//初始顺序
					if (mouse.x > 140 && mouse.x < 280 && mouse.y > 500 && mouse.y < 550)
					{
						if (mouse.uMsg == WM_LBUTTONDOWN)
						{
							closegraph();
							break;
						}

					}
					//售价顺序
					if (mouse.x > 280 && mouse.x < 415 && mouse.y > 500 && mouse.y < 550)
					{
						if (mouse.uMsg == WM_LBUTTONDOWN)
						{
						
						closegraph();
						price_sort(i);
						goto flag1;
						}
					}
					//毛利顺序
					if (mouse.x > 415 && mouse.x < 550 && mouse.y > 500 && mouse.y < 550)
					{
						if (mouse.uMsg == WM_LBUTTONDOWN)
						{
							closegraph();
							GP_sort(i);
							goto flag1;
						}
					}

					/*上一页*/
					if (mouse.x > 550 && mouse.x <  670 && mouse.y >500 && mouse.y < 550)//下一页
					{
						if (mouse.uMsg == WM_LBUTTONDOWN)
						{
							if (i <= 11)//限制page--不至于＜=0
							{

								MessageBox(GetHWnd(), "无上一页", "错误！", MB_OK | MB_ICONEXCLAMATION);
								goto flag2;
							}
							else
							{

								page--;
								if (page == 0)
								{
									page = 1;
									MessageBox(GetHWnd(), "无上一页", "错误！", MB_OK | MB_ICONEXCLAMATION);
								}
								closegraph();
								goto flag1;
							}
						}
					}

					//下一页
					if (mouse.x > 670 && mouse.x < 790 && mouse.y > 500 && mouse.y < 550)//下一页
					{
						if (mouse.uMsg == WM_LBUTTONDOWN)
						{

							if (i <= 11 || (int)(i / 11) + 1 == page)
							{
								MessageBox(GetHWnd(), "无下一页", "错误！", MB_OK | MB_ICONEXCLAMATION);
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