#include "main.h"
#include "Tool.h"
#include "Interface.h"
#include "Function.h"
#include "File.h"
#include "Node.h"
#include "DynBase.h"

#include <string>

using std::string;

char buff[100];
int flag = 1;

int Select(string str)
{
	if((str != "add") && (str != "change") && (str != "del") && (str != "destroy") 
		&& (str != "rev") && (str != "se") && (str != "so") && (str != "display") )
	{
		printf("Please input success str !\n");
		return 0;
	}
	else
		return 1;
}


int main(int argc, char *argv[])
{
	if(argc != 2)
	{
	    printf("Please input success Data !\n");
	    exit(-1);
	}

	strcpy(buff, argv[1]);
	char buff2[1024];
    pNode head = new Node;

    //Factory *f = new Factory;
    Function *w = NULL;
    //Interface *inter = new Interface;

	File::FileOpen(head,argv[1]);
	
	while(flag)
	{

		//delete w;  写在这造成断错误，
		//			因为判断指令出错后，会再次delete
		//printf("demo44\n");
	    //inter->Func();
	    memset(buff2,0,sizeof(buff2));
	    Interface::Get()->Func();   

	    scanf("%s",buff2);
	    printf("\n--%s--\n",buff2);
	   
	    if(Select(buff2))
	    {
	    	//printf("demo11\n");
	    	w = reinterpret_cast<ABFactory *>(DynObjectFactory::CreateObject(buff2))
	            ->CreateFunction();
	           // printf("demo22\n");
	    	w->work(head);
	    	delete w;
	    	w = NULL;
	    	//printf("demo33\n");
	    }
	   
	}
	//delete w;
	delete head;
	Interface::Free();
	w = NULL;
	head = NULL;

    return 0;
}
