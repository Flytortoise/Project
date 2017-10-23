#ifndef INTERFACE_H_
#define INTERFACE_H_


class Interface
{
public :
	void Func();
	static Interface *Get();
	static void Free();
private :
	Interface();
	static Interface *inter_;
};

#endif
