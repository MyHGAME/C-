/*
街区最短路径问题
时间限制：3000 ms  |  内存限制：65535 KB
难度：4
描述
一个街区有很多住户，街区的街道只能为东西、南北两种方向。

住户只可以沿着街道行走。

各个街道之间的间隔相等。

用(x,y)来表示住户坐在的街区。

例如（4,20），表示用户在东西方向第4个街道，南北方向第20个街道。

现在要建一个邮局，使得各个住户到邮局的距离之和最少。

求现在这个邮局应该建在那个地方使得所有住户距离之和最小；

输入
第一行一个整数n<20，表示有n组测试数据，下面是n组数据;
每组第一行一个整数m<20,表示本组有m个住户，下面的m行每行有两个整数0<x,y<100，表示某个用户所在街区的坐标。
m行后是新一组的数据；
输出
每组数据输出到邮局最小的距离和，回车结束；
样例输入
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
样例输出
2
44

写法差异：我写的属于将所有覆盖的点都进行了遍历，而标准只需要最中间的x点和y点，这样就可以保证距离最短
标准：
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
sort(y, y + m);       //  x，y 都从小到大排序
for (i = 0; i<m / 2; i++)
s = s + x[m - i - 1] - x[i] + y[m - i - 1] - y[i];     //   两端相对应的住户的距离差就是两户距邮局的距离之和
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