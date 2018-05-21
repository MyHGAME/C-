#include <iostream>
#include <string>
using namespace std;
const int MaxLen = 100;
template <class DataType>
class TheStack
{
public:
	TheStack();
	void push(char, DataType);
	DataType pop(char);
	DataType top(char);
	bool emety(){ LTopPoint == -1 && RTopPoint == MaxLen ? return true : return false };
	DataType Stack[MaxLen];
	int LTopPoint, LButtomPoint;
	int RTopPoint, RButtomPoint;
private:

};
template <class DataType>
TheStack<DataType>::TheStack()
{
	LTopPoint = -1, LButtomPoint = 0;
	RTopPoint = MaxLen, LButtomPoint = MaxLen - 1;
}
template <class DataType>
void TheStack<DataType>::push(char direct, DataType element)
{
	if (LTopPoint + 1 == RTopPoint) throw "栈满";
	if (direct == 'r')
	{
		Stack[--RTopPoint] = element;
	}
	else if (direct == 'l')
	{
		Stack[++LTopPoint] = element;
	}
}
template <class DataType>
DataType TheStack<DataType>::pop(char direct)
{
	if (direct == 'r')
	{
		if (RTopPoint == MaxLen) throw "右栈为空";
		return Stack[RTopPoint++];
	}
	if (direct == 'l')
	{
		if (LTopPoint == -1) throw "左栈为空";
		return Stack[LTopPoint--] ;
	}

}

template <class DataType>
DataType TheStack<DataType>::top(char direct)
{
	if (direct == 'r')
	{
		return Stack[RTopPoint];
	}
	if (direct == 'l')
	{
		return Stack[LTopPoint];
	}
}
int main()
{
	TheStack<int> test;
	
	try
	{
		cout<<""
		while()
		{
		}
	}
	catch(string e)
	{
		cout<<e;
	}
	system("pause");
	return 0;
}
