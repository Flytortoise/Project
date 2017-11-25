#pragma once

/*
	�����û���
*/

#include "AddData.h"
#include <list>

using namespace std;

class Manager
{
public:
	Manager();
	~Manager();

	void Display();
	int Add();
	int Func(int);

	enum
	{
		Del,
		Search,
		Change,
		SUCCESS,
		FAIL
	};


private:
	list<AddData> _manager;
	void _PointOut(int);	//��ӡ��ʾ��Ϣ
	void _PointOut(int, list<AddData>::iterator &);
};

