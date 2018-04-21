#include <iostream>
#include <vector>
using namespace std;

vector<char> Create(vector<char> root)
{
	char data;
	cin >> data;
	while (data != '#')
	{
		root.push_back(data);
		cin >> data;
	}
	return root;
}
void InOrder(vector<char> root, int n)
{
	if (n >= root.size() || root[n] == NULL) return;
	else
	{
		InOrder(root, 2 * n + 1);
		cout << root[n];
		InOrder(root, 2 * n + 2);
	}

}

void PreOrder(vector<char> root, int n)
{
	if (n >= root.size() || root[n] == NULL) return;
	else
	{
		cout << root[n];
		PreOrder(root, 2 * n + 1);
		PreOrder(root, 2 * n + 2);
	}

}

void PostOrder(vector<char> root, int n)
{
	if (n >= root.size() || root[n] == NULL) return;
	else
	{
		PostOrder(root, 2 * n + 1);
		PostOrder(root, 2 * n + 2);
		cout << root[n];
	}

}

int main()
{
	vector<char> root;
	root = Create(root);
	for (int i = 0; i < root.size(); i++)
	{
		cout << root[i] << " ";
	}
	cout << endl;
	cout << "ǰ�������";
	PreOrder(root, 0);
	cout << endl;
	cout << "���������";
	InOrder(root, 0);
	cout << endl;
	cout << "���������";
	PostOrder(root, 0);
	cout << endl;
	system("pause");
	return 0;
}

