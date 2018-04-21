//δ���ƣ�һ���ַ����������������ţ�����Ҫһ����������������
//�������ȼ�������
#include <iostream>
#include <stack>
#include <list>
#include <string>
#include <sstream>
using namespace std;
bool isnum(string);
bool IsUp(string, string);
list<string> Change(list<string>);
double Operation(list<string>);
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
//�����ʽת���ɺ�׺���ʽ
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
	if (!theOperator.empty()){
		Expression.push_back(theOperator.top());
	}
	return Expression;
}

double Operation(list<string> Expression)
{
	stack<double> result;
	list<string>::iterator iter;
	cout << endl << "������̣�";
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
			cout << "���ֳ� 0 ����" << endl;
		}
	}

	return result.top();
}
int main()
{
	list<string> test;
	test.push_back("(");
	test.push_back("12");
	test.push_back("*");
	test.push_back("23");
	test.push_back("*");
	test.push_back("(");
	test.push_back("31");
	test.push_back("+");
	test.push_back("63");
	test.push_back("-");
	test.push_back("43");
	test.push_back("*");
	test.push_back("(");
	test.push_back("6");
	test.push_back("+");
	test.push_back("62");
	test.push_back(")");
	test.push_back(")");
	test.push_back(")");
	test.push_back("+");
	test.push_back("6");
	test.push_back("+");
	test.push_back("62");
	list<string> Expression = Change(test);
	list<string>::iterator iter;
	cout << "ԭ���ʽ��" << endl;
	for (iter = test.begin(); iter != test.end(); iter++)
	{
		cout << " " << *iter;
	}
	cout << endl;
	cout << "��׺���ʽ��" << endl;
	for (iter = Expression.begin(); iter != Expression.end(); iter++)
	{
		cout << " " << *iter;
	}
	cout << endl << "�����" << Operation(Expression) << endl;
	system("pause");
	return 0;
}

