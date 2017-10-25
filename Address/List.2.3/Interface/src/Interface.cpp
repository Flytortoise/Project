#include "Interface.h"
#include <stdio.h>

void Interface::Func()
{
    printf("+-------------------------------------------+\n");
	printf("|       Address                   List      |\n");
	printf("+-------------------------------------------+\n");
	printf("| 1. Add(add)            | 2. Delete(del)   |\n");
	printf("| 3. Change(change)      | 4. Search(se)    |\n");
	printf("| 5. Display(display)    | 6. Sort(so)      |\n");
	printf("| 7. Reverse(re)         | 8. Exit(destroy) |\n");
	printf("+-------------------------------------------+\n");
	printf("Please input str :");
}

Interface *Interface::inter_ = NULL;

Interface::	Interface()
{}

Interface *Interface::Get()
{
	if(inter_ == NULL)
	{
		inter_ = new Interface;
	}

	return inter_;
}

void Interface::Free()
{
	if(inter_ != NULL)
	{
		delete inter_;
		inter_ = NULL;
	}
}


