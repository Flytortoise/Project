#ifndef FUNCTION_H_
#define FUNCTION_H_

#include "Node.h"

class Function;

class ABFactory
{
public :
	virtual Function *CreateFunction() = 0;
	virtual ~ABFactory();
};

class add : public ABFactory
{
public :
	Function *CreateFunction();
};

class change : public ABFactory
{
public :
	Function *CreateFunction();
};

class del : public ABFactory
{
public :
	Function *CreateFunction();
};

class destroy : public ABFactory
{
public :
	Function *CreateFunction();
};

class rev : public ABFactory
{
public :
	Function *CreateFunction();
};

class se : public ABFactory
{
public :
	Function *CreateFunction();
};

class so : public ABFactory
{
public :
	Function *CreateFunction();
};

class display : public ABFactory
{
public :
	Function *CreateFunction();
}; 



class Function
{
public :
	virtual int work(pNode head) = 0;
	virtual ~Function();
};

class Add : public Function
{
public :
	int work(pNode head);
};

class Change : public Function
{
public :
	int work(pNode head);
};

class Delete : public Function
{
public :
	int work(pNode head);
};

class Destroy : public Function
{
public :
	int work(pNode head);
};

class Reverse : public Function
{
public :
	int work(pNode head);
};

class Search : public Function
{
public :
	int work(pNode head);
};

class Sort : public Function
{
public :
	int work(pNode head);
};

class Display : public Function
{
public :
	int work(pNode head);
};

#endif
