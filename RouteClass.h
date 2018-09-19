#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<fstream>
#include<stdio.h>

using namespace std;

class Route
{
public:
	string Place[2];
	float Distance;
	Route(){}
	Route(string place1,string place2,float distance)
	{
		Place[0] = place1;
		Place[1] = place2;
		Distance = distance;
	}

	Route(char* place1, char* place2, float distance)
	{
		Place[0] = place1;
		Place[1] = place2;
		Distance = distance;
	}
};

class RouteManager
{
public:
	RouteManager();
	RouteManager(string);
	~RouteManager();
	vector<Route> Routes;
	void LoadRoute(string);
	void SaveRoute(string);
	void InputRoute();
	void ShowRoute();
	void GetShortRoute();
private:
	vector<string> GetAllPlaces();
};

RouteManager::RouteManager()
{

}

RouteManager::RouteManager(string name)
{
	LoadRoute(name);
}

void RouteManager::InputRoute()
{
	char IsEnd;
	do
	{
		string Place1, Place2;
		float Distance;
		cout << "输入地方1名字 地方2名字 距离（公里）：（格式：广州 上海 1999）" << endl;
		cin >> Place1 >> Place2 >> Distance;
		Route route(Place1, Place2, Distance);
		Routes.push_back(route);
		cout << "输入 y 继续录入线路"<<endl;
		cin >> IsEnd;
	} while (IsEnd == 'y');
	
}

void RouteManager::LoadRoute(string name)
{
	char Buffer[100];
	ifstream In(name);
	if (!In.is_open)
	{
		cout << "no file";
	}
	else
	{
		while (!In.eof())
		{
			char * Token[3];
			int index = 0;
			In.getline(Buffer, 100);
			char *TempStr = strtok(Buffer," ");
			while (TempStr != NULL)
			{
				Token[index++] = TempStr;
				TempStr = strtok(NULL, " ");
			}
			Route route(Token[0], Token[1], stof(Token[2]));
			Routes.push_back(route);
		}
	}
	
}

void RouteManager::SaveRoute(string name)
{
	ofstream Out(name);
	if (Out.is_open)
	{
		for (int i = 0; i < Routes.size; i++)
		{
			Out << Routes[i].Place[0] << ' ' << Routes[i].Place[1] << ' ' << Routes[i].Distance << endl;
		}
	}
}

void RouteManager::ShowRoute()
{
	for (int i = 0; i < Routes.size; i++)
	{
		cout << Routes[i].Place[0] << ' ' << Routes[i].Place[1] << ' ' << Routes[i].Distance << endl;
	}
}

void RouteManager::GetShortRoute()
{
	string StartPlace, AimPlace;
	vector<float> Distances;
	vector<string> ResultPlaces;
	vector<string> PendingPlaces;
	vector<string> AllPlaces = GetAllPlaces();
	int ShortDistancePos = 0;
	cout << "输入出发地 目的地" << endl;
	cin >> StartPlace >> AimPlace;
	for (int i = 0; i < Routes.size; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			
		}
	}
}

vector<string> RouteManager::GetAllPlaces()
{
	vector<string> AllPlaces;
	for (int i = 0; i < Routes.size; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			int Have = 0;
			for (int l = 0; l < AllPlaces.size; l++)
			{
				if (AllPlaces[l] == Routes[i].Place[j])
				{
					Have = 1;
					break;
				}
			}
			if (!Have)
			{
				AllPlaces.push_back(Routes[i].Place[j]);
			}
		}
	}
	return AllPlaces;
}

RouteManager::~RouteManager()
{
}
