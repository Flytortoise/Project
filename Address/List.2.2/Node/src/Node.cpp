#include "Node.h"

#include <string.h>

Node::Node() : next(NULL)
{
	memset(name,0,sizeof(name));
	memset(tel,0,sizeof(tel));
}


