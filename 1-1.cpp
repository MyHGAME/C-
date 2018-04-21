#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
vector<int> InData();
void Order(vector<int> Test);
void Test();
vector<int> InData()
{
	vector<int> Test;
	string In;
	int data = 0;
	cin >> In;
	while (In != "#")
	{
		stringstream s(In);
		s >> data;
		Test.push_back(data);
		cin >> In;
	}
	return Test;
}
void Order(vector<int> Test)
{
	int i = 0, j = Test.size() - 1;
	while (i<j)
	{
		while (Test[i]<0)  i++;
		while (Test[j]>0) j--;
		if (i<j)  swap(Test[i], Test[j]);   //交换a[i], a[j]的值
	}
	for (int k = 0; k < Test.size(); k++)
	{
		cout << Test[k] << " ";
	}
}
void Test()
{
	vector<int> Test = InData();
	Order(Test);
	cout << endl;
}
int main()
{
	int A[] = { 0, 1, -1, 1, 1, 2, 3, 4, 5, 6, -2, 7, 8, -2, -4, 9, -1, -2, -3, -4, -6, -8, 9 };
	const int ArrLength = sizeof(A) / sizeof(int);
	int i = 0, j = ArrLength - 1;
	int temp = 0;
	/*while (true)
	{
	while (A[i] < 0)
	{
	i++;
	}
	while (A[j] > 0)
	{
	j--;
	}
	if (i >= j)
	{
	break;
	}
	temp = A[i];
	A[i] = A[j];
	A[j] = temp;
	}*/
	cout << "原数据：" << endl;
	for (int k = 0; k < ArrLength; k++)
	{
		cout << A[k] << " ";
	}
	cout << endl;
	while (i<j)
	{
		while (A[i]<0)  i++;
		while (A[j]>0) j--;
		if (i<j)  swap(A[i], A[j]);   //交换a[i], a[j]的值
	}
	cout << "处理后数据：" << endl;
	for (int k = 0; k < ArrLength; k++)
	{
		cout << A[k] << " ";
	}
	cout << endl;
	cout << "输入数据：" << endl;
	Test();
	system("pause");
	return 0;
}

