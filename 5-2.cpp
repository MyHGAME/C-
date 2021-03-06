#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct Edge
{
	int AdjVer;
	int Weight;
	Edge *NextEdge;
};

struct Node
{
	int Vertex;
	Edge *FirstEdge;
};
void GetAllNodes(vector<Node *> nodes);
vector<Node *> Create();
vector<Node *> Create()
{
	int vertex = 0;
	vector<Node *> Nodes;
	cout << "请输入第一个点的编号：" << endl;
	cin >> vertex;
	while (vertex != -1)
	{
		Node* node = new Node();
		Edge* next = new Edge();
		node->FirstEdge = NULL;
		node->Vertex = vertex;
		int endVertex = 0;
		cout << "请输入邻接点的编号：" << endl;
		cin >> endVertex;
		while (endVertex != -1)
		{
			int weight = 0;
			cout << "请输入这条线的权值：" << endl;
			cin >> weight;
			Edge *edge = new Edge();
			edge->AdjVer = endVertex;
			edge->Weight = weight;
			edge->NextEdge = NULL;
			if (node->FirstEdge == NULL)
			{
				node->FirstEdge = edge;
				next = node->FirstEdge;
			}
			else
			{
				next->NextEdge = new Edge();
				next->NextEdge = edge;
				next = next->NextEdge;
			}
			cout << "请输入下一个邻接点的编号：（-1结束）" << endl;
			cin >> endVertex;
		}
		Nodes.push_back(node);
		cout << "请输入下一个点的编号：（-1结束）" << endl;
		cin >> vertex;
	}
	return Nodes;
}

void GetAllNodes(vector<Node *> nodes)
{
	map<int, int> DegreeNode;
	map<int, int>::iterator iter;
	for (int i = 0; i < nodes.size(); i++)
	{
		cout << "起点编号：" << nodes[i]->Vertex << " ";
		Edge *next = nodes[i]->FirstEdge;
		int Degree = 0;
		while (next != NULL)
		{
			Degree++;
			cout << "领接点编号：" << next->AdjVer << " 权值：" << next->Weight << " ";
			next = next->NextEdge;
		}
		cout << endl << "点 " << nodes[i]->Vertex << " 的出度：" << Degree << endl;
		DegreeNode.insert(make_pair(nodes[i]->Vertex, Degree));
	}
	int max_degree = 0, max_node = 0;
	for (iter = DegreeNode.begin(); iter != DegreeNode.end(); iter++)
	{
		if (iter->second > max_degree)
		{
			max_node = iter->first;
			max_degree = iter->second;
		}
		if (iter->second == 0)
		{
			cout << "点 " << iter->first << " 的度为 0" << endl;
		}
	}
	cout << "点 " << max_node << " 出度最大 为" << max_degree << endl;
}


int main()
{
	vector<Node *> Nodes = Create();
	GetAllNodes(Nodes);
	system("pause");
	return 0;
}

