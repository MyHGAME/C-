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
	cout << "�������һ����ı�ţ�" << endl;
	cin >> vertex;
	while (vertex != -1)
	{
		Node* node = new Node();
		Edge* next = new Edge();
		node->FirstEdge = NULL;
		node->Vertex = vertex;
		int endVertex = 0;
		cout << "�������ڽӵ�ı�ţ�" << endl;
		cin >> endVertex;
		while (endVertex != -1)
		{
			int weight = 0;
			cout << "�����������ߵ�Ȩֵ��" << endl;
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
			cout << "��������һ���ڽӵ�ı�ţ���-1������" << endl;
			cin >> endVertex;
		}
		Nodes.push_back(node);
		cout << "��������һ����ı�ţ���-1������" << endl;
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
		cout << "����ţ�" << nodes[i]->Vertex << " ";
		Edge *next = nodes[i]->FirstEdge;
		int Degree = 0;
		while (next != NULL)
		{
			Degree++;
			cout << "��ӵ��ţ�" << next->AdjVer << " Ȩֵ��" << next->Weight << " ";
			next = next->NextEdge;
		}
		cout << endl << "�� " << nodes[i]->Vertex << " �ĳ��ȣ�" << Degree << endl;
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
			cout << "�� " << iter->first << " �Ķ�Ϊ 0" << endl;
		}
	}
	cout << "�� " << max_node << " ������� Ϊ" << max_degree << endl;
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
	//��tempnodes��������Ϊ������0������select������������nodes�ľͼ���ѭ��
	while (true)
	{
		TempEdge = temp->FirstEdge;
		while (TempEdge != NULL)
		{
			cout << TempEdge->AdjVer << " -> ";
			//�������ظ��������棬���ұ����һ��edge��ѭ���������ظ���ɾ��tempnode�������һ��������ѭ��
			selected.push_back(TempEdge->AdjVer);//����ǰ�����

			//��tempnode��firstedge�ǿյģ��򲻱��棬������ѭ��
			Node *tempnode = GetNodeFromEdge(Nodes, TempEdge);
			TempNodes.push_back(tempnode);
			//��i���������һ��
			i++;
			TempEdge = TempNodes[i]->FirstEdge;
			//TempEdge = TempEdge->NextEdge;
		}

		if (TempNodes.size() > 0)
		{
			//temp����������һ��

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

