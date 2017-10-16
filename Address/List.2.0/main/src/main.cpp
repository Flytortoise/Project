#include "main.h"
#include "Tool.h"
#include "Interface.h"
#include "Function.h"
#include "File.h"
#include "Node.h"

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
	    printf("Please input success Data !\n");
	    exit(-1);
	}
    pNode head = new Node;

    Function *f = new Function(head);
    Interface *inter = new Interface;

	File::FileOpen(head,argv[1]);
	int flag = 1;
	while(flag)
	{
	    inter->Func();
		scanf("%d",&flag);
		switch(flag)
		{
		    case 1:
				f->Add();
				break;
		    case 2:
				f->Delete();
				break;
		    case 3:
				f->Change();
				break;
		    case 4:
				f->Search();
				break;
		    case 5:
				f->Display();
				break;
		    case 6:
				f->Sort();
				break;
		    case 7:
				f->Reverse();
				break;
		    case 8:
				File::FileClose(head, argv[1]);
				head = f->Destroy();
				delete f;
				delete inter;
				flag = 0;
				printf("Exit Success !\n");
				break;
			default :
				flag = 1;
				printf("Please input success number !\n");
				break;
		}

	}


    return 0;
}
