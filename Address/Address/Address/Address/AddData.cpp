#include "AddData.h"

#include <iostream>

AddData::AddData(string &name, string &tel)
		:_name(name), _tel(tel)
{
}

AddData::~AddData()
{
}

void AddData::Display() 
{
	cout << "name : " << _name << endl;
	cout << "tel : " << _tel << endl;
}

bool AddData::operator==(const string &name)
{
	return this->_name == name;
}
