/*
���ģ�https://wenku.baidu.com/view/3223f77a77232f60ddcca170.html
�����https://blog.csdn.net/lemongirl131/article/details/51130659
�������������
ʱ�����ƣ�3000 ms  |  �ڴ����ƣ�65535 KB
�Ѷȣ�5
����
��ĳ��������ϣ�ȡn���㣬��n����˳����������ո���˳�����ڵĵ���ֱ�����ӣ� ����һ�������һ�����ӣ���
�����߶β��������߶��ཻ�����ǿ����غϣ��ɵõ�һ������λ�һ���߶λ�һ������κ�һ���߶ε����Ӻ��ͼ�Σ�
�����һ���߶�,���Ƕ������Ϊ0����������Ϊ��0,0��.����������ĵ㼯��ɵ�ͼ�ε���������ĺ�������ĺͣ�
����
��һ����һ������0<n<11,��ʾ��n�����ݣ�
ÿ�����ݵ�һ����һ������m<10000,��ʾ������������m�����㣻
���
���ÿ������ε���������ĺ�������ĺͣ�С���������λ��
��������
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
�������
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