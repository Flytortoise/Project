#pragma once

/*
	�û���Ϣ��
*/

#include <string>

using namespace std;

class AddData
{
public:
	AddData(string &name, string &tel);	//ͨ�����캯����������Ϣ
	~AddData();
	
	void Display();		//��ӡ�û���Ϣ
	bool operator==(const string &name);	//���صȺţ��ڹ������е�find�㷨�õ�
					//�˴�һ��Ҫ��const���������ش���
private:
	string _name;	//�û�����
	string _tel;	//�û��绰
};

