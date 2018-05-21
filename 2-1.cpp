#include <iostream>
#include <stack>
#include <list>
#include <string>
#include <sstream>
#include <cctype>
#include <math.h>
#include <stdlib.h>
using namespace std;
bool isnum(string);
bool IsUp(string, string);
list<string> Change(list<string>);
double Operation(list<string>);
list<string> InData(string s);
list<string> InData(string s)
{

	list<string> thelist;
	int n = 0;
	while(n < s.size())
	{
		if(isdigit(s[n]))
		{
			int i = n;
			float sum = 0;
			while(isdigit(s[i]))
			{
				sum *=10;
				sum = sum + (s[i]-48);
				i++;
			}
			if(s[i] == '.')
			{
				int j = i+1,num = -1;
				float sum2 = 0;
				while(isdigit(s[j]))
				{
					sum2 += (s[j]-48)*pow(10,num);
					num--;
					j++;
				}
				i = j ;
				sum += sum2;
			}
			ostringstream oss;  //创建一个格式化输出流
            oss<<sum;             //把值传递如流中
			thelist.push_back(oss.str());
			n = i-1;
		}
		else
		{
            string str(1, s[n]);
			thelist.push_back(str);
		}
		n++;
	}
	return thelist;
}

bool IsUp(string a, string b)
{
	if (b == "(")
	{
		return true;
	}
	else if (a == "*" || a == "/" || a == "%")
	{
		if (b == "+" || b == "-")
			return true;
	}
	return false;
}
bool isnum(string s)
{
	stringstream sin(s);
	double t;
	char p;
	if (!(sin >> t))
		return false;
	if (sin >> p)
		return false;
	else
		return true;
}
//将表达式转换成后缀表达式
list<string> Change(list<string> A)
{
	int ArrLenth = 0;
	list<string> Expression;
	stack<string> theOperator;
	list<string>::iterator iter;
	for (iter = A.begin(); iter != A.end(); iter++)
	{
		if (isnum(*iter))
		{
			Expression.push_back(*iter);
		}
		else
		{
			if (theOperator.empty() || *iter == "(" || IsUp(*iter, theOperator.top()))
			{
				theOperator.push(*iter);

			}
			else if (!IsUp(*iter, theOperator.top()))
			{

				if (*iter == ")")
				{
					while (!theOperator.empty())
					{

						if (theOperator.top() == "(")
						{
							theOperator.pop();
							break;
						}
						Expression.push_back(theOperator.top());
						theOperator.pop();
					}

				}
				else
				{
					Expression.push_back(theOperator.top());
					theOperator.pop();
					theOperator.push(*iter);
				}
			}
		}
	}
	while (!theOperator.empty()){
		Expression.push_back(theOperator.top());
		theOperator.pop();
	}
	return Expression;
}

double Operation(list<string> Expression)
{
	stack<double> result;
	list<string>::iterator iter;
	cout << endl << "计算过程：";
	try
	{
		for (iter = Expression.begin(); iter != Expression.end(); iter++)
		{
			if (isnum(*iter))
			{
				stringstream s(*iter);
				double num;
				s >> num;
				result.push(num);
			}
			else
			{
				double BeOperator = 0;
				double Operator = 0;
				double OperationResult = 0;
				BeOperator = result.top();
				result.pop();
				Operator = result.top();
				result.pop();
				if (*iter == "+")
				{
					OperationResult = Operator + BeOperator;
				}
				else if (*iter == "-")
				{
					OperationResult = Operator - BeOperator;
				}
				else if (*iter == "*")
				{
					OperationResult = Operator * BeOperator;
				}
				else if (*iter == "%")
				{
					OperationResult = (int)Operator * (int)BeOperator;
				}
				else if (*iter == "/")
				{
					if (BeOperator == 0) throw 0;
					OperationResult = Operator / BeOperator;
				}
				cout << endl << Operator << " " << *iter << " " << BeOperator << " = " << OperationResult;
				result.push(OperationResult);
			}
		}
	}
	catch (int e)
	{
		if (e == 0)
		{
			cout << "出现除 0 错误" << endl;
		}
	}

	return result.top();
}
int main()
{
//	list<string> test;
//	test.push_back("(");
//	test.push_back("12");
//	test.push_back("*");
//	test.push_back("23");
//	test.push_back("*");
//	test.push_back("(");
//	test.push_back("31");
//	test.push_back("+");
//	test.push_back("63");
//	test.push_back("-");
//	test.push_back("43");
//	test.push_back("*");
//	test.push_back("(");
//	test.push_back("6");
//	test.push_back("+");
//	test.push_back("62");
//	test.push_back(")");
//	test.push_back(")");
//	test.push_back(")");
//	test.push_back("+");
//	test.push_back("6");
//	test.push_back("+");
//	test.push_back("62");
//	list<string> Expression = Change(test);
//	list<string>::iterator iter;
//	cout << "原表达式：" << endl;
//	for (iter = test.begin(); iter != test.end(); iter++)
//	{
//		cout << " " << *iter;
//	}
//	cout << endl;
//	cout << "后缀表达式：" << endl;
//	for (iter = Expression.begin(); iter != Expression.end(); iter++)
//	{
//		cout << " " << *iter;
//	}
//	cout << endl << "结果：" << Operation(Expression) << endl;
	string s;
	cin>>s;
    list<string> data = InData(s);
    data = Change(data);
    list<string>::iterator iter2;
	for(iter2 = data.begin();iter2 != data.end();iter2++)
	{
		cout << " " << *iter2;
	}
		cout << endl << "结果：" << Operation(data) << endl;
	system("pause");
	return 0;
}
