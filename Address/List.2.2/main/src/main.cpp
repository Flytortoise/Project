#include "main.h"
#include "Tool.h"
#include "Interface.h"
#include "Function.h"
#include "File.h"
#include "Node.h"

char buff[100];

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
	    printf("Please input success Data !\n");
	    exit(-1);
	}

	strcpy(buff, argv[1]);

    pNode head = new Node;

    Factory *f = new Factory;
    Function *w = NULL;
    //Interface *inter = new Interface;

	File::FileOpen(head,argv[1]);
	int flag = 1;
	while(flag)
	{
	    //inter->Func();
	    Interface::Get()->Func();   
	    delete w;
		scanf("%d",&flag);
		w = f->CreateFunction(flag);
		if(w)
			w->work(head);

	}
	delete f;
	delete w;
	delete head;
	f = NULL;
	w = NULL;
	head = NULL;

    return 0;
}
