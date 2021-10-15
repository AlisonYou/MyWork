#include "supermarket.h"


/*
文件名：     function.cpp
作者：       游李滨
日期：       2021年6月18日
功能描述：   按毛利从大到小排序；按销售额从大到小排序；恢复原始排序
修改说明：   仅供学习参考
版本声明：   小超市商品管理v1.0，版权所有，禁止转载。
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
			p = p->next;//一直循环不出j，最后发现read_cmd函数里结点数一直是多算了一个！！！！！！！！！！！
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

//销售额顺序排序
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
				temp = *p;//交换结构体内容，但是next指向不变
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

//毛利顺序排序
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
			//根据毛利总额大小排序，改变排序方式仅改变此处即可
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