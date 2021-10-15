#include "supermarket.h"

/*
文件名：     function.cpp
作者：       游李滨
日期：       2021年6月18日
功能描述：   创建链表head1；读取txt文件、创建链表head2;读取链表head2结点个数...
修改说明：   仅供学习参考
版本声明：   小超市商品管理v1.0，版权所有，禁止转载。
*/


CMD *head1 = NULL;//链表1，用于存储添加后的商品信息，作用域：全文件，在line.cpp（creakLine）、picture.cpp(setcmd1\2)中使用
CMD *head2 = NULL;//链表2，用于读取并存储本地商品信息,作用域：全文件,在function.cpp（）、line.cpp（read_line）等多处调用

//**********************************************************************************
int creatLine()
{
	CMD *p, *tail = NULL;
	int ch;
	int i = 1;
	while (1)
	{
		printf("\n%d :", i);
		//尾插法
		p = (CMD *)malloc(sizeof(CMD));
		if (p == NULL)
		{
			printf("申请内存失败！\n");
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
		//输入数据域

		if (scanf("%s %s %s %f %f %f %f",p->number, p->name, p->type,&p->pch_price, &p->price, &p->get_num, &p->put_num) != 7)
		{
			printf("\n\n输入数据域失败！\n\n");
		}
		p->odd_num = p->get_num - p->put_num;
		p->gs_profit = p->price - p->pch_price;
		//检查商品是否合法
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
		//判断结束与否
		printf("\n\n是否继续输入 ？（1  继续 或 0  结束 ) ：");
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
	//尾插顺序读入数据建立head2
	p = (CMD *)malloc(sizeof(CMD));
	if (p == NULL)
	{
		printf("申请失败！\n");
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

void freeList(CMD *head)//删除结点
{
	CMD *p = head;
	CMD *t;
	while (p != NULL)
	{
		t = p->next; //暂存下一个结点的地址
		free(p);
		p = t;
	}
	head2 = NULL;

}


