/*
�������·������
ʱ�����ƣ�3000 ms  |  �ڴ����ƣ�65535 KB
�Ѷȣ�4
����
һ�������кܶ�ס���������Ľֵ�ֻ��Ϊ�������ϱ����ַ���

ס��ֻ�������Žֵ����ߡ�

�����ֵ�֮��ļ����ȡ�

��(x,y)����ʾס�����ڵĽ�����

���磨4,20������ʾ�û��ڶ��������4���ֵ����ϱ������20���ֵ���

����Ҫ��һ���ʾ֣�ʹ�ø���ס�����ʾֵľ���֮�����١�

����������ʾ�Ӧ�ý����Ǹ��ط�ʹ������ס������֮����С��

����
��һ��һ������n<20����ʾ��n��������ݣ�������n������;
ÿ���һ��һ������m<20,��ʾ������m��ס���������m��ÿ������������0<x,y<100����ʾĳ���û����ڽ��������ꡣ
m�к�����һ������ݣ�
���
ÿ������������ʾ���С�ľ���ͣ��س�������
��������
2
3
1 1
2 1
1 2
5
2 9
5 20
11 9
1 1
1 20
�������
2
44

д�����죺��д�����ڽ����и��ǵĵ㶼�����˱���������׼ֻ��Ҫ���м��x���y�㣬�����Ϳ��Ա�֤�������
��׼��
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int x[110], y[110];
int s;
int main()
{
int m, n, i;
cin >> n;
while (n--)
{
memset(x, 0, sizeof(x));
memset(y, 0, sizeof(y));
s = 0;
cin >> m;
for (i = 0; i<m; i++)
{
cin >> x[i] >> y[i];
}
sort(x, x + m);
sort(y, y + m);       //  x��y ����С��������
for (i = 0; i<m / 2; i++)
s = s + x[m - i - 1] - x[i] + y[m - i - 1] - y[i];     //   �������Ӧ��ס���ľ��������������ʾֵľ���֮��
cout << s << endl;
}
return 0;
}
*/

#include<iostream>
#include<math.h>
#include<vector>
#include <stdlib.h>
using namespace std;

struct point
{
	int x;
	int y;
};
int main()
{
	int N = 0;
	vector<int> dis;
	cin >> N;
	while (N > 0)
	{
		point p[110];
		int m = 0, x = 0;
		cin >> m;
		while (m > 0)
		{
			cin >> p[x].x >> p[x].y;
			x++;
			m--;
		}
		int max_x = p[0].x, max_y = p[0].y, min_x = p[0].x, min_y = p[0].y;
		int i = 0;
		while (i < x)
		{
			if (p[i].x > max_x)
			{
				max_x = p[i].x;
			}
			if (p[i].x < min_x)
			{
				min_x = p[i].x;
			}
			if (p[i].y > max_y)
			{
				max_y = p[i].y;
			}
			if (p[i].y < min_y)
			{
				min_y = p[i].y;
			}
			i++;
		}

		for (int j = min_x; j <= max_x; j++)
		{
			for (int k = min_y; k <= max_y; k++)
			{
				int a = 0;
				int dis2 = 0;
				while (a < x)
				{
					dis2 += abs(p[a].x - j) + abs(p[a].y - k);
					a++;
				}
				dis.push_back(dis2);
			}
		}
		if (dis.size() == 0)
			return 1;
		int mindis = dis.front();
		for (int j = 0; j < dis.size(); j++)
		{
			if (mindis > dis[j])
			{
				mindis = dis[j];
			}
		}
		cout << mindis << endl;
		dis.clear();
		N--;
	}
	return 0;
}