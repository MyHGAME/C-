/*
������
��ˮװ�ã�һ��
ʱ�����ƣ�3000 ms  |  �ڴ����ƣ�65535 KB
�Ѷȣ�3
����
����һ���ƺ����Ϊ20�ף���Ϊ2�ף�Ҫ�ں��������Ϸ��ð뾶ΪRi����ˮװ�ã�ÿ����ˮװ�õ�Ч������������Ϊ���ĵİ뾶Ϊʵ��Ri(0<Ri<15)��Բ��ʪ�����г������ˮװ��i��1<i<600)��������һ���ܰѲ�ƺȫ��ʪ����Ҫ�����ǣ�ѡ�����ٵ���ˮװ�ã���������ƺ��ȫ��ʪ��
����
��һ��m��ʾ��m���������
ÿһ��������ݵĵ�һ����һ��������n��n��ʾ����n����ˮװ�ã�����һ�У���n��ʵ��ri��ri��ʾ����ˮװ���ܸ��ǵ�Բ�İ뾶��
���
�������װ�õĸ���
��������
2
5
2 3.2 4 4.5 6
10
1 2 3 1 2 1.2 3 1.1 1 2
�������
2
5
*/
#include<iostream>
#include<math.h>
using namespace std;

int main()
{
	int N = 0;
	cin >> N;
	while (N > 0)
	{
		float l = 20, w = 2;
		int num = 0, x = 0;
		float ri[600];
		cin >> num;
		while (num > 0)
		{
			cin >> ri[x];
			x++;
			num--;
		}
		float area = l*w;
		int sum = 0;
		while (area > 0)
		{
			float max = ri[0];
			int t = 0;
			for (int i = 0; i < x; i++)
			{
				if (max < ri[i])
				{
					max = ri[i];
					t = i;
				}
			}
			ri[t] = 0;
			area -= 4 * sqrt(max*max - 1);
			sum++;
		}
		cout << sum << endl;
		N--;
	}
	return 0;
}