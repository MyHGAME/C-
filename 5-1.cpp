#include <iostream>
#include <vector>
using namespace std;
struct BiNode
{
	int value;
	char code;
	char codes[100];
	BiNode *lchild;
	BiNode *rchild;
	BiNode *parent;
};
vector<BiNode *> Create(vector<int>);
vector<BiNode *> ChangeToBiTree(vector<BiNode *> Nodes);
vector<BiNode *> SortByValue(vector<BiNode *>);
vector<BiNode *> InsertSort(vector<BiNode*> Nodes);
vector<BiNode *> InsertSort2(vector<BiNode*> Nodes);
void PreOrder(BiNode *bt);
vector<int> InData()
{
	vector<int> datas;
	int data;
	cin >> data;
	while (data != 0)
	{
		datas.push_back(data);
		cin >> data;
	}
	return datas;
}

vector<BiNode *> ChangeToBiNode(vector<int> datas)
{
	vector<BiNode *> Nodes;
	for (int i = 0; i <datas.size(); i++)
	{
		BiNode *Node = new BiNode();
		Node->value = datas[i];
		Node->lchild = NULL;
		Node->rchild = NULL;
		Node->parent = NULL;
		Nodes.push_back(Node);
	}
	return Nodes;
}

vector<BiNode *> SortByValue(vector<BiNode*> Nodes)
{
	for (int i = 0; i < Nodes.size() - 1; i++)
	{
		for (int j = i + 1; j < Nodes.size(); j++)
		{
			if (Nodes[i]->value < Nodes[j]->value)
			{
				BiNode *Temp = new BiNode();
				Temp = Nodes[i];
				Nodes[i] = Nodes[j];
				Nodes[j] = Temp;
				//swap(Nodes[i], Nodes[j]);
			}
		}
	}
	cout << "data: ";
	for (int i = 0; i < Nodes.size(); i++)
	{
		cout << Nodes[i]->value << "  ";
	}
	return Nodes;
}

vector<BiNode *> InsertSort(vector<BiNode*> Nodes)
{
	if (Nodes.size() != 1)
	{
		BiNode *Node = Nodes.back();
		Nodes.pop_back();
		vector<BiNode*>::iterator iter;
		for (iter = Nodes.begin(); iter != Nodes.end(); iter++)
		{
			if (Node->value >= (*iter)->value)
			{
				Nodes.insert(iter, Node);
				return Nodes;
			}
		}
	}
	return Nodes;
}

vector<BiNode *> InsertSort2(vector<BiNode*> Nodes)
{
	if (Nodes.size() != 1)
	{
		BiNode *Node = Nodes.back();
		Nodes.pop_back();
		vector<BiNode*>::iterator iter;
		for (iter = Nodes.begin(); iter != Nodes.end(); iter++)
		{
			if (Node->value > (*iter)->value)
			{
				Nodes.insert(iter, Node);
				return Nodes;
			}
		}
		Nodes.push_back(Node);
	}
	return Nodes;
}

vector<BiNode *> ChangeToBiTree(vector<BiNode *> Nodes)
{
	if (Nodes.size() >= 2)
	{
		BiNode *Node = new BiNode();
		//对最小的两个权值进行相加，将相加后的结果放回原来的数组
		Node->value += Nodes.back()->value;
		Nodes.back()->parent = Node;
		Nodes.back()->code = '0';
		Node->lchild = Nodes.back();
		Nodes.pop_back();
		//重复，略显啰嗦，要修改
		Node->value += Nodes.back()->value;
		Nodes.back()->parent = Node;
		Nodes.back()->code = '1';
		Node->rchild = Nodes.back();
		Nodes.pop_back();
		Nodes.push_back(Node);
		//两种不同的插入后进行排序的方法
		//Nodes = InsertSort(Nodes);
		Nodes = InsertSort2(Nodes);
		//进行递归
		Nodes = ChangeToBiTree(Nodes);
	}
	return Nodes;

}

void PreOrder(BiNode *bt)
{
	if (bt == NULL) return;
	else
	{
		cout << bt->value << " ";
		PreOrder(bt->lchild);
		PreOrder(bt->rchild);
	}
}

void CodeOrder(BiNode *bt)
{
	if (bt->lchild == NULL && bt->rchild == NULL)
	{
		BiNode *node = bt;
		cout << "value: ";
		cout << bt->value << "  ";
		vector<char> codes;
		vector<char>::reverse_iterator iter;
		while (bt->parent != NULL)
		{
			codes.push_back(bt->code);
			bt = bt->parent;
		}
		cout << "codes: ";
		int i = 0;
		for (iter = codes.rbegin(); iter != codes.rend(); iter++)
		{
			cout << *iter << " ";
			node->codes[i] = *iter;
			i++;
		}
		cout << endl;
	}
	else
	{
		CodeOrder(bt->lchild);
		CodeOrder(bt->rchild);
	}
}
int main()
{
	vector<int> datas = InData();
	vector<BiNode*> Nodes = ChangeToBiNode(datas);
	Nodes = SortByValue(Nodes);
	Nodes = ChangeToBiTree(Nodes);
	BiNode* Root = Nodes.back();
	cout << endl << "前序排序：" << endl;
	PreOrder(Root);
	cout << endl;
	CodeOrder(Root);
	system("pause");
	return 0;
}

