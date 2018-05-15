/*
重心：https://wenku.baidu.com/view/3223f77a77232f60ddcca170.html
面积：https://blog.csdn.net/lemongirl131/article/details/51130659
多边形重心问题
时间限制：3000 ms  |  内存限制：65535 KB
难度：5
描述
在某个多边形上，取n个点，这n个点顺序给出，按照给出顺序将相邻的点用直线连接， （第一个和最后一个连接），
所有线段不和其他线段相交，但是可以重合，可得到一个多边形或一条线段或一个多边形和一个线段的连接后的图形；
如果是一条线段,我们定义面积为0，重心坐标为（0,0）.现在求给出的点集组成的图形的面积和重心横纵坐标的和；
输入
第一行有一个整数0<n<11,表示有n组数据；
每组数据第一行有一个整数m<10000,表示有这个多边形有m个顶点；
输出
输出每个多边形的面积、重心横纵坐标的和，小数点后保留三位；
样例输入
3
3
0 1
0 2
0 3
3
1 1
0 0
0 1
4
1 1
0 0
0 0.5
0 1
样例输出
0.000 0.000
0.500 1.000
0.500 1.000
*/
#include<iostream>
#include<vector>
#include<math.h>
#include <iomanip> 
using namespace std;
struct vertex
{
	double x;
	double y;

};
int main()
{
	int N = 0;
	vector<vertex> Vertexs[11];
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int Num = 0;
		cin >> Num;
		for (int j = 0; j < Num; j++)
		{
			vertex temp;
			cin >> temp.x >> temp.y;
			Vertexs[i].push_back(temp);
		}
		double area = 0;
		vertex gravity;
		gravity.x = 0;
		gravity.y = 0;

		int size = Vertexs[i].size();
		if (size == 0)
		{
			continue;
		}
		for (int j = 0; j < size; j++)
		{
			double temp = (Vertexs[i][j].y * Vertexs[i][(j + 1) % size].x - Vertexs[i][(j + 1) % size].y * Vertexs[i][j].x) / 2.0;
			area += temp;
			gravity.x += temp*(Vertexs[i][j].x + Vertexs[i][(j + 1) % size].x) / 3.0;
			gravity.y += temp*(Vertexs[i][j].y + Vertexs[i][(j + 1) % size].y) / 3.0;

		}
		if (area == 0)
			cout << "0.000 0.000" << endl;
		else
			cout << fixed << setprecision(3) << fabs(area) << " " << (gravity.x + gravity.y) / area << endl;
	}

	return 0;
}