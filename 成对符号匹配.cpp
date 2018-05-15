/*
描述
现在，有一行括号序列，请你检查这行括号是否配对。
输入
第一行输入一个数N（0<N<=100）,表示有N组测试数据。后面的N行输入多组输入数据，每组输入数据都是一个字符串S(S的长度小于10000，且S不是空串），测试数据组数少于5组。数据保证S中只含有"[", "]", "(", ")" 四种字符
输出
每组输入数据的输出占一行，如果该字符串中所含的括号是配对的，则输出Yes,如果不配对则输出No
样例输入
3
[(])
(])
([[]()])
样例输出
No
No
Yes
*/
//减少if语句，使用表驱动法，将SList变成动态，让这个程序可以识别多个符号类似编译器
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	int N = 0;
	cin >> N;
	string SList[100];
	for (int i = 0; i < N; i++)
	{
		string S;
		cin >> S;
		SList[i] = S;
	}

	for (int i = 0; i < N; i++)
	{
		int j = 0, flag = 1;
		vector<char> list;
		while (j != SList[i].length())
		{

			if (SList[i][j] == '(' || SList[i][j] == '[')
			{
				list.push_back(SList[i][j]);
			}
			if (SList[i][j] == ')' || SList[i][j] == ']')
			{
				if (list.empty())
				{
					flag = 0;
					break;
				}

				if ((SList[i][j] == ')' && list.back() == '(') || (SList[i][j] == ']' && list.back() == '['))
				{
					list.pop_back();
				}
				else
				{
					flag = 0;
					break;
				}
			}
			j++;
		}
		if (flag == 1)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}

	system("pause");
	return 0;
}
