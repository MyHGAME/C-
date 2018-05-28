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
	if (LTopPoint + 1 == RTopPoint) throw 1;
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
		if (RTopPoint == MaxLen) throw 2;
		return Stack[RTopPoint++];
	}
	if (direct == 'l')
	{
		if (LTopPoint == -1) throw 3;
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
	
	
		int n = 0;
		cout<<"1.入栈 2.出栈 3.输出全部栈"<<endl;
		cin>>n;
		while(n != 0)
		{
			char dir = ' ';
			int data = 0;
			
			switch(n)
			{
				case 1:
					cout<<"输入格式为 (哪一个栈)r/l (栈的数据)data"<<endl;
					cin>>dir>>data;
					test.push(dir,data);
				break;
				case 2:
					try{
						cout<<"输入格式为 (哪一个栈)r/l"<<endl;
						cin>>dir;
						data = test.pop(dir);
						cout<<"data: "<<data<<endl;
					}
					catch(int e)
					{
						//将e错误抛出
						cout<<e<<endl;
					}
					
				break;
				case 3:
					int l =  test.LTopPoint;
					int r = test.RTopPoint;
					cout<<"左边栈为："<<endl;
					for(l;l > -1;l--)
						cout<<test.Stack[l]<<"  ";
					cout<<endl;
					cout<<"右边栈为："<<endl;
					for(r;r < MaxLen;r++)
						cout<<test.Stack[r]<<"  ";
					cout<<endl;
				break;
			}
			cout<<"1.入栈 2.出栈 3.输出全部栈"<<endl;
			cin>>n;
			
		}
	system("pause");
	return 0;
}
