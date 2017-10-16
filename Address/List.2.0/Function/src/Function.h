#ifndef FUNCTION_H_
#define FUNCTION_H_

#include "Node.h"

class Function
{
public :
	Function(pNode p);
	int Add();
	int Delete();
	int Change();
	int Search();
	int Display();
	int Sort();
	int Reverse();
	pNode Destroy();

private :
	pNode head;

};


#endif
