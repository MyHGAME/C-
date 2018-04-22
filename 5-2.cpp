#include <iostream>
#include <vector>
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
	}
}


int main()
{
	vector<Node *> Nodes = Create();
	GetAllNodes(Nodes);
	system("pause");
	return 0;
}

