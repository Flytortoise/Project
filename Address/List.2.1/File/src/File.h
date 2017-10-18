#ifndef FILE_H_
#define FILE_H_

#include "Node.h"

namespace File
{
	void FileOpen(pNode head, char *filename);

	void FileClose(pNode head, char *filename);
}

#endif 
