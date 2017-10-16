#ifndef FILE_H_
#define FILE_H_

#include "Node.h"

class File
{
public :
	static void FileOpen(pNode head, char *filename);

	static void FileClose(pNode head, char *filename);
};

#endif 
