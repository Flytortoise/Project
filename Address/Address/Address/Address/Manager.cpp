#include "Manager.h"
#include <iostream>
#include <string>

#include <algorithm>

using namespace std;


Manager::Manager()
{
}


Manager::~Manager()
{
	_manager.clear();
}

void Manager::Display()
{
	for (auto data : _manager) {
		data.Display();
	}
}

int Manager::Add()
{
	string name;
	string tel;
	cout << "Please input new Person name :" << endl;
	cin >> name;
	cout << "Please input new Person tel :" << endl;
	cin >> tel;

	_manager.push_back(AddData(name, tel));

	return 0;
}

int Manager::Func(int t)
{
	string name;
	_PointOut(t);	//��ӡ��ʾ��Ϣ
	cin >> name;
	auto it = find(_manager.begin(), _manager.end(), name);
	if (it == _manager.end())
	{
		cout << "No Person" << endl;
		return FAIL;	//�˴�Ӧ���׳��쳣
	}
	else
	{
		_PointOut(t, it);	//�ֱ���д���
	}

	return SUCCESS;

}


void Manager::_PointOut(int t)
{
	cout << "Please input ";

	switch (t)
	{
	case Del:
		cout << "Del" ;
		break;
	case Search:
		cout << "Search";
		break;
	case Change:
		cout << "Change";
		break;

	default:
		//�˴�Ӧ���׳��쳣
		break;
	}

	cout << " Person name :" << endl;
}

void Manager::_PointOut(int t, list<AddData>::iterator &it)
{
	string name;
	string tel;
	AddData *temp;

	switch (t)
	{
	case Del:
		_manager.erase(it);
		break;

	case Search:
		it->Display();
		break;

	case Change:		
		cout << "Please input new name : " << endl;
		cin >> name;
		cout << "Please input new tel : " << endl;
		cin >> tel;
		temp = new AddData(name, tel);	
		swap(*temp, *it);	//�������ߵ����ݣ��ﵽ���µ�Ŀ��
		delete temp;
		temp = nullptr;
		break;

	default:
		//�˴�Ӧ���׳��쳣
		break;
	}
}
