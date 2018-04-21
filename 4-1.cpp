#include <iostream>
#include <list>
using namespace std;

template<class DataType>
struct BiNode
{
	DataType data;
	BiNode<DataType> *lchild, *rchild;
};
template<class DataType>
class BiTree
{
public:
	BiTree(){ Root = Create(Root); };
	~BiTree(){ Release(Root); };
	void PreOrder(){ PreOrder(Root); };
	void InOrder(){ InOrder(Root); };
	void PostOrder(){ PostOrder(Root); };
	void NonRecursivePreOrder(){ NonRecursivePreOrder(Root); };
	void LeverOrder();
private:
	BiNode<DataType> *Root;
	BiNode<DataType> *Create(BiNode<DataType>*);
	void Release(BiNode<DataType>*);
	void PreOrder(BiNode<DataType>*);
	void InOrder(BiNode<DataType>*);
	void PostOrder(BiNode<DataType>*);
	void NonRecursivePreOrder(BiNode<DataType>*);

};
template<class DataType>
BiNode<DataType> *BiTree<DataType>::Create(BiNode<DataType> *bt)
{
	DataType data;
	cin >> data;
	if (data == '#') bt = NULL;
	else
	{
		bt = new BiNode<DataType>();
		bt->data = data;
		bt->lchild = Create(bt->lchild);
		bt->rchild = Create(bt->rchild);
	}
	return bt;
}
template<class DataType>
void BiTree<DataType>::PreOrder(BiNode<DataType> *bt)
{
	if (bt == NULL) return;
	else
	{
		cout << bt->data;
		PreOrder(bt->lchild);
		PreOrder(bt->rchild);
	}
}
template<class DataType>
void BiTree<DataType>::InOrder(BiNode<DataType> *bt)
{
	if (bt == NULL) return;
	else
	{
		InOrder(bt->lchild);
		cout << bt->data;
		InOrder(bt->rchild);
	}
}
template<class DataType>
void BiTree<DataType>::PostOrder(BiNode<DataType> *bt)
{
	if (bt == NULL) return;
	else
	{
		PostOrder(bt->lchild);
		PostOrder(bt->rchild);
		cout << bt->data;
	}
}
template<class DataType>
void BiTree<DataType>::LeverOrder()
{
	list<BiNode<DataType>*> List;
	list<BiNode<DataType>*>::iterator iter;
	BiNode<DataType> *Point = new BiNode<DataType>();
	if (Root == NULL) return;
	List.push_back(Root);
	iter = List.begin();
	while (iter != List.end())
	{
		Point = *iter;
		cout << Point->data << " ";
		if (Point->lchild != NULL) List.push_back(Point->lchild);
		if (Point->rchild != NULL) List.push_back(Point->rchild);
		iter++;
	}
}

template<class DataType>
void BiTree<DataType>::Release(BiNode<DataType>* bt)
{
	if (bt == NULL) return;
	Release(bt->lchild);
	Release(bt->rchild);
	delete bt;
}

template<class DataType>
void BiTree<DataType>::NonRecursivePreOrder(BiNode<DataType> *bt)
{
	list<BiNode<DataType>*> List;
	list<BiNode<DataType>*>::iterator iter = List.begin();
	int index = -1;
	while (bt != NULL || index != -1)
	{
		while (bt != NULL)
		{
			cout << bt->data << " ";
			List.push_back(bt);
			index++;
			bt = bt->lchild;
		}
		if (index != -1)
		{
			bt = List.back()->rchild;
			index--;
			List.pop_back();
		}
	}
}

int main()
{
	BiTree<char> test;
	cout << endl << "前序：" << endl;
	test.PreOrder();
	cout << endl << "非递归前序：" << endl;
	test.NonRecursivePreOrder();
	cout << endl << "中序：" << endl;
	test.InOrder();
	cout << endl << "后序：" << endl;
	test.PostOrder();
	cout << endl << "层级：" << endl;
	test.LeverOrder();
	system("pause");
	return 0;
}

