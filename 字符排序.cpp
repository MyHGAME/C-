/*
ASCII码排序
时间限制：3000 ms  |  内存限制：65535 KB
难度：2
描述
输入三个字符（可以重复）后，按各字符的ASCII码从小到大的顺序输出这三个字符。
输入
第一行输入一个数N,表示有N组测试数据。后面的N行输入多组数据，每组输入数据都是占一行，有三个字符组成，之间无空格。
输出
对于每组输入数据，输出一行，字符中间用一个空格分开。
样例输入
2
qwe
asd
样例输出
e q w
a d s
*/
#include<iostream>

using namespace std;

int main()
{
	const int num = 3;
	int N = 0;
	cin >> N;
	while (N > 0)
	{
		char a[num];
		int i = 0;
		cin >> a;
		for (int j = 0; j < num - 1; j++)
		{
			for (int k = j; k < num; k++)
			{
				if (a[j] > a[k])
				{
					swap(a[j], a[k]);
				}
			}
		}
		while (i < num)
		{
			cout << a[i] << " ";
			i++;
		}
		cout << endl;
		N--;
	}
	return 0;
}