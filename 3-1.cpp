#include <iostream>
using namespace std;
const int MaxLen = 100;
template <class DataType>
class Queue
{
public:
	Queue();
	void push(DataType);
	DataType pop();
	DataType top();
	bool emety(){ TopPoint == ButtomPoint ? return true : return false };
	DataType Elements[MaxLen];
	int TopPoint, ButtomPoint;
private:

};
template <class DataType>
Queue<DataType>::Queue()
{
	TopPoint = ButtomPoint = MaxLen - 1;
}
template <class DataType>
void Queue<DataType>::push(DataType element)
{
	if ((ButtomPoint + 1) % MaxLen == TopPoint) throw "иорГ";
	ButtomPoint = (ButtomPoint + 1) % MaxLen;
	Elements[ButtomPoint] = element;
}
template <class DataType>
DataType Queue<DataType>::pop()
{
	if (ButtomPoint == TopPoint) throw "обрГ";
	TopPoint = (TopPoint + 1) % MaxLen;
	return Elements[TopPoint];
}

template <class DataType>
DataType Queue<DataType>::top()
{
	if (ButtomPoint == TopPoint) throw "обрГ";
	int i = (TopPoint + 1) % MaxLen;
	return Elements[i];
}
int main()
{

	system("pause");
	return 0;
}

