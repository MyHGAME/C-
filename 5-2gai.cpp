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
void GetAllNodes(vector<Node *>);
vector<Node *> Create();
void DFSTraverse(vector<Node *>);
void BFSTraverse(vector<Node *>);
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

Node *GetNodeFromEdge(vector<Node *> Nodes, Edge* edge)
{
	for (int i = 0; i < Nodes.size(); i++)
	{

		if (edge->AdjVer == Nodes[i]->Vertex)
		{
			return Nodes[i];
		}
	}

	return NULL;
}
void DFSTraverse(vector<Node *> Nodes)
{
	vector<int> selected;
	vector<Node *> TempNodes;
	Node* temp = new Node();
	Edge* TempEdge = new Edge();
	int i = -1;
	temp = Nodes[0];
	//若tempnodes的数量变为不等于0，或者select的数量不等于nodes的就继续循环
	while (true)
	{
		TempEdge = temp->FirstEdge;
		while (TempEdge != NULL)
		{
			cout << TempEdge->AdjVer << " -> ";
			//若存在重复，不保存，并且变成下一个edge，循环，若都重复则删除tempnode链表最后一个，跳出循环
			selected.push_back(TempEdge->AdjVer);//类似前序遍历

			//若tempnode的firstedge是空的，则不保存，且跳出循环
			Node *tempnode = GetNodeFromEdge(Nodes, TempEdge);
			TempNodes.push_back(tempnode);
			//用i来访问最后一个
			i++;
			TempEdge = TempNodes[i]->FirstEdge;
			//TempEdge = TempEdge->NextEdge;
		}

		if (TempNodes.size() > 0)
		{
			//temp变成链表最后一个

		}
	}
}

void BFSTraverse(vector<Node *> Nodes)
{

}
int main()
{
	vector<Node *> Nodes = Create();
	GetAllNodes(Nodes);
	system("pause");
	return 0;
}

