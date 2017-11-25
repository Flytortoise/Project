#include <iostream>
#include "Manager.h"
using namespace std;

void InterFace()	//字符界面
{
	cout << "+-------------------------------+" << endl;
	cout << "|     Address        List       |" << endl;
	cout << "+-------------------------------+" << endl;
	cout << "|     1.Add      |   2.Del      |" << endl;
	cout << "|     3.Change   |   4.Search   |" << endl;
	cout << "|     5.Display  |   6.Exit     |" << endl;
	cout << "+-------------------------------+" << endl;
	cout << "Please input Func number :";
}

int main()
{
	int flag = 1;
	Manager manager;	//管理类，用来管理用户

	while (flag)
	{
		InterFace();
		cin >> flag;
		switch (flag)
		{
		case 1:
			manager.Add();
			break;
		case 2:
			manager.Func(Manager::Del);
			break;
		case 3:
			manager.Func(Manager::Change);
			break;
		case 4:
			manager.Func(Manager::Search);
			break;
		case 5:
			manager.Display();
			break;
		case 6:		//退出，跳出循环
			flag = 0;
			break;
		default:
			cout << "Please input Success Number !!" << endl;
			break;
		}

	}

	system("pause");

	return 0;
}


