/*
����
���ڣ���һ���������У����������������Ƿ���ԡ�
����
��һ������һ����N��0<N<=100��,��ʾ��N��������ݡ������N����������������ݣ�ÿ���������ݶ���һ���ַ���S(S�ĳ���С��10000����S���ǿմ���������������������5�顣���ݱ�֤S��ֻ����"[", "]", "(", ")" �����ַ�
���
ÿ���������ݵ����ռһ�У�������ַ�������������������Եģ������Yes,�������������No
��������
3
[(])
(])
([[]()])
�������
No
No
Yes
*/
//����if��䣬ʹ�ñ�����������SList��ɶ�̬��������������ʶ�����������Ʊ�����
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
