/*
ASCII������
ʱ�����ƣ�3000 ms  |  �ڴ����ƣ�65535 KB
�Ѷȣ�2
����
���������ַ��������ظ����󣬰����ַ���ASCII���С�����˳������������ַ���
����
��һ������һ����N,��ʾ��N��������ݡ������N������������ݣ�ÿ���������ݶ���ռһ�У��������ַ���ɣ�֮���޿ո�
���
����ÿ���������ݣ����һ�У��ַ��м���һ���ո�ֿ���
��������
2
qwe
asd
�������
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