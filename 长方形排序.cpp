/*
一种排序
时间限制：3000 ms  |  内存限制：65535 KB
难度：3
描述
现在有很多长方形，每一个长方形都有一个编号，这个编号可以重复；还知道这个长方形的宽和长，编号、长、宽都是整数；现在要求按照一下方式排序（默认排序规则都是从小到大）；

1.按照编号从小到大排序

2.对于编号相等的长方形，按照长方形的长排序；

3.如果编号和长都相同，按照长方形的宽排序；

4.如果编号、长、宽都相同，就只保留一个长方形用于排序,删除多余的长方形；最后排好序按照指定格式显示所有的长方形；
输入
第一行有一个整数 0<n<10000,表示接下来有n组测试数据；
每一组第一行有一个整数 0<m<1000，表示有m个长方形；
接下来的m行，每一行有三个数 ，第一个数表示长方形的编号，

第二个和第三个数值大的表示长，数值小的表示宽，相等
说明这是一个正方形（数据约定长宽与编号都小于10000）；
输出
顺序输出每组数据的所有符合条件的长方形的 编号 长 宽
样例输入
1
8
1 1 1
1 1 1
1 1 2
1 2 1
1 2 2
2 1 1
2 1 2
2 2 1
样例输出
1 1 1
1 2 1
1 2 2
2 1 1
2 2 1
这个排序可以转化成数字排序，例如编号长宽这样的数字，按照数字大小进行排序，也可以插入排序，输入一个数就进行排序，也可以进行
*/
#include<iostream>
using namespace std;

struct rectangle
{
	int l;
	int w;
	int num;
};
int main()
{
	int N = 0;
	cin >> N;
	while (N > 0)
	{
		rectangle rect[1000];
		int a = 0, x = 0;
		cin >> a;
		while (x < a)
		{
			int num1 = 0;
			int num2 = 0;
			cin >> rect[x].num >> num1 >> num2;
			if (num1 > num2)
			{
				rect[x].l = num1;
				rect[x].w = num2;
			}
			else
			{
				rect[x].w = num1;
				rect[x].l = num2;
			}
			x++;
		}
		int i = 0;
		while (i < x - 1)
		{
			if (rect[i].num == 0)
				continue;
			int j = i + 1;
			while (j < x)
			{
				if (rect[j].num == 0)
					continue;
				if (rect[i].num > rect[j].num)
				{
					swap(rect[i], rect[j]);
				}
				else if (rect[i].num == rect[j].num)
				{
					if (rect[i].l > rect[j].l)
					{
						swap(rect[i], rect[j]);
					}
					else if (rect[i].l == rect[j].l)
					{
						if (rect[i].w > rect[j].w)
						{
							swap(rect[i], rect[j]);
						}
						else if (rect[i].w == rect[j].w)
						{
							rect[i].num = 0;
						}
					}
				}
				j++;
			}
			i++;
		}
		int q = 0;
		while (q < x)
		{
			if (rect[q].num != 0)
			{
				cout << rect[q].num << " " << rect[q].l << " " << rect[q].w << endl;
			}
			q++;
		}

		N--;
	}
	return 0;
}