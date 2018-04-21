#include <iostream>
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
	if (LTopPoint + 1 == RTopPoint) throw "…œ“Á";
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
		if (RTopPoint0 == MaxLen) throw "…œ“Á";
		return Stack[RTopPoint++];
	}
	if (direct == 'l')
	{
		if (LTopPoint0 == -1) throw "œ¬“Á";
		return Stack[LTopPoint--] = element;
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
	test.push('r', 100);
	test.push('l', 1002);
	cout << test.top('r') << endl << test.top('l') << endl;
	system("pause");
	return 0;
}

