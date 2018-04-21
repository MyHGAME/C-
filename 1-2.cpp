#include <iostream>
#include <string>
#include <sstream>
using namespace std;
struct TheList
{
	int data = 0;
	TheList *next;
	TheList *prior;
};
TheList *CreateList();
TheList *ChangeList(TheList *head);
TheList *InData();
void Test();
int main()
{
	TheList *head = CreateList();
	TheList *p = ChangeList(head);
	cout << "输入数据：" << endl;
	Test();
	system("pause");
	return 0;
}
void Test()
{
	TheList *Test = InData();
	Test = ChangeList(Test);
	cout << endl;
}
TheList *InData()
{
	TheList *head = NULL, *h = NULL;
	string In;
	int data = 0;
	cin >> In;
	while (In != "#")
	{
		stringstream s(In);
		s >> data;
		if (head == NULL)
		{
			head = new TheList();
			head->data = data;
			h = head;
			continue;
		}
		TheList *p = new TheList();
		//p->next = new TheList();
		p->data = data;
		p->next = head;
		h->next = p;
		h = p;
		cin >> In;
	}

	TheList *p = head;
	while (p != NULL)
	{
		cout << p->data << endl;
		p = p->next;
		if (p == head)break;
	}
	cout << endl;
	return head;
}

TheList *CreateList()
{
	int A[] = { 1, 2, 2, 3, 4, 5, 7, 9, -2, 3, -4, 5, -6, 7 };
	TheList *head = NULL, *h = NULL;
	int ArrLenth = sizeof(A) / sizeof(int);
	for (int i = 0; i < ArrLenth; i++)
	{
		if (head == NULL)
		{
			head = new TheList();
			head->data = A[0];
			h = head;
			continue;
		}
		TheList *p = new TheList();
		//p->next = new TheList();
		p->data = A[i];
		h->next = p;
		h = p;
		h->next = head;
	}
	TheList *p = head;
	while (p != NULL)
	{
		cout << p->data << endl;
		p = p->next;
		if (p == head)break;
	}
	cout << endl;
	return head;
}

TheList *ChangeList(TheList *head)
{
	TheList *p = head, *q = head;
	while (p != NULL)
	{
		cout << p->data << endl;
		//关键
		p->next->prior = p;
		p = p->next;
		if (p == head)break;
	}
	cout << endl;
	while (q != NULL)
	{
		cout << "next->data: " << q->next->data << endl << "prior->data: " << q->prior->data << endl << "data: " << q->data << endl;
		q = q->next;
		if (q == head)break;
	}

	return p;
}
