/*
һ������
ʱ�����ƣ�3000 ms  |  �ڴ����ƣ�65535 KB
�Ѷȣ�3
����
�����кܶ೤���Σ�ÿһ�������ζ���һ����ţ������ſ����ظ�����֪����������εĿ�ͳ�����š�������������������Ҫ����һ�·�ʽ����Ĭ����������Ǵ�С���󣩣�

1.���ձ�Ŵ�С��������

2.���ڱ����ȵĳ����Σ����ճ����εĳ�����

3.�����źͳ�����ͬ�����ճ����εĿ�����

4.�����š���������ͬ����ֻ����һ����������������,ɾ������ĳ����Σ�����ź�����ָ����ʽ��ʾ���еĳ����Σ�
����
��һ����һ������ 0<n<10000,��ʾ��������n��������ݣ�
ÿһ���һ����һ������ 0<m<1000����ʾ��m�������Σ�
��������m�У�ÿһ���������� ����һ������ʾ�����εı�ţ�

�ڶ����͵�������ֵ��ı�ʾ������ֵС�ı�ʾ�����
˵������һ�������Σ�����Լ���������Ŷ�С��10000����
���
˳�����ÿ�����ݵ����з��������ĳ����ε� ��� �� ��
��������
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
�������
1 1 1
1 2 1
1 2 2
2 1 1
2 2 1
����������ת�����������������ų������������֣��������ִ�С��������Ҳ���Բ�����������һ�����ͽ�������Ҳ���Խ���
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