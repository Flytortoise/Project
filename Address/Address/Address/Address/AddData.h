#pragma once

/*
	用户信息类
*/

#include <string>

using namespace std;

class AddData
{
public:
	AddData(string &name, string &tel);	//通过构造函数来设置信息
	~AddData();
	
	void Display();		//打印用户信息
	bool operator==(const string &name);	//重载等号，在管理类中的find算法用到
					//此处一定要加const，否则重载错误
private:
	string _name;	//用户姓名
	string _tel;	//用户电话
};

