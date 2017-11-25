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
	_PointOut(t);	//打印提示信息
	cin >> name;
	auto it = find(_manager.begin(), _manager.end(), name);
	if (it == _manager.end())
	{
		cout << "No Person" << endl;
		return FAIL;	//此处应该抛出异常
	}
	else
	{
		_PointOut(t, it);	//分别进行处理
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
		//此处应该抛出异常
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
		swap(*temp, *it);	//交换两者的内容，达到更新的目的
		delete temp;
		temp = nullptr;
		break;

	default:
		//此处应该抛出异常
		break;
	}
}
