#include <iostream>
#include <string>
#include <list>
using namespace std;
void Manager(int, int);
void Manager(int TheCoachNum, int TheTruckNum)
{
	int CoachNum = 0, AllCoachNum = 0;
	int TruckNum = 0;
	list<string> thelist;
	int i = 0;
	while (true)
	{
		if (TheCoachNum == 0 && TheTruckNum == 0)
			break;
		//�ͳ��Ѿ�������
		if (CoachNum != 0 && CoachNum % 4 == 0)
		{
			if (TheTruckNum > 0)
			{
				TruckNum++;
				TheTruckNum--;
				thelist.push_back("��");
			}
			else
			{
				if (TheCoachNum > 0)
				{
					CoachNum++;
					AllCoachNum++;
					TheCoachNum--;
					thelist.push_back("��");
				}
			}
			CoachNum = 0;
		}
		else
		{
			if (TheCoachNum > 0)
			{
				CoachNum++;
				AllCoachNum++;
				TheCoachNum--;
				thelist.push_back("��");
			}
			else
			{
				if (TheTruckNum > 0)
				{
					TruckNum++;
					TheTruckNum--;
					thelist.push_back("��");
				}
				CoachNum = 0;
			}

		}
		if (TruckNum + AllCoachNum == 10)
		{
			i++;
			TruckNum = 0;
			AllCoachNum = 0;
			list<string>::iterator iter;
			cout << "�� " << i << " ������ :  ";
			for (iter = thelist.begin(); iter != thelist.end(); iter++)
			{
				cout << " " << *iter;
			}
			cout << endl;
			thelist.clear();
		}
	}
}
int main()
{
	int TheCoachNum = 645;
	int TheTruckNum = 550;
	Manager(TheCoachNum, TheTruckNum);
	system("pause");
	return 0;
}

